/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
*  MODUL 9 – TUGAS BESAR
*  Kelompok : B-3
*  Hari dan Tanggal : Kamis, 15 April 2020
*  Asisten (NIM) : Lionel Valdrant (18316020)
*  Nama File : functions_eka.h
*  Deskripsi : Function file untuk main
*/

//read_inputFile membaca file seed untuk Game of Life dan menaruhnya ke dalam sebuah array 1 dimensi dengan panjang dan lebarnya
void read_inputFile(char filename[50], char** grid, int* width, int* height);
/*Check_cell mengecek tetangga dari sebuah cell dengan posisi x,y dan menentukan apakah cell tersebut hidup atau mati di iterasi selanjutnya
  Return 1 jika hidup, return 0 jika mati*/
int check_cell(char* grid,int width,int height, int posX, int posY);