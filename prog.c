#include "sorted-list.h"
#include<stdio.h>

typedef struct Employee{
	char *name;
	int salary;
} Employee;

int compareEmployees(void * x,void* y){
	Employee* a= (Employee*)x;
	Employee* b= (Employee*)y;
	if(a->salary<b->salary)
		return -1;
	else if(a->salary>b->salary)
		return 1;
	else
		return 0;
	return 0;
}

void destroyEmployee(void* x){
	Employee* a=(Employee*)x;
	free(a);
}
int main()
{
	Employee *a=(Employee*)malloc(sizeof(Employee));
	a->name="Albert";
	a->salary=48000;

	Employee *b=(Employee*)malloc(sizeof(Employee));
	b->name="Bob";
	b->salary=47000;
	
	Employee *c=(Employee*)malloc(sizeof(Employee));
	c->name="Carter";
	c->salary=46000;
	
	Employee *d=(Employee*)malloc(sizeof(Employee));
	d->name="Dudley";
	d->salary=45000;

	Employee *e=(Employee*)malloc(sizeof(Employee));
	e->name="Elysia";
	e->salary=44000;


	SortedListPtr ptr=SLCreate(&compareEmployees, &destroyEmployee);
	SLInsert(ptr, (void *)b);
	SLInsert(ptr, (void *)a);
	SLInsert(ptr, (void *)c);
	
	SLInsert(ptr, (void *)d);
	//SLRemove(ptr, (void *)c);

	//need to start using iterator once it has been implemented
	Employee* firstEmp=(Employee*)(ptr->head->data);
  	printf(" Hello world! %s is the first employee in the sorted list. \n",firstEmp->name);

	SortedListIteratorPtr walker = SLCreateIterator(ptr);

	SortedListIteratorPtr walker2 = SLCreateIterator(ptr);


	printf("Testing Iterator: %s \n", ((Employee*)(SLGetItem(walker)))->name);

	//the walker will stay at the last element
	while(walker->current->next!=NULL){
		SLNextItem(walker);	
		printf("Testing Iterator NextItem: %s \n", ((Employee *)(SLGetItem(walker)))->name);
	}
  	//case 1: destroyed the list but an iterator still points to one of the elements.
  	SLDestroy(ptr);
  	printf("Iterator is pointing to: %s \n", ((Employee *)(SLGetItem(walker)))->name);
	printf("Iterator 2 is pointing to: %s\n",((Employee *)(SLGetItem(walker2)))->name );
	printf("Lets traverse through each iterator\n");
	if(SLNextItem(walker)==NULL)
		printf("Iterator 1 reaches null\n");
	if(SLNextItem(walker2)==NULL)
		printf("Iterator 2 reaches null\n");
	SLDestroyIterator(walker);
	SLDestroyIterator(walker2);


  	return 0;
}





