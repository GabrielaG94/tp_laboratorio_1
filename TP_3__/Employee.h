#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
//Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr);

Employee* employee_newParametros(int* id,char* nombre,int* horasTrabajadas,int* sueldo);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);
int sortByID(Employee* emp1, Employee* emp2);
int sortByName(Employee* emp1, Employee* emp2);
int sortByHoras(Employee* emp1, Employee* emp2);

int sortBySueldo(Employee* emp1, Employee* emp2);
#endif // employee_H_INCLUDED
