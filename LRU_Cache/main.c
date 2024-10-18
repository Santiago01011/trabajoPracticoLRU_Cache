#include <stdio.h>
#include "lib.h"
#include "funciones_para_genericos.h"


//funcion que transforma un archivo .csv a .bin con estructura tTweet
void transformarCsvABin(){
    FILE* lp = fopen("lote_pruebas.csv","rt");
    FILE* bp = fopen("lote_pruebas.bin","wb");
    tTweet tweet;
    char linea[200];
    if (lp == NULL || bp == NULL) {
        printf("Error al abrir los archivos.\n");
        fclose(lp);
        fclose(bp);
        return;
    }

    while (fgets(linea, sizeof(linea), lp)) {
        // Parsear la línea del CSV
        sscanf(linea, "%d;%140[^\n]", &tweet.id, &tweet.texto);
        // Escribir la estructura en el archivo binario
        fwrite(&tweet, sizeof(tTweet), 1, bp);
    }

    fclose(lp);
    fclose(bp);



}


int main()
{

    transformarCsvABin();
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
