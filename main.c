#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "heapsort.c"
#include "insertionsort.c"

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

int main(){ 
    int *array=fileToArray("random_10000.txt");//crea el array a partir del archivo dado
    int size=sizeofarray(array);//calculo su tamaño
    double suma=0.0;
        clock_t inicio = clock();
        heapsort(array,size);
        clock_t fin = clock();
        suma+=(double) (fin-inicio)/CLOCKS_PER_SEC;
    printf("hola");
    printf("%f",suma);
    free(array);//libero el array
    return 0;
}