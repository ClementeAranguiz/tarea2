#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertionsort(int *lista){
    int i=1;
    while(lista[i]!=-1){
        int current=lista[i];
        int prev=i-1;
        while(prev>=0 && lista[prev]>current){
            lista[prev+1]=lista[prev];
            prev--;
        }
        lista[prev+1]=current; 
        i++;
    } 
}

int *fileToArray(char *nombre_archivo){
    int *array=malloc(sizeof(int));
    FILE *pfile;
    pfile=fopen(nombre_archivo,"r");  
    char line[30];
    int contador=0;
    while(!feof(pfile)){
        array=realloc(array, sizeof(int)*(contador+1));
        char *current=fgets(line,8,pfile);
        array[contador]=atoi(current);
        contador++;
    }
    fclose(pfile);
    array=realloc(array, sizeof(int)*(contador+1));
    array[contador]=-1;
    return array;
}

int sizeofarray(int* array){
    int i=0;
    while(array[i]!=-1){i++;}
    return i;
}

void maxheap(int *array,int size){
    int i=1;
    while(array[i]!=-1){
        if (array[i]>array[(i-1)/2]){ 
            int j = i;
            while (array[j]>array[(j-1)/2]){ 
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
            if (array[indice] < array[indice+1] && indice<(i-1)){
                indice++; 
            }
            if (array[j] < array[indice] && indice<i){ 
                k=array[j];
                array[j]=array[indice];
                array[indice]=k;
            }
            j = indice; 
        } while(indice<i); 
    } 
} 

int main(){ 
    int *array=fileToArray("random_150.txt");
    int size=sizeofarray(array);
    heapsort(array,size);
    printf("%d\n",array[150]);
    array=fileToArray("random_150.txt");
    printf("%d\n",array[150]);
    array=fileToArray("random_150.txt");
    insertionsort(array);
    printf("%d\n",array[150]);
    free(array);
    return 0;
}