/*
 ============================================================================
 Name        : Tp2___.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>

#include"ArrayEmployees.h"
#define LEN 1000
#define TAM 15


int main(void) {
	setbuf(stdout,NULL);

    char salir='n';
    int flagAlta=0;


    int nextId=01;

    eEmployee nomina[LEN];
    initEmployeesializarEmployees(nomina,LEN);


    do
    {
        switch (menu())
        {
        case 1:

            addEmployee(nomina,LEN,&nextId);
            flagAlta=1;

             system("pause");


            break;
        case 2:

        if(flagAlta){
            modificarEmpleado(nomina,LEN);

        }
        else{
            printf("Para hacer modificaciones primero hay que dar de alta .\n");
        }



             system("pause");


            break;
        case 3:
           if(flagAlta ){
            removeEmployee(nomina,LEN,nextId);

           }
           else{
            printf("Para dar de baja un empleado primero tenes que dar de alta\n");
           }
             system("pause");

            break;
        case 4:
                if (flagAlta){
                    menuInformes(nomina,LEN);

                }
                else{
                        printf("Para ver informes tenes que dar de alta primero");
                    }


            system("pause");

            break;
        case 5:
            printf("Confirma salir?:");
            fflush(stdin);
            scanf("%c",&salir);
            printf("\n\n");

            break;

        }
    }
    while(salir=='n');
    return EXIT_SUCCESS;
}

