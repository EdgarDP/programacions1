#include <stdio.h>

int main() {
    
    char dia = 0;
    int hora = 0;
    int duracion = 0;
    float precio = 0;

    printf("Día de tu llamada?\n\n");
    printf("L = LUNES\n");
    printf("M = MARTES\n");
    printf("X = MIERCOLES\n");
    printf("J = JUEVES\n");
    printf("V = VIERNES\n");
    printf("S = SABADO\n");
    printf("D = DOMINGO\n");
    scanf("%c" , &dia);
    
    printf("Lapso intermedio en horas de la llamada?\n");
    printf("Ejemplo: 2:30 tendra que ser 1430\n");
    scanf("%d" , &hora);

    printf("Tiempo en minutos de llamada\n");
    scanf("%d" ,  &duracion);
    
    
    if ((dia == 'L') || (dia == 'l') || (dia == 'M') || (dia == 'm') || (dia == 'X')||(dia == 'x') || (dia == 'J') || (dia == 'j') || (dia == 'V') || (dia == 'v') ){
        
        if ((hora > 559) || (hora < 2001)) {
            precio = 0.60*(duracion);
        }
        else if ((hora < 600) || (hora > 2000)) {
            precio = 0.20*(duracion);
        }
    }
    else if ((dia == 'S') || (dia == 's') || (dia == 'D') || (dia == 'd')) {
    precio = 0.15*(duracion);
    }
    else {
    printf("Datos equivocados, intentar de nuevo");
    }
    
    printf("Gastaste %f", precio);
    printf(" pesos");
}