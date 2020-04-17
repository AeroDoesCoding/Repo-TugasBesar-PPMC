#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Eka-------------------------------------------------------------------------------------------------------------------------------------
//read_inputFile membaca file seed untuk Game of Life dan menaruhnya ke dalam sebuah array 1 dimensi dengan panjang dan lebarnya
void read_inputFile(char filename[50], char** grid, int* width, int* height);
/*Check_cell mengecek tetangga dari sebuah cell dengan posisi x,y dan menentukan apakah cell tersebut hidup atau mati di iterasi selanjutnya
  Return 1 jika hidup, return 0 jika mati*/
int check_cell(char* grid,int width,int height, int posX, int posY);

//Emergency
void print_grid(char* grid,int width,int height);
void tick(char** grid,int width, int height);

//Cahya
void delay(int delay_time_ms);
void animate(int h, int w, int count, char** array);

