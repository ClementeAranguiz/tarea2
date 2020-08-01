#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertionsort(int **lista){
    int i=1;
    while((*lista)[i]!=-1){
        int current=(*lista)[i];
        int prev=i-1;
        while(prev>=0 && (*lista)[prev]>current){
            (*lista)[prev+1]=(*lista)[prev];
            prev--;
        }
        (*lista)[prev+1]=current; 
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
    while(1){
        if(array[size-2]);

    }
};


int main(){ 
    int *array=fileToArray("random_150.txt");
    int size=sizeofarray(array);
    maxheap(array,size);
    printf("%d\n",array[0]);
    printf("%d",sizeofarray(array));
    free(array);
    return 0;
}