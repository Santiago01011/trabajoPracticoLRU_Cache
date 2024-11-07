#include "lib.h"
#include "funciones_para_genericos.h"
#include "cache.h"
#include <time.h>
#include <stdio.h>
#include <string.h>

int procesar_sin_cache(char* fileUsuarios, char* fileTweets)
{
    clock_t start, end;
    double tiempo_total;
    int i;
    FILE* pfu, //puntero a file de usuarios
        * pft; //puntero a file de tweets
    tRegistro registro;
    tTweet tweet;
    char pathUsuarios[70] = "../archivos/",
         pathTweets[70] = "../archivos/";

    strcat(pathUsuarios,fileUsuarios);
    strcat(pathTweets,fileTweets);

    pfu = fopen(pathUsuarios,"rb");
    if(!pfu)
        return 1;
    pft = fopen(pathTweets,"rb");
    if(!pft)
    {
        fclose(pfu);
        return 2;
    }

    start = clock();

    fread(&registro,sizeof(tRegistro),1,pfu);
    while(!feof(pfu))
    {
        //printf("\n%s:\n",registro.usuario);
        for (i=0;i<TAM_FEED;i++)
        {
            fseek(pft,registro.feed[i]*sizeof(tTweet),SEEK_SET);
            fread(&tweet,sizeof(tTweet),1,pft);
            //printTweet(&tweet,NULL);
        }
        fread(&registro,sizeof(tRegistro),1,pfu);
        //system("pause");
    }
    end = clock();
    fclose(pfu);
    fclose(pft);
    tiempo_total = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("%f segundos", tiempo_total);

    return 0;//OK
}

int procesar_con_cache(char* fileUsuarios, char* fileTweets, unsigned tamCache)
{
    clock_t start, end;
    double tiempo_total;
    int i;
    FILE* pfu, //puntero a file de usuarios
        * pft; //puntero a file de tweets
    tRegistro registro;
    tTweet tweet;
    t_lru_cache cache;
    char pathUsuarios[70] = "../archivos/",
         pathTweets[70] = "../archivos/";

    strcat(pathUsuarios,fileUsuarios);
    strcat(pathTweets,fileTweets);

    pfu = fopen(pathUsuarios,"rb");
    if(!pfu)
        return 1;
    pft = fopen(pathTweets,"rb");
    if(!pft)
    {
        fclose(pfu);
        return 2;
    }

    crear_lrucache(&cache,tamCache);

    start = clock();

    fread(&registro,sizeof(tRegistro),1,pfu);
    while(!feof(pfu))
    {
        //printf("\n%s:\n",registro.usuario);
        for (i=0;i<TAM_FEED;i++)
        {
            tweet.id = registro.feed[i];
            if(!obtener_lrucache(&cache,&tweet,sizeof(tTweet),cmpidtw))
            {
                fseek(pft,registro.feed[i]*sizeof(tTweet),SEEK_SET);
                fread(&tweet,sizeof(tTweet),1,pft);
                agregar_lrucache(&cache,&tweet,sizeof(tTweet),cmpidtw);
            }
            //printTweet(&tweet,NULL);
        }
        fread(&registro,sizeof(tRegistro),1,pfu);
        //system("pause");
    }
    end = clock();
    //map_cache(&cache,printTweet,NULL);
    vaciar_lrucache(&cache);
    fclose(pfu);
    fclose(pft);
    tiempo_total = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("%f segundos", tiempo_total);

    return 0;
}

void test_cache()
{
    int i;
    t_lru_cache cacheper;
    tPersona persona,
             vecpersonas[] = {{44391303,"Naspleda"},
                              {44525943,"Sapata"},
                              {43407685,"Maudet"},
                              {44525943,"Zapata"}};

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
}

void printline()
{
    int i;

    printf("\n");
    for (i=0;i<70;i++)
        printf("-");
    printf("\n");
}
