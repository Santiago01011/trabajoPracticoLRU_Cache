#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAM_USUARIO 15      //tamaño máximo del nombre de cada usuario
#define TAM_FEED 20         //cantidad de tweets en cada feed
#define NUM_REGISTROS 2000
#define MAX_TWEET 50000

///IMPORTANTE:
//se generará un archivo de NUM_REGISTROS usuarios cuyo feed contendrá TAM_FEED tweets que podrán ser desde el tweet 0 hasta el tweet (MAX_TWEET-1)

typedef struct {
    char usuario[TAM_USUARIO]; // 14 caracteres + 1 para el null terminator
    int feed[TAM_FEED];        // vector de 20 enteros
} Registro;

int main() {
    FILE *archivo;
    Registro registros[NUM_REGISTROS];
    char filename[64];
    srand(time(NULL)); // Inicializa la semilla para números aleatorios

    // Generar registros
    for (int i = 0; i < NUM_REGISTROS; i++) {
        // Asignar un nombre de usuario aleatorio
        snprintf(registros[i].usuario, TAM_USUARIO, "usuario%d", i + 1);

        // Llenar el vector de enteros con números aleatorios
        for (int j = 0; j < TAM_FEED; j++) {
            registros[i].feed[j] = (rand() + rand() + rand() + rand() + rand() + rand()) % MAX_TWEET; // Número aleatorio entre 0 y 49999
        }
    }

    // Abrir el archivo para escritura en modo binario
    sprintf(filename,"../archivos/%dusuarios_%drango.bin",NUM_REGISTROS, MAX_TWEET);
    archivo = fopen(filename, "wb");
    if (archivo == NULL) {
        perror("No se pudo abrir el archivo");
        return 1;
    }

    // Escribir los registros en el archivo
    fwrite(registros, sizeof(Registro), NUM_REGISTROS, archivo);
    fclose(archivo);

    printf("Archivo creado con %d registros.\n", NUM_REGISTROS);
    /*
    int i,num;
    for (i=0;i< NUM_REGISTROS;i++)
    {
        num = (rand() + rand() + rand() + rand() + rand() + rand()) % 50000;
        if(num<25000)
            printf("%5d ",num);
    }
    */
    return 0;
}
