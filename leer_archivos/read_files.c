#include <stdio.h>
#include <stdlib.h>
#define TAM_USUARIO 15
#define TAM_FEED 20
#define FILENAME "../archivos/100usuarios_0min_49999max_300salto.bin"

typedef struct {
    char usuario[TAM_USUARIO]; // 14 caracteres + 1 para el null terminator
    int feed[TAM_FEED];        // vector de 20 enteros
}tRegistro;

typedef struct
{
    unsigned id;
    char texto[141];
}tTweet;

void printTweet(tTweet* ptw);
void printUsuario(tRegistro* pr);

int main()
{
    tRegistro registro;
    tTweet tweet;

    FILE* pf = fopen("../archivos/tweets.bin","rb");
    if(!pf)
        puts("Error");

    fread(&tweet,sizeof(tTweet),1,pf);
    while(!feof(pf))
    {
        printTweet(&tweet);
        fread(&tweet,sizeof(tTweet),1,pf);
    }
    fclose(pf);

    printf("\n\n");

    FILE* pusuarios = fopen(FILENAME,"rb");
    if(!pusuarios)
        puts("Error");

    fread(&registro,sizeof(tRegistro),1,pusuarios);
    while(!feof(pusuarios))
    {
        printUsuario(&registro);
        fread(&registro,sizeof(tRegistro),1,pusuarios);
    }
    fclose(pusuarios);

    return 0;
}

void printTweet(tTweet* ptw)
{
    printf("%d: %s\n",ptw->id,ptw->texto);
}

void printUsuario(tRegistro* pr)
{
    int i;
    printf("%-10s\t",pr->usuario);
    for (i=0;i<TAM_FEED;i++)
    {
        printf("| %5d ",pr->feed[i]);
    }
    printf("\n");
}
