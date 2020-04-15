#include <stdio.h>
#include <stdlib.h>

int XY_to_i(int x,int y, int w,int h){
    int i;
    i = (x + (w*(y-1)))-1;
    return i;
};

void i_to_XY(int i,int* x,int* y,int w,int h){
    int a,j;
    a = i+1;
    j=0;
    while(a > w){
        a = a-w;
        j++;
    }
    *x = a;
    *y = j+1;
};

int check_cell(char* grid,int width,int height, int posX, int posY){
    int n_X[8],n_Y[8],n_I,j;
    int n_total,alive;

    n_X[0] = posX-1;
    n_Y[0] = posY-1;
    n_X[1] = posX;
    n_Y[1] = posY-1;
    n_X[2] = posX+1;
    n_Y[2] = posY-1;
    n_X[3] = posX-1;
    n_Y[3] = posY;
    n_X[4] = posX+1;
    n_Y[4] = posY;
    n_X[5] = posX-1;
    n_Y[5] = posY+1;
    n_X[6] = posX;
    n_Y[6] = posY+1;
    n_X[7] = posX+1;
    n_Y[7] = posY+1;

    if(posX == 1){
        n_X[0] = width;
        n_X[3] = width;
        n_X[5] = width;
    }
    if(posX == width){
        //2,4,7
        n_X[2] = 1;
        n_X[4] = 1;
        n_X[7] = 1;
    }
    if(posY == 1){
        n_Y[0] = height;
        n_Y[1] = height;
        n_Y[2] = height;
    }
    if(posY == height){
        n_Y[5] = 1;
        n_Y[6] = 1;
        n_Y[7] = 1;
    }

    n_total = 0;
    for(j=0;j<8;j++){
        n_I = XY_to_i(n_X[j],n_Y[j],width,height);
        if(grid[n_I] == 'X'){
            n_total++;
        }
    }
    n_I = XY_to_i(posX,posY,width,height);
    if(grid[n_I] == 'X'){
        if(n_total == 2 || n_total == 3){
            alive = 1;
        }else{alive = 0;}
    }else{
        if(n_total == 3){
            alive = 0;
        }else{alive = 0;}
    }
    return alive;
}