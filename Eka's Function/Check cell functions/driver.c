/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
*  MODUL 9 – TUGAS BESAR
*  Kelompok : B-3
*  Hari dan Tanggal : Kamis, 15 April 2020
*  Asisten (NIM) : Lionel Valdrant (18316020)
*  Nama File : function.h
*  Deskripsi : Driver untuk pengujian check cell function
*/
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