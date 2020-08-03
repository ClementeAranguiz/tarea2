#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heapsort.h"
#include "insertionsort.h"

void printarray(int *array){//imprime cada elemento del array
    int i=0;
    while(array[i]!=-1){
        printf("%d\n",array[i]);
        i++;
    }
}
int *fileToArray(char* nombre_archivo){//convierte el archivo a un array de enteros
    int *array=malloc(sizeof(int));    //reservando memoria dinamicamente
    FILE *pfile;                       //hasta llegar al final del documento
    pfile=fopen(nombre_archivo,"r");  
    char line[8];
    int contador=0;
    while(!feof(pfile)){
        array=realloc(array, sizeof(int)*(contador+1));
        char *current=fgets(line,8,pfile);
        array[contador]=atoi(current);
        contador++;
    }
    fclose(pfile);                                    //cierro el archivo
    array=realloc(array, sizeof(int)*(contador+1));   //asigno un ultimo espacio
    array[contador]=-1;                               //para insertar un -1 que indica donde  
    return array;                                     //termina el array
}

int sizeofarray(int* array){//recorre el array hasta encontrar el -1 para retornar el tamaño
    int i=0;
    while(array[i]!=-1){i++;}
    return i;
}

int main(int argc,char *argv[]){ 
    int *array=fileToArray(argv[1]);//crea el array a partir del archivo dado
    int size=sizeofarray(array);//calculo su tamaño
    if(!strcmp(argv[2],"insertionsort")){//si escribió insertionsort lo printea ordenado
        insertionsort(array);            //con insertionsort
        printarray(array);
    }
    if(!strcmp(argv[2],"heapsort")){//si escribió heapsort lo printea ordenado con heapsort
        heapsort(array,size);
        printarray(array);
    }
    free(array);//libero el array
    return 0;
}