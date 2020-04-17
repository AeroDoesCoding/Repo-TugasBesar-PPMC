/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
*  MODUL 9 – TUGAS BESAR
*  Kelompok : B-3
*  Hari dan Tanggal : Kamis, 15 April 2020
*  Asisten (NIM) : Lionel Valdrant (18316020)
*  Nama File : function.c
*  Deskripsi : Implementasi pengujian read_inputFile function
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