#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILAS 10
#define COLUMNAS 10

// enumeracion de celdas existentes
enum celda
{
    oculto,
    vacio,
    bandera,
    mina
};

// tablero de juego en 2d
int tablero[FILAS][COLUMNAS];

// estado del juego en 2d
enum celda estado[FILAS][COLUMNAS];

// función para generar números aleatorios
int rand_int(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

// función para generar el tablero
void generate_tablero()
{
    // generador de números aleatorios
    srand(time(NULL));

    // Todas celdas al vacío
    for (int f = 0; f < FILAS; f++)
    {
        for (int c = 0; c < COLUMNAS; c++)
        {
            tablero[f][c] = 0;
            estado[f][c] = oculto;
        }
    }

    // generar las minas
    for (int i = 0; i < 10; i++) {
        // generar coordenadas aleatorias
        int f = rand_int(0, FILAS - 1);
        int c = rand_int(0, COLUMNAS - 1);

        // asegurar las celdas vacías
        if (tablero[f][c] == 0) {
            tablero[f][c] = -1;
        }
    }
}

// funcion para dibujar tablero
void print_tablero()
{
    printf("\n");

    // dibujar numero de columnas del tablero
    printf("  ");
    for (int c = 0; c < COLUMNAS; c++)
    {
        printf("%d ", c);
    }
    printf("\n");

    // pintar numero de filas del tablero
    for (int f = 0; f < FILAS; f++)
    {
        printf("%d ", f);
        for (int c = 0; c < COLUMNAS; c++)
        {
            switch (estado[f][c])
            {
            case oculto:
                printf("- ");
                break;
            case vacio:
                printf("%d ", tablero[f][c]);
                break;
            case bandera:
                printf("F ");
                break;
            case mina:
                printf("* ");
                break;
            }
        }
        printf("\n");
    }
}

// funcion para revelar la celda
void reveal_celda(int f, int c)
{
    // checar si está vacía
    if (estado[f][c] == oculto)
    {
        // revelar celda
        estado[f][c] = vacio;

        // checar si la celda tiene mina
        if (tablero[f][c] == -1)
        {
            estado[f][c] = mina;
        }
    }
}

// banderear celda
void flag_celda(int f, int c)
{
    // checar si está escondida la celda
    if (estado[f][c] == oculto)
    {
        // banderear la celda
        estado[f][c] = bandera;
    }
}

int main()
{
    // generar tablero
    generate_tablero();

    // imprimir tablero
    print_tablero();

    // saltar hasta que el juego acabe
    while (1)
    {
        // recibir filas y columnas del jugador
        int f, c;
        printf("ingresar filas y columnas: ");
        scanf("%d %d", &f, &c);

        // revelar la celda
        reveal_celda(f, c);

        // banderear la celda
        flag_celda(f, c);

        // imprimir tablero
        print_tablero();
    }

    return 0;
}


// Edgar Díaz Peraza 
// Francisco Avila Blanco