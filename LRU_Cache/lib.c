#include "lib.h"

void crear_lrucache(t_lru_cache* pc, size_t ce)//pc: puntero a la cache
{
    pc->pri = NULL;
    pc->ce_max = ce;
}


/*
para agregar primero habia pensado en buscar si el elemento existe en la cache y moverlo al principio
cambiando solo los punteros.
de esa forma me evitaba el tener que agregar un elemento que ya existia y borrar su version vieja

termine descartando eso porque segun el enunciado "Si el dato ya existía (misma clave), es
reemplazado y queda al principio del set de datos", lo que me dio a entender que, por ejemplo, para la
estructura de persona que declare en el .h se podria dar la situacion de que en la cache exista alguien
con DNI 123 y apellido Lopez, y luego se quiera agregar a alguien con DNI 123 (el mismo) pero apellido Perez,
por lo que mover los punteros no me seria suficiente porque, si bien la clave es la misma, el resto cambia
*/
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
