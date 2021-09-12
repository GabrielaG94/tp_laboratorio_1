/*
 * gabriela.c
 *
 *  Created on: 12 sep. 2021
 *      Author: pc
 */


#include <stdio.h>
#include <stdlib.h>
#include "gabriela.h"

int suma(int a,int b)
{
    int resultado;
    resultado=a+b;
    return resultado;

}


int resta (int a, int b)
{
    int resultado =  (a - b);
    return resultado;
}

float division(int a,int b)
{
    float resultado;
    resultado = (float) a / (float) b;
    return resultado;

}


int multiplicacion(int a,int b)
{
    int resultado= a*b;
    return resultado;
}

int factorial(int a)
{
    int resultado =1;
    for(int i=1; i<=a; i++)
    {
        resultado=resultado*i;
    }
    return resultado;

}
