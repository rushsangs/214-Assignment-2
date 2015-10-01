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
	
	Employee *c=(Employee*)malloc(sizeof(Employee));
	c->name="Sasha";
	c->salary=4000;

	Employee *b=(Employee*)malloc(sizeof(Employee));
	b->name="Bob";
	b->salary=100;

	Employee *g=(Employee*)malloc(sizeof(Employee));
	g->name="Ulysses";
	g->salary=3000;

	SortedListPtr ptr=SLCreate(&compareEmployees, &destroyEmployee);
	SLInsert(ptr, (void *)b);
	SLInsert(ptr, (void *)a);
	SLInsert(ptr, (void *)c);
	SLInsert(ptr, (void *)g);
	SLRemove(ptr, (void *)c);

	//need to start using iterator once it has been implemented
	Employee* firstEmp=(Employee*)(ptr->head->data);
  	printf(" Hello world! %s is the first employee in the sorted list. \n",firstEmp->name);

	SortedListIteratorPtr walker = SLCreateIterator(ptr);
	printf("Testing Iterator: %s \n", ((Employee*)(SLGetItem(walker)))->name);
	while(SLNextItem(walker)!=NULL)
		printf("Testing Iterator NextItem: %s \n", ((Employee *)(SLGetItem(walker)))->name);
	
  	SLDestroy(ptr);
  	return 0;
}





