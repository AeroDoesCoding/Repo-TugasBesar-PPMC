/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
*  MODUL 9 – TUGAS BESAR
*  Kelompok : B-3
*  Hari dan Tanggal : Kamis, 15 April 2020
*  Asisten (NIM) : Lionel Valdrant (18316020)
*  Nama File : functions_eka.c
*  Deskripsi : Function file untuk main
*/

#include <stdio.h>
#include <stdlib.h>

//read_inputFile membaca file seed untuk Game of Life dan menaruhnya ke dalam sebuah array 1 dimensi dengan panjang dan lebarnya
void read_inputFile(char filename[50], char** grid, int* width, int* height){
    FILE *textfile;
    int w,h,i,size;
    char input;
    char *new_grid;

    //Input filename
    textfile = fopen(filename,"r");

    //Read height & width
    fscanf(textfile,"%d",&h);
    fscanf(textfile,"%d",&w);
    //Allocate mememory for new_grid array
    size = w*h;
    new_grid = (char*) malloc(size*sizeof(char));

    //Loop for reading the seed
    i = 0;
    while(i < size){
        input = fgetc(textfile);
        if(input != '\n'){
            new_grid[i] = input; 
            i++;
        }
    }
    //Assigning to param
    *grid = new_grid;
    *width = w;
    *height= h;
}

//function XY_to_i mengubah posisi dalam koodinat ke dalam hitungan array 1 dimensi
int XY_to_i(int x,int y, int w,int h){
    int i;
    i = (x + (w*(y-1)))-1;
    return i;
};

//function i_to_XY mengubah hitungan i array 1 dimensi ke dalam koordinat XY
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

/*Check_cell mengecek tetangga dari sebuah cell dengan posisi x,y dan menentukan apakah cell tersebut hidup atau mati di iterasi selanjutnya
  Return 1 jika hidup, return 0 jika mati*/
int check_cell(char* grid,int width,int height, int posX, int posY){
    int n_X[8],n_Y[8],n_I,j;
    int n_total,alive;

//Default neighbours assignment
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

//Check if cell is on left wall
    if(posX == 1){
        n_X[0] = width;
        n_X[3] = width;
        n_X[5] = width;
    }
//Check if cell is on right wall
    if(posX == width){
        //2,4,7
        n_X[2] = 1;
        n_X[4] = 1;
        n_X[7] = 1;
    }
//Check if cell is on top wall
    if(posY == 1){
        n_Y[0] = height;
        n_Y[1] = height;
        n_Y[2] = height;
    }
//Check if cell is on bottom wall
    if(posY == height){
        n_Y[5] = 1;
        n_Y[6] = 1;
        n_Y[7] = 1;
    }

//Counting alive neighbours loop
    n_total = 0;
    for(j=0;j<8;j++){
        n_I = XY_to_i(n_X[j],n_Y[j],width,height);
        if(grid[n_I] == 'X'){
            n_total++;
        }
    }
    //Checking alive or not of a cell (According to Conway's Rule)
    n_I = XY_to_i(posX,posY,width,height);
    if(grid[n_I] == 'X'){
        if(n_total == 2 || n_total == 3){
            alive = 1;
        }else{alive = 0;}
    }else{
        if(n_total == 3){
            alive = 1;
        }else{alive = 0;}
    }

    return alive;
}