#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <string.h>
#include <float.h>

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
    fclose(pfile);
    array=realloc(array, sizeof(int)*(contador+1));
    array[contador]=-1;
    printf("%d\n",array[149]);
    insertionsort(&array);
    printf("%d",array[149]);
    free(array);
    return 0;
} 



  