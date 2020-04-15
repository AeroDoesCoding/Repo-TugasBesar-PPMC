#include <stdio.h>
#include <stdlib.h>

void read_inputFile(char filename[50], char** grid, int* width, int* height){
    FILE *textfile;
    int w,h,i,size;
    char input;
    char *new_grid;
    textfile = fopen(filename,"r");
    fscanf(textfile,"%d",&h);
    fscanf(textfile,"%d",&w);
    size = w*h;
    new_grid = (char*) malloc(size*sizeof(char));
    i = 0;
    while(i < size){
        input = fgetc(textfile);
        if(input != '\n'){
            new_grid[i] = input; 
            i++;
        }
    }
    *grid = new_grid;
    *width = w;
    *height= h;
}