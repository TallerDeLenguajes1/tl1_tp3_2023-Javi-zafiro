#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5
#define M 12

int main()
{
    //declaracion de variables
    int produccion[N][M];
    int suma, max=0, min=99999, anio[2], mes[2];
    float prom;
    srand(time(NULL));

    //carga y muestra la matriz
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            produccion[i][j]=rand()%40000 + 10000;
            printf(" %8d ", produccion[i][j]);
        }
        printf("\n");
    }

    //recorre la matriz, promedia las filas y guarda el valor mas grande y mas chico
    for (int i = 0; i < N; i++)
    {
        suma=0;
        for (int j = 0; j < M; j++)
        {
            suma=suma+produccion[i][j];
            if (produccion[i][j]>max)
            {
                max=produccion[i][j];
                anio[0]=i+1;
                mes[0]=j+1;
            }
            if (produccion[i][j]<min)
            {
                min=produccion[i][j];
                anio[1]=i+1;
                mes[1]=j+1;
            }
        }
        prom=suma/M;
        printf("el promedio de ganancias del %d° año es: %.2f \n", (i+1), prom);
    }
    printf("el valor maximo alcanzado es %d y se consiguio el mes %d del %d° año \n", max, mes[0], anio[0]);
    printf("el valor minimo alcanzado es %d y se consiguio el mes %d del %d° año \n", min, mes[1], anio[1]);
    return 0;
}

