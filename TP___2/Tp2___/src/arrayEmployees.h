/*
 * arrayEmployees.h
 *
 *  Created on: 16 oct. 2021
 *      Author: pc
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_


typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} eEmployee;

int menu();
int menuInformes(eEmployee list [], int len);
int hardcodearEmployees(eEmployee list[],int len,int cant,int* pId);
int addEmployee(eEmployee nuevoEmployee[],int len,int* pId );
int initEmployeesializarEmployees(eEmployee list[],int len);
int findFree(eEmployee list[], int len);
int findEmployeeById (eEmployee list[], int len,int pId);
int removeEmployee(eEmployee list[], int len,int pId);
int sortEmployees(eEmployee list[], int len,int order);
int printEmployee(eEmployee anEmployee, int len);
int printEmployees(eEmployee list[], int len);
int modificarEmpleado(eEmployee list [], int len);
int sonLetras(char cadena[]);
int validarRangoEntero(int numero,int limInf,int limSup);
#endif /* ARRAYEMPLOYEES_H_ */
