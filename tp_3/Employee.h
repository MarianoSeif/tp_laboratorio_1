#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "LinkedList.h"

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);

Employee* employee_newParametrosFormats(int id,char* nombreStr,int horasTrabajadasStr,int sueldoStr);
void employee_delete(void);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);


int employee_listOneEmployee(Employee* this, int header);

int employee_generateId(LinkedList* pArrayListEmployee, int len);

int employee_findEmployeeById(LinkedList* pArrayListEmployee, int id);

int employee_editEmployee(LinkedList* pArrayListEmployee, int index);

int employee_compareByName(void* employee1, void* employee2);
int employee_compareById(void* employee1, void* employee2);
int employee_compareByHorasTrabajadas(void* employee1, void* employee2);
int employee_compareBySueldo(void* employee1, void* employee2);

#endif // employee_H_INCLUDED
