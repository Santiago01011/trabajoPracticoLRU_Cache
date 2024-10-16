#include <stdio.h>
#include "lib.h"
#include "funciones_para_genericos.h"

int main()
{
    int i;
    t_lru_cache cacheper;
    tPersona vecpersonas[] = {{44391303,"Naspleda"},
                              {44525943,"Zapata"},
                              {43407685,"Maudet"},
                              {44525943,"Sapata"}};

    crear_lrucache(&cacheper,10);
    for (i=0;i<(int)((sizeof(vecpersonas)/sizeof(tPersona)));i++)
        agregar_lrucache(&cacheper,&vecpersonas[i],sizeof(tPersona),cmpdni);
    map_cache(&cacheper,printPersona,NULL);

    return 0;
}
