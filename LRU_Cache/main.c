#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main()
{
    printline();

    ///ARCHIVO 1
    printf("%d usuarios, tweets desde el %d al %d de %d en %d\n",100000,0,49999,1000,1000);

    printf("\nCon cache de %5d elementos: ",50);
    procesar_con_cache("100000usuarios_0min_49999max_1000salto.bin", "tweets.bin",50);

    printf("\nCon cache de %5d elementos: ",40);
    procesar_con_cache("100000usuarios_0min_49999max_1000salto.bin", "tweets.bin",40);

    printf("\nCon cache de %5d elementos: ",30);
    procesar_con_cache("100000usuarios_0min_49999max_1000salto.bin", "tweets.bin",30);

    printf("\nCon cache de %5d elementos: ",10);
    procesar_con_cache("100000usuarios_0min_49999max_1000salto.bin", "tweets.bin",10);

    printf("\nCon cache de %5d elementos: ",1);
    procesar_con_cache("100000usuarios_0min_49999max_1000salto.bin", "tweets.bin",1);

    printf("\nSin cache:\t\t      ");
    procesar_sin_cache("100000usuarios_0min_49999max_1000salto.bin", "tweets.bin");

    printline();

    ///ARCHIVO 2
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

    ///ARCHIVO 3
    printf("%d usuarios, tweets desde el %d al %d de %d en %d\n",200000,0,49999,250,250);

    printf("\nCon cache de %5d elementos: ",200);
    procesar_con_cache("200000usuarios_0min_49999max_250salto.bin", "tweets.bin",200);

    printf("\nCon cache de %5d elementos: ",150);
    procesar_con_cache("200000usuarios_0min_49999max_250salto.bin", "tweets.bin",150);

    printf("\nCon cache de %5d elementos: ",100);
    procesar_con_cache("200000usuarios_0min_49999max_250salto.bin", "tweets.bin",100);

    printf("\nCon cache de %5d elementos: ",50);
    procesar_con_cache("200000usuarios_0min_49999max_250salto.bin", "tweets.bin",50);

    printf("\nCon cache de %5d elementos: ",10);
    procesar_con_cache("200000usuarios_0min_49999max_250salto.bin", "tweets.bin",10);

    printf("\nSin cache:\t\t      ");
    procesar_sin_cache("200000usuarios_0min_49999max_250salto.bin", "tweets.bin");

    printline();

    ///ARCHIVO 4
    printf("%d usuarios, tweets desde el %d al %d de %d en %d\n",200,0,49999,1,1);

    printf("\nCon cache de %5d elementos: ",4000);
    procesar_con_cache("200usuarios_0min_49999max_1salto.bin", "tweets.bin",4000);

    printf("\nCon cache de %5d elementos: ",2000);
    procesar_con_cache("200usuarios_0min_49999max_1salto.bin", "tweets.bin",2000);

    printf("\nCon cache de %5d elementos: ",500);
    procesar_con_cache("200usuarios_0min_49999max_1salto.bin", "tweets.bin",500);

    printf("\nCon cache de %5d elementos: ",100);
    procesar_con_cache("200usuarios_0min_49999max_1salto.bin", "tweets.bin",100);

    printf("\nCon cache de %5d elementos: ",10);
    procesar_con_cache("200usuarios_0min_49999max_1salto.bin", "tweets.bin",10);

    printf("\nSin cache:\t\t      ");
    procesar_sin_cache("200usuarios_0min_49999max_1salto.bin", "tweets.bin");

    printline();

    ///ARCHIVO 5
    printf("%d usuarios, tweets desde el %d al %d de %d en %d\n",10000,0,49999,1,1);

    printf("\nCon cache de %5d elementos: ",50000);
    procesar_con_cache("10000usuarios_0min_49999max_1salto.bin", "tweets.bin",50000);

    printf("\nCon cache de %5d elementos: ",25000);
    procesar_con_cache("10000usuarios_0min_49999max_1salto.bin", "tweets.bin",25000);

    printf("\nCon cache de %5d elementos: ",5000);
    procesar_con_cache("10000usuarios_0min_49999max_1salto.bin", "tweets.bin",5000);

    printf("\nCon cache de %5d elementos: ",100);
    procesar_con_cache("10000usuarios_0min_49999max_1salto.bin", "tweets.bin",100);

    printf("\nCon cache de %5d elementos: ",10);
    procesar_con_cache("10000usuarios_0min_49999max_1salto.bin", "tweets.bin",10);

    printf("\nSin cache:\t\t      ");
    procesar_sin_cache("10000usuarios_0min_49999max_1salto.bin", "tweets.bin");

    printline();

    system("pause");

    return 0;
}
