#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5

int main()
{
    //declaro variables
    int n;
    char **nombres;
    char *buff; //auxiliar

    printf("ingrese la cantidad de nombres \n");
    scanf("%d",&n); //ingreso el tamaño de mi arreglo
    fflush(stdin);
    nombres=(char **)malloc(n*sizeof(char *)); //reservo dinamicamente la memoria para mi arreglo
    
    buff=(char *)malloc(10 * sizeof(char)); //reserva dinamica para buff

    //cargo el arreglo de nombres con reserva dinamica de memoria para cada nombre
    for (int i = 0; i < n; i++)
    {
        printf("ingrese el %d° nombre \n", (i+1));
        gets(buff);
        nombres[i]=(char *)malloc((strlen(buff)+1)*sizeof(char));
        strcpy(nombres[i], buff);
    }

    printf("--------------------\n");

    //muestro lo que hay en el arreglo
    for (int i = 0; i < n; i++)
    {
        printf("el %d° nombre ingresado es: \n", (i+1));
        puts(nombres[i]);
    }

    //libero la memoria
    free(nombres);
    free(buff);
    
    return 0;
}
