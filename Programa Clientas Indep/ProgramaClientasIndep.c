#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void procesarDni(int*, int*, int*, int*, int*);
void facturacion(float,float,float,int,int,int, float*, float*, float*);

int main()
{
    int contVentasTotales, clientas, olla, sarten, utens;

    printf("Bienvenido/a! Este es un programa para procesar ventas de articulos de cocina.\nTe solicitare unos datos para poder continuar...\n\n");
        procesarDni(&clientas,&contVentasTotales,&olla,&sarten,&utens);
    printf("El total de vecinas procesadas es de %d\n\n",clientas);

        if (olla>sarten){
            if (olla>utens){
            printf ("El productor mas vendido fue la Olla\n\n");
            }
            } else {
                if (sarten>utens){
                printf("El producto mas vendido fue El Sarten\n\n");
                }else {
                    if(utens>sarten){printf("Los productos mas vendidos fueron los Utensillos\n\n");}
                    else { printf ("Mas de un producto genero buenas ventas\n\n");}
                    }}

    printf ("El total de ventas es de:%d\n\n",contVentasTotales);


    return 0;
}

void procesarDni(int* vecinas, int* contVentasTotal,int* olla, int* sarten, int* utens)
{
int dni, contVentas=0, acum=0, continuar;
float subt1=0.0,subt2=0.0, subt3=0.0,precioOlla=0.0,precioSar=0.0, precioUtens=0.0;
char categoria, producto;

    printf ("Por favor, ingrese el DNI del cliente o -1 para salir:\n\n"),
    scanf ("%d",&dni);
    printf ("Vecina-clienta con DNI numero:%d\n\n", dni);

        while (dni!=(-1))
        {
        *vecinas=+1;
        printf ("Por favor,seleccione su categoria de cliente: E-Especial o C-Comun\n\n");
        fflush (stdin);
        scanf ("%c", &categoria);

        printf ("Para continuar presione un numero cualquiera, si desea salir, cero\n\n");
        scanf ("%d", &continuar);

        while (continuar!=0)
        {
            printf ("Ingrese el tipo de producto: O-Olla,S-Sarten o U-Utensillos de cocina\n");
            fflush (stdin);
            scanf ("%c", &producto);

            switch (producto)
            {
            case 'O': *olla=+1;
                printf ("Ingrese el precio del mismo en decimales\n");
                scanf ("%f", &precioOlla);
                contVentas++;
                break;

            case 'S': *sarten=+1;
                printf ("Ingrese el precio del mismo en decimales\n");
                scanf ("%f", &precioSar);
                contVentas++;
                break;

            case 'U' : *utens=+1;
                printf ("Ingrese el precio del mismo en decimales\n");
                scanf ("%f", &precioUtens);
                contVentas++;
                break;

            default: printf ("Ingrese el tipo de producto: O-Olla,S-Sarten o U-Utensillos de cocina\n");
                break;
            }


            printf ("Para continuar presione un numero cualquiera, si desea salir, cero\n");
            scanf ("%d", &continuar);
        }


        if (categoria=='E'){

            facturacion (precioSar, precioOlla,precioUtens,*olla,*sarten,*utens, &subt1, &subt2,&subt3);
            subt1=subt1-((subt1*20)/100);
            subt2=subt2-((subt2*20)/100);
            subt3=subt3-((subt3*20)/100);
            printf ("Total de ollas es:%f\n\n",subt1);
            printf ("Total de sartenes es:%f\n\n", subt2);
            printf ("Total de utensillos de cocina es:%f\n\n", subt3);
        }
            else {
            if (categoria=='C')
            facturacion (precioSar, precioOlla,precioUtens,*olla,*sarten,*utens, &subt1, &subt2,&subt3);
            printf ("Total vecina %d:%f\n\n",dni,(subt1+subt2+subt3));
            printf ("Total de ollas es:%f\n\n",subt1);
            printf ("Total de sartenes es:%f\n\n", subt2);
            printf ("Total de utensillos de cocina es:%f\n\n", subt3);

        }

        *olla=0, *sarten=0, *utens=0;
        precioOlla=0.0,precioSar=0.0, precioUtens=0.0;
        *contVentasTotal=acum+contVentas;

        printf ("Por favor, ingrese el DNI de otro cliente o -1 para salir:\n\n"),
        scanf ("%d",&dni);

    }
}

void facturacion (float precioSar, float precioOlla,float precioUtens,int olla,int sarten,int utens, float* subt1, float* subt2, float* subt3)
{

*subt1=precioOlla*(olla);
*subt2=precioSar*(sarten);
*subt3=precioUtens*(utens);

}
