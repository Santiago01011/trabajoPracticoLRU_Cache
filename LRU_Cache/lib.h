#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED

#include <stdlib.h>
#include <string.h>

typedef struct sNodo
{
    void* info;
    size_t tamInfo;
    struct sNodo* sig;
}tNodo;

typedef struct
{
    tNodo* pri;
    size_t ce_max;//cantidad de nodos maxima que podra guardar la cache
}t_lru_cache;

void crear_lrucache(t_lru_cache* pc, size_t ce);
int agregar_lrucache(t_lru_cache* pc, const void* dato, size_t tam,int cmp(const void*, const void*));
void map_cache(t_lru_cache* pc, void accion(void*,void*), void* param);

#endif // LIB_H_INCLUDED
