#include "insertionsort.h"
void insertionsort(int *lista){
    int i=1;
    while(lista[i]!=-1){//Por cada numero del array
        int current=lista[i];//Almaceno el dato a cambiar
        int prev=i-1;        //y el indice anterior
        while(prev>=0 && lista[prev]>current){//mientras el numero de la izquierda sea mayor
            lista[prev+1]=lista[prev];        //cambialos
            prev--;                           //avanza hacia la izquierda
        }
        lista[prev+1]=current; //coloca el numero donde corresponde
        i++;  //avanza al siguiente numero
    } 
}