#ifndef FUNCIONES_PARA_GENERICOS_H_INCLUDED
#define FUNCIONES_PARA_GENERICOS_H_INCLUDED

#include <stdio.h>
#define TAM_MAX_APE 30

typedef struct
{
    unsigned dni;
    char apellido[TAM_MAX_APE];
}tPersona;

//int cmpint(const void* a, const void* b);
//void printInt(void* elem, void* param);
int cmpdni(const void* a,const void* b);
void printPersona(void* pv, void* param);

#endif // FUNCIONES_PARA_GENERICOS_H_INCLUDED
