#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED

int procesar_sin_cache(char* fileUsuarios, char* fileTweets);
int procesar_con_cache(char* fileUsuarios, char* fileTweets, unsigned tamCache);
void test_cache();
void printline();

#endif // LIB_H_INCLUDED
