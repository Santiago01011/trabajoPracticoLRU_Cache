#include "funciones_para_genericos.h"
#include <stdio.h>

int cmpdni(const void* a,const void* b)
{
    tPersona* pa=(tPersona*)a;
    tPersona* pb=(tPersona*)b;

    return (pa->dni)-(pb->dni);
}

int cmpidtw(const void* a,const void* b)
{
    tTweet* pa=(tTweet*)a;
    tTweet* pb=(tTweet*)b;

    return (pa->id)-(pb->id);
}

void printPersona(void* pv, void* param)
{
    tPersona* pp = (tPersona*)pv;
    (void)param;//para sacar el warning
    printf("%d: %s\n",pp->dni,pp->apellido);
}

void printTweet(void* pinfo, void* param)
{
    tTweet* ptw = (tTweet*)pinfo;
    (void)param;
    printf("%5d: %s\n",ptw->id,ptw->texto);
}

void printUsuario(void* pinfo, void* param)
{
    int i;
    (void)param;
    tRegistro* pr = (tRegistro*)pinfo;
    printf("%-10s\t",pr->usuario);
    for (i=0;i<TAM_FEED;i++)
    {
        printf("| %5d ",pr->feed[i]);
    }
    printf("\n");
}
