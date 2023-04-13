#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Producto {
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
} typedef Producto;

struct Cliente {
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos; //El tamaño de este arreglo depende de la variable CantidadProductosAPedir
} typedef Cliente;

float totalProducto(Producto x);

int main()
{
    char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};
    Cliente *puntClientes;
    int cantidad;
    char buff[25];
    int aux, aux2;
    float totalFinal=0, porProducto=0;

    srand(time(NULL));
    printf("ingrese la cantidad de clientes \n");
    scanf("%d",&cantidad);
    fflush(stdin);
    puntClientes=(Cliente *)malloc(cantidad*sizeof(Cliente));
    for (int i = 0; i < cantidad; i++)
    {
        puntClientes[i].ClienteID=i+1;
        printf("por favor ingrese el nombre del cliente %d \n", (i+1));
        gets(buff);
        puntClientes[i].NombreCliente=(char *)malloc((strlen(buff)+1)*sizeof(char));
        strcpy(puntClientes[i].NombreCliente, buff);
        aux=1+rand()%5;
        puntClientes[i].CantidadProductosAPedir=aux;
        puntClientes[i].Productos=(Producto *)malloc(aux*sizeof(Producto));
        for (int j = 0; j < aux; j++)
        {
            puntClientes[i].Productos[j].ProductoID=j+1;
            puntClientes[i].Productos[j].Cantidad=1+rand()%10;
            aux2=rand()%4;
            puntClientes[i].Productos[j].TipoProducto=(char *)malloc((strlen(TiposProductos[aux2])+1)*sizeof(char));
            strcpy(puntClientes[i].Productos[j].TipoProducto,TiposProductos[aux2]);
            aux2=10+rand()%90;
            puntClientes[i].Productos[j].PrecioUnitario=(float)aux2;
        }
        
    }
    
    for (int i = 0; i < cantidad; i++)
    {
        printf("los datos del cliente %d son:\n", (i+1));
        printf("el id del cliente es: \n");
        printf("%d \n", puntClientes[i].ClienteID);
        printf("el nombre del cliente es: \n");
        puts(puntClientes[i].NombreCliente);
        printf("la cantidad de productos que pidio son: \n");
        printf("%d\n",puntClientes[i].CantidadProductosAPedir);
        printf("estos productos son: \n");
        for ( int j = 0; j < puntClientes[i].CantidadProductosAPedir ; j++)
        {
            printf("=================================\n");
            printf("datos del producto %d\n", (j+1));
            printf("id: \n");
            printf("%d\n",puntClientes[i].Productos[j].ProductoID);
            printf("cantidad: \n");
            printf("%d \n", puntClientes[i].Productos[j].Cantidad);
            printf("tipo: \n");
            puts(puntClientes[i].Productos[j].TipoProducto);
            printf("precio unario: \n");
            printf("$ %.2f \n", puntClientes[i].Productos[j].PrecioUnitario);
            porProducto=totalProducto(puntClientes[i].Productos[j]);
            printf("precio por este producto: $ %.2f \n", porProducto);
            totalFinal=totalFinal+porProducto;
            printf("=================================\n");
        }
        printf("el total a pagar es: $ %.2f \n", totalFinal);
        printf("+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*\n");
        totalFinal=0;
    }
    
    for (int i = 0; i < cantidad; i++)
    {
        free(puntClientes[i].NombreCliente);
        for (int j=0; j<puntClientes[i].CantidadProductosAPedir; j++){
            free(puntClientes[i].Productos[j].TipoProducto);
        }
        free(puntClientes[i].Productos);
    }
    free(puntClientes);
    return 0;
}

float totalProducto(Producto x){
    float res;
    res=(x.Cantidad)*(x.PrecioUnitario);
    return res;
}
