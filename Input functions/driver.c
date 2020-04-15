#include "function.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char filename[50];
    int w,h;
    int i,size,k;
    char *grid = (char*) malloc(sizeof(char));
    strcpy(filename,"file.txt");
    printf("%s\n",filename);
    read_inputFile(filename,&grid,&w,&h);
    size = w*h;
    k = 0;
    printf("width = %d\n",w);
    printf("height = %d\n\n",h);
    printf("grid = \n");
    for(i=0;i<size;i++){
        if(k > w-1){
            k = 1;
            printf("\n");
        }else{
            k++;
        }
        printf("%c",grid[i]);
    }
    free(grid);
}