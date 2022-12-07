#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <time.h>

#define filas 10
#define columnas 10
#define NoCicloVida 50
#define NoMaximo 1
#define NoMinimo 1
#define NoMaximoVive 2
#define NoMinimoVive 1

char poblacion[filas][columnas];
int vida[4] = {NoMaximo,NoMinimo,NoMaximoVive,NoMinimoVive};
void poblacionInicial();
void llenarpoblacion();
void colorearpoblacion();
int analizarVecinos(int,int);
void cicloCelular();
void poblacionInicial(){
    int i,j;
    for (i = -1; i < filas; i++){
        for (j = -1; j < columnas; j++){
            poblacion[i][j] = '_';
        }
    }
}
void poblarVecindad(){
 int filas,x,y;
 rand(time(NULL));
 for (filas = 0; filas < columnas; ++fil){
  y = rand()%columnas;
  x = rand()%filas;
  if(poblacion[x][y]=='_')
   poblacion[x][y]='*';
 }
}
void colorearpoblacion(){
    int i,j;
    for (i = -0; i < filas; i++){
            printf("\n");
        for (j = -0; j < columnas; j++){
            printf("%c",vecindad[i][j] );
        }
    }
    printf("\n");
}
int analizarVecinos(int posf, int posc){
 int vecinos = 0;
 if(posf-1 >= 0 && posc-1 >= 0)
  if(poblacion[posf-1][posc-1] == '*')
   vecinos++;
 if(posf-1 >= 0)
  if(poblacion[posf-1][posc] == '*')
   vecinos++;
 if(posf-1 >= 0 && posc+1 <= columnas-1)
  if(poblacion[posf-1][posc+1] == '*')
   vecinos++;
 if(posc-1 >= 0)
  if(poblacion[posf][posc-1] == '*')
   vecinos++;
 if(posc+1 <= columnas-1)
  if(poblacion[posf][posc+1] == '*')
   vecinos++;
 if(posf+1 <= filas-1 && posc-1 >= 0)
  if(poblacion[posf+1][posc-1] == '*')
   vecinos++;
 if(posf+1 <= filas-1)
  if(poblacion[posf+1][posc] == '*')
   vecinos++;
 if(posf+1 <= filas-1 && posc+1 <= columnas-1)
  if(poblacion[posf+1][posc+1] == '*')
   vecinos++;
return vecinos;
}
void cicloCelular(){
int filas,columnas;
int n_vecinos;
for(filas = 0; filas < filas; filas++){
for(columnas = 0; columnas < columnas; columnas++){
n_vecinos = analizarVecinos(filas,columnas);
   if(poblacion[filas][columnas] == '_'){
    if(n_vecinos == NoMinimoVive || n_vecinos == NoMaximoVive)
     poblacion[filas][columnas] = '*';
    else
     poblacion[filas][columnas] = '_';
   }
   else if(poblacion[filas][columnas] == '*'){
    if(n_vecinos == NoMinimo || n_vecinos == NoMaximo)
     poblacion[filas][columnas] = '*';
    else
     poblacion[filas][columnas] = '_';
   }
  }
 }
}
int main(int argc, char *argv[])
{
 int i=0;
 poblacionInicial();
 llenarPoblación();  
 while(i < NoCicloVida){
  colorearPoblación();
  usleep(100000);
  system("clear");
  cicloCelular();
  i++;
 }
return 0;
}