#include "listaEnlazada.h"

#define minimo(x, y) ((x) <= (y) ? (x) : (y))



void crearLista(tLista *p){
    *p = NULL;
}

int listaVacia(const tLista *p){
    return *p == NULL;
}

int listaLlena(const tLista *p, unsigned cantBytes){
    tNodo *aux = (tNodo *)malloc(sizeof(tNodo));
    void *info = malloc(cantBytes);
    free(info);
    free(aux);
    return info == NULL || aux == NULL;
}

void vaciarLista(tLista *p){
    while (*p){
        tNodo *aux = *p;
        *p = aux->sig;
        free(aux->info);
        free(aux);
    }    
}

int ponerAlComienzo(tLista *p, const void *d, unsigned cantBytes){
    tNodo *nue;
    if((nue = (tNodo *)malloc(sizeof(tNodo))) == NULL ||
    (nue->info = malloc(cantBytes)) == NULL){
        free(nue);
        return 0;
    }
    memcpy(nue->info, d, cantBytes);
    nue->tamInfo = cantBytes;
    nue->sig = *p;
    *p = nue;
    return 1;
}

int sacarPrimeroLista(tLista *p, void *d, unsigned cantBytes){
    tNodo *aux = *p;
    if(aux == NULL)
        return 0;
    *p = aux->sig;
    memcpy(d, aux->info, minimo(cantBytes, aux->tamInfo));
    free(aux->info);
    free(aux);
    return 1;
}

int verPrimeroLista(const tLista *p, void *d, unsigned cantBytes){
    if(*p == NULL)
        return 0;
    memcpy(d, (*p)->info, minimo(cantBytes, (*p)->tamInfo));
    return 1;
}

int ponerAlFinal(tLista *p, const void *d, unsigned cantBytes){
    tNodo *nue;
    while(*p)
        p = &(*p)->sig;
    if((nue = (tNodo *)malloc(sizeof(tNodo))) == NULL ||(nue->info = malloc(cantBytes)) == NULL){
        free(nue);
        return 0;
    }
    memcpy(nue->info, d, cantBytes);
    nue->tamInfo = cantBytes;
    nue->sig = NULL;
    *p = nue;
    return 1;
}

int sacarUltimoLista(tLista *p, void *d, unsigned cantBytes){
    while(*p && (*p)->sig)
        p = &(*p)->sig;
    if(*p == NULL)
        return 0;
    tNodo *aux = *p;
    memcpy(d, aux->info, minimo(cantBytes, aux->tamInfo));
    free(aux->info);
    free(aux);
    *p = NULL;
    return 1;
}

int verUltimoLista(const tLista *p, void *d, unsigned cantBytes){
    while(*p && (*p)->sig)
        p = &(*p)->sig;
    if(*p == NULL)
        return 0;
    memcpy(d, (*p)->info, minimo(cantBytes, (*p)->tamInfo));
    return 1;
}

int ponerEnOrden(tLista *p, const void *d, unsigned cantBytes, Cmp cmp){
    tNodo *nue;
    while(*p && cmp((*p)->info, d) < 0)
        p = &(*p)->sig;
    if((nue = (tNodo *)malloc(sizeof(tNodo))) == NULL || (nue->info = malloc(cantBytes)) == NULL){
        free(nue);
        return 0;
    }
    memcpy(nue->info, d, cantBytes);
    nue->tamInfo = cantBytes;
    nue->sig = *p;
    *p = nue;
    return 1;
}

void ordenarListaInsercion(tLista *p, Cmp cmp){
    tLista listaOrdenada;
    crearLista(&listaOrdenada);
    tNodo *aux;
    tNodo **q;
    while(*p){
        aux = *p;
        *p = aux->sig;
        aux->sig = NULL;
        q = &listaOrdenada;
        while(*q && cmp((*q)->info, aux->info) < 0)
            q = &(*q)->sig;
        aux->sig = *q;
        *q = aux;
    }
    *p = listaOrdenada;
}



//ordenar lista con quicksort
void ordenarListaQuickSort(tLista *p, Cmp cmp) {
    (*p) = quickSortRec(*p, obtenerUltimoNodo(*p), cmp);
}

tNodo* obtenerUltimoNodo(tNodo *raiz) {
    while (raiz != NULL && raiz->sig != NULL)
        raiz = raiz->sig;
    return raiz;
}

tNodo* quickSortRec(tNodo *inicio, tNodo *fin, Cmp cmp) {
    if (!inicio || inicio == fin)
        return inicio;

    tNodo *nuevoInicio = NULL, *nuevoFin = NULL;

    tNodo *pivote = particionar(inicio, fin, cmp, &nuevoInicio, &nuevoFin);

    if (nuevoInicio != pivote) {
        tNodo *tmp = nuevoInicio;
        while (tmp->sig != pivote)
            tmp = tmp->sig;
        tmp->sig = NULL;

        nuevoInicio = quickSortRec(nuevoInicio, tmp, cmp);

        tmp = obtenerUltimoNodo(nuevoInicio);
        tmp->sig = pivote;
    }

    pivote->sig = quickSortRec(pivote->sig, nuevoFin, cmp);

    return nuevoInicio;
}

tNodo* particionar(tNodo *inicio, tNodo *fin, Cmp cmp, tNodo **nuevoInicio, tNodo **nuevoFin) {
    tNodo *pivote = fin;
    tNodo *prev = NULL, *cur = inicio, *tail = pivote;

    while (cur != pivote) {
        if (cmp(cur->info, pivote->info) < 0) {
            if ((*nuevoInicio) == NULL)
                (*nuevoInicio) = cur;
            prev = cur;
            cur = cur->sig;
        } else {
            if (prev)
                prev->sig = cur->sig;
            tNodo *tmp = cur->sig;
            cur->sig = NULL;
            tail->sig = cur;
            tail = cur;
            cur = tmp;
        }
    }

    if ((*nuevoInicio) == NULL)
        (*nuevoInicio) = pivote;

    (*nuevoFin) = tail;

    return pivote;
}




void map(tLista *p, void accion(void*, void*), void *param){
    while(*p){
        accion((*p)->info, param);
        p = &(*p)->sig;
    }
}

void filter(tLista *p, int condicion(const void*, void*), void *param){
    tNodo *aux;
    while(*p){
        if(!condicion((*p)->info, param)){ //si condicion devuelve 0, elimino el nodo. Si devuelve 1, avanzo.
            aux = *p;
            *p = aux->sig;
            free(aux->info);
            free(aux);
        }else{
            p = &(*p)->sig;
        }
    }
}

void* reduce(tLista *p, void *res, void accion(const void*, void*, void*), void *param){
    while(*p){
        accion((*p)->info, res, param);
        p = &(*p)->sig;
    }
    return res;
}
