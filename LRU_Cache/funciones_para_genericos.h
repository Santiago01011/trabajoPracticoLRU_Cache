#ifndef FUNCIONES_PARA_GENERICOS_H_INCLUDED
#define FUNCIONES_PARA_GENERICOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_MAX_APE 30

typedef struct
{
    unsigned dni;
    char apellido[TAM_MAX_APE];
}tPersona;

typedef struct{
    char usuario [15];
    int feed[20];
}tUsuario;

typedef struct{
    unsigned id;
    char texto[140];
}tTweet;


typedef void (*print_callback)(void* elem);
int mostrarArchivoGen(const char* nombreArch, size_t tamElem, print_callback printStruct);
//int cmpint(const void* a, const void* b);
//void printInt(void* elem, void* param);
int cmpdni(const void* a,const void* b);
void printPersona(void* pv, void* param);
void printUsuario(void* pv);
void printTweet(void* pv);

#endif // FUNCIONES_PARA_GENERICOS_H_INCLUDED
