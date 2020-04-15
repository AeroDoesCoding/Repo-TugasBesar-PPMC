#include "function.h"
#include "input_function.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int x,y,w,h,a;
    char *grid;
    read_inputFile("file.txt",&grid,&w,&h);
    x = 24;
    y = 4;
    a = check_cell(grid,w,h,x,y);
    printf("%d",a);
    free(grid);
}