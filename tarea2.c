#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <string.h>

void insertionsort(int *lista){
    int i=0;
    while(lista[i]!=-1){
        
        int current=lista[i];
        printf("%d\n",lista[i]);
        int prev=current-1;
        while(prev>=0 && lista[prev]>current){
            printf("%d\n",lista[i]);
            lista[prev+1]=lista[prev];
            printf("%d\n",lista[i]);
            prev--;
        }
        lista[prev+1]=current; 
        //printf("%d\n",lista[current]);
        i++;
    }
    
}

int main(){ 
    int *array=malloc(sizeof(int));
    FILE *pfile;
    pfile=fopen("random_150.txt","r");  
    char line[30];
    int contador=0;
    while(!feof(pfile)){
        array=realloc(array, sizeof(int)*(contador+1));
        char *current=fgets(line,8,pfile);
        array[contador]=atoi(current);
        contador++;
    }
    array=realloc(array, sizeof(int)*(contador+1));
    array[contador]=-1;

    fclose(pfile);
    insertionsort(array);
    //printf("%d",array[0]);
    free(array);
    return 0;
} 



  