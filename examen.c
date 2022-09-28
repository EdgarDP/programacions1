#include "main.h"
#include <stdio.h>
#include <math.h>

float main()
{
int volumen;
float densidad, precionuevo, rad, areanueva, costoanterior, difpre, peso;
char opcion;

printf("Seleccione el liquido: \n");
printf("a - aceite \n");
printf("b - alcohol \n");
printf("c - gasolina \n");
printf("d - acetona \n");
scanf("%c", &opcion);

printf("Ingrese el volumen: \n");
scanf("%d", &volumen);
rad = radio(volumen);
printf("El radio necesario es %f \n", rad);
areanueva = area(volumen);
printf("El area nueva es %f \n", areanueva);

switch (volumen)
{
case 500:
    costoanterior = 1.006;
    precionuevo = costo(rad, areanueva);
    break;
case 1000:
    costoanterior = 1.6816;
    precionuevo = costo(rad, areanueva);
    break;
case 1500:
    costoanterior = 1.9610;
    precionuevo = costo(rad, areanueva);
    break;
case 3000:
    costoanterior = 3.10386;
    precionuevo = costo(rad, areanueva);
    break;
default:
    costoanterior = 3.10386;
    precionuevo = costo(rad, areanueva);
    break;
}
printf("El costo anterior era %f \n", costoanterior);
printf("El costo nuevo es %f \n", precionuevo);
difpre = costoanterior - precionuevo;
printf("El ahorro es de %f \n", difpre);

switch (opcion)
{
case 'a':
peso = volumen * 0.9;
    break;
case 'b':
peso = volumen * 0.8;
    break;
case 'c':
peso = volumen * 0.68;
    break;
case 'd':
peso = volumen * 0.79;
    break;
default:
printf("Opcion no valida");
return 1;
    break;
}
printf("El peso en gramos por el volumen es de %f gramos \n", peso);

}