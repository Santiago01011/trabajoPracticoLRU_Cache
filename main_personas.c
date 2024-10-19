#include <stdio.h>
#include "lib.h"
#include "funciones_para_genericos.h"

int main()
{
    int i;
    t_lru_cache cacheper;
    tPersona persona,
             vecpersonas[] = {{44391303,"Naspleda"},
                              {44525943,"Zapata"},
                              {43407685,"Maudet"},
                              {44525943,"Sapata"}};

    crear_lrucache(&cacheper,10);
    for (i=0;i<(int)((sizeof(vecpersonas)/sizeof(tPersona)));i++)
        agregar_lrucache(&cacheper,&vecpersonas[i],sizeof(tPersona),cmpdni);
    map_cache(&cacheper,printPersona,NULL);

    persona.dni = 44391303;
    printf("\n\nObtengo la persona con DNI %d\n",persona.dni);
    if(obtener_lrucache(&cacheper,&persona,sizeof(tPersona),cmpdni))
        printPersona(&persona,NULL);
    else
        puts("Persona no encontrada.");
    printf("\nAhora la cache queda ordenada asi:\n");
    map_cache(&cacheper,printPersona,NULL);

    persona.dni = 44525943;
    printf("\n\nElimino la persona con DNI %d\n",persona.dni);
    if(borrar_lrucache(&cacheper,&persona,sizeof(tPersona),cmpdni))
        printPersona(&persona,NULL);
    else
        puts("Persona no encontrada.");
    printf("\nAhora la cache queda asi:\n");
    map_cache(&cacheper,printPersona,NULL);

    vaciar_lrucache(&cacheper);
    map_cache(&cacheper,printPersona,NULL);//no deberia mostrar nada

    return 0;
}
