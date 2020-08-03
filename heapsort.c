#include "heapsort.h"
void maxheap(int *array,int size){      //Funcion que convierte el array en un arbol
    int i=1;                            //en el que cada hijo es menor que el padre.
    while(array[i]!=-1){                //Por cada numero del array
        if (array[i]>array[(i-1)/2]){   //Si el hijo es más grande que el padre
            int j = i;
            while (array[j]>array[(j-1)/2]){ //Cambia el hijo con el padre hasta que sea menor
                int k=array[j];
                array[j]=array[(j-1)/2];
                array[(j-1)/2]=k;
                j=(j-1)/2; 
            } 
        } 
        i++;
    } 
}

void heapsort(int *array, int size){
    maxheap(array,size);
    for(int i=size-1;i>0;i--){
        int k=array[0];
        array[0]=array[i];
        array[i]=k;
        int j=0,indice;  
        do{ 
            indice=(2*j+1);
            if (array[indice] < array[indice+1] && indice<(i-1)){//Si el hijo de la izquierda es mas
                indice++;                                        //pequeño que el de la derecha
            }                                                    //apunta a el de la derecha   
            if (array[j] < array[indice] && indice<i){ //cambia el hijo mayor por el padre
                k=array[j];
                array[j]=array[indice];
                array[indice]=k;
            }
            j = indice; 
        } while(indice<i); //Mientras queden numeros por
    } 
} 