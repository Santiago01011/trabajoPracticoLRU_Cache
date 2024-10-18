#include "funciones_para_genericos.h"

int cmpdni(const void* a,const void* b)
{
    tPersona* pa=(tPersona*)a;
    tPersona* pb=(tPersona*)b;

    return (pa->dni)-(pb->dni);
}

void printPersona(void* pv, void* param)
{
    tPersona* pp=(tPersona*)pv;
    printf("%d: %s\n",pp->dni,pp->apellido);
}

void printTweet(void* pv)
{
    tTweet* pt=(tTweet*)pv;
    printf("%d: %s\n",pt->id,pt->texto);
}

void printUsuario(void* pv)
{
    tUsuario* pu=(tUsuario*)pv;
    printf("%s:\n",pu->usuario);
    for(int i=0;i<20;i++)
        printf("|%d|\n",pu->feed[i]);
    putchar('\n');
}




/**
 * @brief Muestra un archivo binario de forma generica.
 * 
 * Muestra el contenido de un archivo utilizando la función de impresión recibida por printStruct.
 * 
 * @param nombreArch Puntero a la ruta del archivo que se va a mostrar.
 * @param tamElem Tamaño de los elementos del archivo.
 * @param printStruct puntero a función de impresión.
 * @return int Devuelve 1 si se pudo abrir el archivo, 0 en caso contrario.
 */
int mostrarArchivoGen(const char* nombreArch, size_t tamElem, print_callback printStruct){
    FILE *arch;
    void *elem;
    if((arch = fopen(nombreArch, "rb")) == NULL)
        return 0;
    elem = malloc(tamElem);
    if(elem == NULL){
        fclose(arch);
        return 0;
    }
    printf("-----------------Archivo: %s-----------------\n", nombreArch);
    while(fread(elem, tamElem, 1, arch) == 1){
        printStruct(elem);
    }
    puts("---------------------------------------------");
    free(elem);
    fclose(arch);
    return 1;
}