#ifndef FUNCIONES_PARA_GENERICOS_H_INCLUDED
#define FUNCIONES_PARA_GENERICOS_H_INCLUDED

#define TAM_APE 30
#define TAM_USUARIO 15
#define TAM_FEED 20

typedef struct {
    char usuario[TAM_USUARIO];
    int feed[TAM_FEED];
}tRegistro;

typedef struct
{
    unsigned id;
    char texto[141];
}tTweet;

typedef struct
{
    unsigned dni;
    char apellido[TAM_APE];
}tPersona;

int cmpdni(const void* a,const void* b);
int cmpidtw(const void* a,const void* b);
void printPersona(void* pv, void* param);
void printTweet(void* pinfo, void* param);
void printUsuario(void* pinfo, void* param);

#endif // FUNCIONES_PARA_GENERICOS_H_INCLUDED
