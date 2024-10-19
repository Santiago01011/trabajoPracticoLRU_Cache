#include <stdio.h>
#include <time.h>
#include "lib.h"
#include "funciones_para_genericos.h"

#define FILENAME_USUARIOS "4000usuarios_200rango.bin"
#define FILENAME_TWEETS "tweets.bin"
#define TAM_CACHE 150

int main()
{

    clock_t start, end;
    double tiempo_total;
    int i;
    FILE* pfu, //puntero a file de usuarios
        * pft; //puntero a file de tweets
    tRegistro registro;
    tTweet tweet;

    pfu = fopen(FILENAME_USUARIOS,"rb");
    if(!pfu)
        return 1;
    pft = fopen(FILENAME_TWEETS,"rb");
    if(!pft)
    {
        fclose(pfu);
        fclose(pft);
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
    printf("Tiempo de procesamiento: %f segundos\n", tiempo_total);

/*
    clock_t start, end;
    double tiempo_total;
    int i;
    FILE* pfu, //puntero a file de usuarios
        * pft; //puntero a file de tweets
    tRegistro registro;
    tTweet tweet;
    t_lru_cache cache;

    pfu = fopen(FILENAME_USUARIOS,"rb");
    if(!pfu)
        return 1;
    pft = fopen(FILENAME_TWEETS,"rb");
    if(!pft)
    {
        fclose(pfu);
        fclose(pft);
        return 2;
    }

    crear_lrucache(&cache,TAM_CACHE);

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
    printf("Tiempo de procesamiento: %f segundos\n", tiempo_total);
*/
    return 0;
}
