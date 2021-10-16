/*
 * arrayEmployees.c
 *
 *  Created on: 16 oct. 2021
 *      Author: pc
 */

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>

#include"ArrayEmployees.h"


/** \brief menu de opciones.
 *
 * \return int opcion elegida por el usuario.
 *
 */
int menu()
{
    int opcion;

    system("cls");
    printf("*** ABM Empleados ***\n\n ");
    printf(" 1.Alta Empleado\n ");
    printf(" 2.Modificar Empleado\n ");
    printf(" 3.Baja Empleado\n ");
    printf(" 4.Informes Empleados\n ");
    printf(" 5.Salir\n ");

    printf("\n Ingrese opcion:");

    scanf("%d",&opcion);

    return opcion;
}

/** \brief
* da de alta a un empleado en la primera posicion que este libre
 * \param list employee* array de empleados
 * \param len int tamaño de array
 * \param int* pId puntero a entero para el proximo id.
* \return 1 si esta todo bien y 0 si hay algun error al dar de alta.
*/
int addEmployee(eEmployee list[],int len,int* pId )
{


    int todoOk=0;
    int indice;
    int validar;
    eEmployee nuevoEmployee;

    system("cls");
    printf("   *** Alta Empleado  ***\n");
    printf("Legajo %d\n",*pId);

    if(list!=NULL && len>0 && pId !=NULL)
    {
        indice=findFree(list,len);
        if(indice==-1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {

            printf("Ingrese Nombre:\n");
            fflush(stdin);
           gets(nuevoEmployee.name);

            validar=sonLetras(nuevoEmployee.name);
            while(validar == -1)
            {
                printf("Nombre invalido.Reingrese Nombre:\n");
                fflush(stdin);
                gets(nuevoEmployee.name);
                validar=sonLetras(nuevoEmployee.name);
            }

            printf("Ingrese Apellido:\n");
            fflush(stdin);
            gets(nuevoEmployee.lastName);
            validar=sonLetras(nuevoEmployee.lastName);
            while(validar == -1)
            {
                printf("Apellido invalido.Reingrese Apellido:\n");
                fflush(stdin);
                gets(nuevoEmployee.lastName);
                validar=sonLetras(nuevoEmployee.lastName);
            }


            printf("Ingrese sueldo:\n");
            scanf("%f",&nuevoEmployee.salary);



            printf("Ingrese Sector 1,2,3,4,5:\n");
            scanf("%d",&nuevoEmployee.sector);
            while(!validarRangoEntero(nuevoEmployee.sector,1,5))
            {

                printf("Sector invalido.Reingrese Sector 1,2,3,4,5:\n");
                scanf("%d",&nuevoEmployee.sector);
            }



            nuevoEmployee.id=*pId;
            nuevoEmployee.isEmpty=0;
            *pId= *pId +1;

            list[indice]=nuevoEmployee;
            todoOk=1;
        }
    }

    return todoOk;
}

/** \brief indica que todas las posiciones del array están vacías,
        esta función ponea todos los (isEmpty) en VERDADERO
 *
 * \param list[] eEmployee
 * \param len int
 * \return int 1 si esta todo bien y 0 si hay algun error .
 *
 */
int initEmployeesializarEmployees(eEmployee list[],int len)
{

    int todoOk=0;

    if(list != NULL && len >0)
    {
        for(int i=0; i<len; i++)
        {
            list[i].isEmpty=1;
        }
        todoOk=1;

    }
    return todoOk;
}

/** \brief busca una posicion libre en el array
 *
 * \param list[] eEmployee
 * \param len int
 * \return
 *
 */
int findFree(eEmployee list[], int len)
{


    int indice=-1;

    if(list != NULL && len >0)
    {
        for(int i=0; i<len; i++)
        {
            if (list[i].isEmpty)
            {
                indice=i;
                break;
            }
        }

    }
    return indice;
}
/** \brief busca un empleado por id y regresa el indice de la posicion del array
 *
 * \param list[] eEmployee
 * \param len int
 * \return retorna la posicion del array o -1 si hay algun error.
 *
 */
int findEmployeeById (eEmployee list[], int len,int pId)
{
    int indice=-1;

    for(int i=0; i<len; i++)
    {
        if(list[i].id==pId && !list[i].isEmpty)
        {
            indice=i;
            break;
        }
    }
    return indice;

}

/** \brief da de baja a un empleado por su id.
 *
 * \param list[] eEmployee
 * \param len int
 * \param pId int
 * \return int 1 si se dio de baja o 0 si hay algun error.
 *
 */
int removeEmployee(eEmployee list[], int len, int pId)
{

    int todoOk=0;
    int indice;
    char confirm;

    system("cls");
    printf("    *** Baja de Empleado  ***\n");

    printEmployees(list,len);
    printf("Ingrese Id: ");
    scanf("%d",&pId);

    indice=findEmployeeById(list,len,pId);
    if(indice== -1)
    {
        printf("No hay ningun empleado registrado con ese Id %d\n",pId);
    }
    else
    {
        printEmployee(list[indice],len);
        printf("Confirma Baja?: ");
        fflush(stdin);
        scanf("%c",&confirm);
        if(confirm=='s')
        {
            list[indice].isEmpty=1;
            printf("Baja exitosa !!!\n");
            todoOk=1;
        }
        else
        {
            printf("Baja cancelada por el usuario\n");
        }
    }
    return todoOk;

}

/** \brief ordena por apellido la lista de empleados
 *
 * \param list[] eEmployee
 * \param len int
 * \param order int
 * \return int 1 si se puede o 0 si hay algun error.
 *
 */
int sortEmployees(eEmployee list[], int len,int order)
{


    int todoOk = 0;
    eEmployee aux;

    if(list != NULL && len > 0)
    {
        for(int i = 0; i < len - 1; i++)
        {
            for(int j = i + 1; j < len; j++)
            {
                if(order == 1)
                {
                    if(strcmp(list[i].lastName, list[j].lastName) > 0 || (strcmp(list[i].lastName, list[j].lastName) == 0 && list[i].sector > list[j].sector))
                    {
                        aux = list[i];
                        list[i] = list[j];
                        list[j] = aux;
                    }
                }
                else
                {
                    if(strcmp(list[i].lastName, list[j].lastName) < 0 || (strcmp(list[i].lastName, list[j].lastName) == 0 && list[i].sector < list[j].sector))
                    {
                        aux = list[i];
                        list[i] = list[j];
                        list[j] = aux;
                    }
                }
            }
        }
        todoOk =1;
    }

    return todoOk;

}







/** \brief muestra un empleado
 *
 * \param anEmployee eEmployee
 * \param len

 *
 */
int printEmployee(eEmployee anEmployee, int len)
{
    printf(" %d     %-10s    %-10s   %9.2f    %d   \n"
           ,anEmployee.id
           ,anEmployee.name
           ,anEmployee.lastName
           ,anEmployee.salary
           ,anEmployee.sector);


    return 0;
}
/** \brief  muestra la lista completa de empleados
 *
 * \param list[] eEmployee
 * \param len int
 * \return int
 *
 */
int printEmployees(eEmployee list[], int len)
{

    int flag=1;
    printf("    ***   Lista de Empleados  *** \n\n ");
    printf(" Id       Nombre      Apellido       Sueldo      Sector\n\n");
    for(int i=0; i<len; i++)
    {
        if(!list[i].isEmpty)
        {
            printEmployee(list[i],len);
            flag=0;
        }

    }
    if(flag)
    {
        printf("No hay empleados que mostrar");
    }
    printf("\n\n");

    return 0;
}

/** \brief se puede modificar los datos de un empleado
 *
 * \param [] eEmployee list
 * \param len int
 * \return int
 *
 */
int modificarEmpleado(eEmployee list [], int len)
{

    int todoOk=0;
    int id;
    int opcion;
    int indice;
    system("cls");
    printf("*** Modificar Empleado ***\n\n");
    printEmployees(list,len);
    printf("\nIngrese id: ");
    scanf("%d", &id);


    indice = findEmployeeById(list,len,id);

    if( indice == -1)
    {
        printf("No existe ningun empleado con ese legajo \n\n");

    }
    else
    {
        system("cls");
        printf(" Id          Nombre         Apellido        Salario     Sector \n\n");
        printEmployee(list[indice],len);
        printf("\n\n");
        printf("1. Modificar Nombre\n");
        printf("2. Modificar Apellido\n");
        printf("3. Modificar Salario\n");
        printf("4. Modificar Sector\n");
        printf("5. Salir\n\n");
        printf("Ingrese opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            printf("Ingrese Nuevo Nombre: ");
            fflush(stdin);
            gets(list[indice].name);
            break;

        case 2:
            printf("Ingrese Nuevo Apellido: ");
            fflush(stdin);
            gets(list[indice].lastName);
            break;

        case 3:
            printf("Ingrese Nuevo Salario: ");
            fflush(stdin);
            scanf("%f",&list[indice].salary);
            break;

        case 4:
            printf("Ingrese Nuevo Sector: ");
            fflush(stdin);
            scanf("%d",&list[indice].sector);

            break;

        case 5:
            printf("Se cancelo la modificacion de datos.\n\n ");
            system("pause");
            break;


        }
        todoOk = 1;
        system("cls");

    }
    system("pause");
    return todoOk;
}
int salarioPromedio(eEmployee list[], int len)
{
    int todoOk = -1;

    float promedio = 0;
    float acuSal = 0;
    int contEmpleados = 0;
    int contSuperanPromedio =0;


    if(list != NULL && len > 0)
    {
        for(int i= 0; i < len; i ++)
        {
            if(list[i].isEmpty == 0)
            {
                acuSal = acuSal + list[i].salary;
                contEmpleados ++;
            }

        }
        promedio = acuSal / contEmpleados;

        for(int i= 0; i < len; i ++)
        {
            if(list[i].salary > promedio && list[i].isEmpty == 0)
            {
                contSuperanPromedio ++;
            }
        }

        printf("El total de salarios es de %7.2f $\n\n", acuSal);
        printf("El salario promedio es de %7.2f $\n\n", promedio);
        if(contSuperanPromedio == 0)
        {
            printf("No hay empleados que superen el salario promedio\n\n");
        }
        else
        {
            printf("%d Empleados superan el salario promedio\n\n", contSuperanPromedio);

        }


        todoOk = 0;
    }

    return todoOk;
}
/** \brief menu de informes
 *
 * \param [] eEmployee list
 * \param len int
 * \return int
 *
 */
int menuInformes(eEmployee list [], int len)
{

    int todoOk=0;

    int opcion;

    system("cls");
    printf(" *** Informes ***\n\n");


    printf("1. Ordenamiento \n");
    printf("2. Salarios\n");

    printf("5. Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    switch(opcion)
    {
    case 1:
        system("cls");
        printf("***  Empleado ordenados por Apellidos y sector *** \n\n");
        sortEmployees(list,len,1);
        printEmployees(list,len);

        break;

    case 2:
        system("cls");
        salarioPromedio(list,len);
        break;

    case 3:
        system("cls");
        printf("Se cancelo la modificacion de datos ");
        break;


    }
    todoOk = 1;


    system("pause");
    return todoOk;

}

/** \brief valida si son letras
 *
 * \param cadena[] char
 * \return int devuelve 1 si son letras, devuelve -1 si son numeros
 *
 */
int sonLetras(char cadena[])
{
    int todoOk= -1;
    int i;
    int longitud = strlen(cadena);

      for(i= 0; i < longitud; i++)
      {
          if((cadena[i] > 65 && cadena[i] < 90) || (cadena[i] > 97 && cadena[i] < 122))
          {

              todoOk= 1;
          }
      }



    return todoOk;
}

/** \brief valida el rango de 2 numeros
 *
 * \param numero int
 * \param limInf int numero inferior
 * \param limSup int numero superior
 * \return int
 *
 */
int validarRangoEntero(int numero,int limInf,int limSup){
int esValido=0;
if(numero >= limInf && numero <= limSup){
    esValido=1;
}
return esValido;
}


