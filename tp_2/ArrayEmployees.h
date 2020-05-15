/*
 * ArrayEmployees.h
 *
 *  Created on: 24 abr. 2020
 *      Author: mfs
 */



typedef struct{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
} Employee;

int harcodearEmployees(Employee* list, int len);

int initEmployees(Employee* list, int len);

int printEmployees(Employee* list, int length);

int printOneEmployee(Employee* list, int index, int header);

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);

int findFirstFreeIndex(Employee* list, int len);

int newEmployee(Employee* list, int len);

int findEmployeeById(Employee* list, int len,int id);

int removeEmployee(Employee* list, int len, int id);

int sortEmployees(Employee* list, int len, int order);

int updateEmployee(Employee* empleados, int len);

int generateId(Employee* list, int len);

int calculateData(Employee* empleados, int len);

int swapEmployees(Employee* list, int len, int i, int j);
