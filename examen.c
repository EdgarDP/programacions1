#include <stdio.h>
#include <math.h>
#include "main.h"

int main()
{

    float volumen, densidad, costo;
    char opcion;
    // PARTE GRAFICA PARA USUARIO
    printf("Elige el tipo de producto:\n");
    printf("a - ACEITE\n");
    printf("b - ALCOHOL\n");
    printf("c - GASOLINA\n");
    printf("d - ACETONA\n");
    scanf("%c", &opcion);
    printf("Ingresa el volumen a envasar:\n");
    scanf("%f", &volumen);

    if (volumen == 500) 
    {
        costo = 1.006;
    }
    else if (volumen == 1000)
    {
        costo = 1.6816;
    }
    else if (volumen == 1500)
    {
        costo = 1.9610;
    }
    else{
        costo = 3.1038;
    }
    

    switch(opcion)
    {
        case 'a': 
        densidad = 0.9; // aceite
        area(volumen, densidad, costo);
        break;
        case 'b': 
        densidad = 0.8; //alcohol
        area(volumen, densidad, costo);
        break;
        case 'c': 
        densidad = 0.68; // gasolina
        area(volumen, densidad, costo);
        break;
        case 'd': 
        densidad = 0.79; //acetona
        area(volumen, densidad, costo);
        break;
        default: // esto se va si el usario contesta mal
        printf("Opción no válida\n");
        break;
    }

}