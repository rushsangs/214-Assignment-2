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
	b->salary=400;

	SortedListPtr ptr=SLCreate(&compareEmployees, &destroyEmployee);
	SLInsert(ptr, (void *)a);
	Employee* firstEmp=(Employee*)(ptr->head->data);
  	printf(" Hello world! %s is the first employee in the sorted list. \n",firstEmp->name);
  	return 0;
}



