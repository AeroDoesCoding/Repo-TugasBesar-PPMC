/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
*  MODUL 9 – TUGAS BESAR
*  Kelompok : B-3
*  Hari dan Tanggal : Kamis, 15 April 2020
*  Asisten (NIM) : Lionel Valdrant (18316020)
*  Nama File : input_function.c
*  Deskripsi : function read_input untuk pengujian check cell
*/
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