#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5

int main()
{
    //declaro variables
    char *nombres[N];
    char *buff; //auxiliar
    //reserva dinamica para buff
    buff=(char *)malloc(20 * sizeof(char));

    //cargo el arreglo de nombres con reserva dinamica de memoria para cada nombre
    for (int i = 0; i < N; i++)
    {
        printf("ingrese el %d° nombre \n", (i+1));
        gets(buff);
        nombres[i]=(char *)malloc((strlen(buff)+1)*sizeof(char));
        strcpy(nombres[i], buff);
    }

    printf("--------------------\n");

    //muestro lo que hay en el arreglo
    for (int i = 0; i < N; i++)
    {
        printf("el %d° nombre ingresado es: \n", (i+1));
        puts(nombres[i]);
    }

    //libero la memoria
    for (int i = 0; i < N; i++)
    {
        free(nombres[i]);
    }
    free(buff);
    
    return 0;
}
