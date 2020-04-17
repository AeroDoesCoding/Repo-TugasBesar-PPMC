/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
*  MODUL 9 – TUGAS BESAR
*  Kelompok : B-3
*  Hari dan Tanggal : Kamis, 15 April 2020
*  Asisten (NIM) : Lionel Valdrant (18316020)
*  Nama File : main.c
*  Deskripsi : Main File untuk conway's Game of Life
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"

int main(){
    int input,check_file,w,h,stop,frame;
    char filename[50];
    char *grid;
    FILE * file_check;
    printf("---------------CONWAY'S GAME OF LIFE---------------\n");
    printf("Masukkan nama file : ");
    scanf("%s",&filename);
    file_check = fopen(filename,"r");
    while(file_check == NULL){
        printf("\nNama File tidak dapat diakses/tidak ada!\nMasukkan nama file lagi :");
        scanf("%s",&filename);
        file_check = fopen(filename,"r");
    }
    fclose(file_check);
    read_inputFile(filename,&grid,&w,&h);
    print_grid(grid,w,h);
    printf("File telah berhasil di load\n");
    printf("seed awal | panjang = %d | tinggi = %d\n",w,h);
    stop = 0;
    while(stop == 0){
        printf("-----------Menu----------\n");
        printf("1.tick\n2.Animate\n3.Stop\n");
        printf("Masukkan pilihan menu: ");
        scanf("%d",&input);
        if(input == 1){
            tick(&grid,w,h);
        }else if(input == 2){
            printf("Masukkan berapa frame animasi mau dilakukan : ");
            scanf("%d",&frame);
            animate(&grid,w,h,frame);
        }else if(input == 3){
            printf("Program Berhenti");
            stop = 1;
        }else{
            printf("Input tidak diketahui!\n\n");
        }

    }


}