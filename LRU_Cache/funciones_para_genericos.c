#include "funciones_para_genericos.h"


/*
int cmpint(const void* a, const void* b)
{
    int* pa = (int*)a;
    int* pb = (int*)b;

    return (*pa)-(*pb);
}

void printInt(void* elem, void* param)
{
    int* pnum = (int*)elem;
    printf("%d  ",*pnum);
}
*/
int cmpdni(const void* a,const void* b)
{
    tPersona* pa=(tPersona*)a;
    tPersona* pb=(tPersona*)b;

    return (pa->dni)-(pb->dni);
}

void printPersona(void* pv, void* param)
{
    tPersona* pp=(tPersona*)pv;
    printf("%d: %s\n",pp->dni,pp->apellido);
}
