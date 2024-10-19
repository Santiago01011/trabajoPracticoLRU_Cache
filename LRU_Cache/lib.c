#include "lib.h"
#define MIN(x,y) ((x) < (y) ? (x) : (y))

void crear_lrucache(t_lru_cache* pc, size_t ce)//pc: puntero a la cache
{
    pc->pri = NULL;
    pc->ce_max = ce;
}

int agregar_lrucache(t_lru_cache* pc, const void* dato, size_t tam,int cmp(const void*, const void*))
{
    tNodo* nue,
         * elim;
    tNodo** pl; //puntero a puntero a nodo con el que se recorre la lista
    int rcmp;
    size_t numelem = 1;

    nue = malloc(sizeof(tNodo));
    if(!nue)
        return 0; //sin memoria
    nue->info = malloc(tam);
    if(!nue->info)
    {
        free(nue);
        return 0; //sin memoria
    }
    //inserto al principio
    memcpy(nue->info,dato,tam);
    nue->tamInfo = tam;
    nue->sig = pc->pri;
    pc->pri = nue;

    pl = &(nue->sig);
    if(!*pl)
        return 1;//el elemento agregado es el primero de la lista

    while((rcmp = cmp(dato,(*pl)->info)) && ((*pl)->sig))
    {
        pl = &(*pl)->sig;
        numelem++;
    }
    if(!rcmp || numelem == pc->ce_max)//si el elemento ya existia en la cache o la cache se desbordo
    {
        elim = *pl;
        *pl = elim->sig;
        free(elim->info);
        free(elim);
    }
    return 1;
}

int obtener_lrucache(t_lru_cache* pc, void* dato, size_t tam, int cmp(const void*, const void*))
{
    tNodo* bus;
    tNodo** pl = &(pc->pri);

    while((*pl) && (cmp(dato,(*pl)->info)))
        pl = &(*pl)->sig;

    if(!*pl)
        return 0; //no encontrado

    bus = *pl;
    *pl = bus->sig;
    bus->sig = pc->pri;
    pc->pri = bus;
    memcpy(dato,bus->info,MIN(tam,bus->tamInfo));

    return 1;
}

int borrar_lrucache(t_lru_cache* pc, void* dato, size_t tam, int cmp(const void*, const void*))
{
    tNodo* elim;
    tNodo** pl = &(pc->pri);

    while((*pl) && (cmp(dato,(*pl)->info)))
        pl = &(*pl)->sig;

    if(!*pl)
        return 0; //no encontrado

    elim = *pl;
    *pl = elim->sig;
    memcpy(dato,elim->info,MIN(tam,elim->tamInfo));
    free(elim->info);
    free(elim);

    return 1;
}

void vaciar_lrucache(t_lru_cache* pc)
{
    tNodo* elim;

    while(pc->pri)
    {
        elim = pc->pri;
        pc->pri = elim->sig;
        free(elim->info);
        free(elim);
    }
}

void map_cache(t_lru_cache* pc, void accion(void*,void*), void* param)
{
//recorrer la lista y hacer algo con cada elemento
    tNodo** pl = &(pc->pri);
    while(*pl)
    {
        accion((*pl)->info,param);
        pl = &(*pl)->sig;
    }
}
