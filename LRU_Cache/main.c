#include <stdio.h>
#include "lib.h"
#include "cache.h"

int main()
{
    printline();
    printf("%d usuarios, tweets desde el %d al %d de %d en %d\n",100,0,49999,300,300);

    printf("\nCon cache de %5d elementos: ",167);
    procesar_con_cache("100usuarios_0min_49999max_300salto.bin", "tweets.bin",167);

    printf("\nCon cache de %5d elementos: ",150);
    procesar_con_cache("100usuarios_0min_49999max_300salto.bin", "tweets.bin",150);

    printf("\nCon cache de %5d elementos: ",100);
    procesar_con_cache("100usuarios_0min_49999max_300salto.bin", "tweets.bin",100);

    printf("\nCon cache de %5d elementos: ",50);
    procesar_con_cache("100usuarios_0min_49999max_300salto.bin", "tweets.bin",50);

    printf("\nCon cache de %5d elementos: ",10);
    procesar_con_cache("100usuarios_0min_49999max_300salto.bin", "tweets.bin",10);

    printf("\nSin cache:\t\t      ");
    procesar_sin_cache("100usuarios_0min_49999max_300salto.bin", "tweets.bin");
    printline();

    return 0;
}
