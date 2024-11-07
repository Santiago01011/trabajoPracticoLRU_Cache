#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAM_USUARIO 15      //tamaño máximo del nombre de cada usuario
#define TAM_FEED 20         //cantidad de tweets en cada feed

typedef struct
{
    char usuario[TAM_USUARIO]; // 14 caracteres + 1 para el /0
    int feed[TAM_FEED];        // vector de 20 enteros (cada uno es un id de tweet)
} Registro;

int random_con_salto(int min, int max, int salto);

int main()
{
    FILE *archivo;
    Registro* registros;
    char filename[64];
    unsigned cantusuarios, min, max, salto;
    srand(time(NULL)); // Inicializa la semilla para números aleatorios

    printf("Ingrese la cantidad de usuarios (cada uno tendra un feed de %d tweets):\n",TAM_FEED);
    scanf("%u",&cantusuarios);
    printf("\nIngrese el numero minimo de tweet:\n");
    scanf("%u",&min);
    printf("\nIngrese el numero maximo de tweet:\n");
    scanf("%u",&max);
    printf("\nIngrese el salto entre tweets:\n");
    scanf("%u",&salto);

    registros = malloc(cantusuarios*sizeof(Registro));
    if(!registros)
        return 2;

    // Generar registros
    for (int i = 0; i < (int)cantusuarios; i++)
    {
        // Asignar un nombre de usuario aleatorio
        snprintf(registros[i].usuario, TAM_USUARIO, "usuario%d", i + 1);

        // Llenar el vector de enteros con números aleatorios
        for (int j = 0; j < TAM_FEED; j++)
            registros[i].feed[j] = random_con_salto(min,max,salto);
    }

    // Abrir el archivo para escritura en modo binario
    sprintf(filename,"../archivos/%dusuarios_%dmin_%dmax_%dsalto.bin",cantusuarios, min, max, salto);
    archivo = fopen(filename, "wb");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo");
        return 1;
    }

    // Escribir los registros en el archivo
    fwrite(registros, sizeof(Registro), cantusuarios, archivo);
    fclose(archivo);

    printf("\nArchivo creado con %d registros.\n\n\n", cantusuarios);

    free(registros);
    system("pause");

    return 0;
}

int random_con_salto(int min, int max, int salto)
{

    int rango = (max - min) / salto + 1;
    int random = (rand() + rand() + rand() + rand() + rand() + rand()) % rango;

    return min + (random * salto);
}
