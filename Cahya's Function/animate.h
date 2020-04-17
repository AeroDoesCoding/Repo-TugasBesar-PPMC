/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* Modul             : Tugas Besar
* Percobaan         : Game of Life by John Horton Conway
* Hari dan Tanggal  : Jumat, 17 April 2020
* Nama (NIM)        : Cahya Yugansyah (13218047)
* Nama Asisten      : Lionel Valdarant
* Nama File         : animate.h
* Deskripsi         : Membuat fungsi untuk menganimasikan game of life dengan
*                     menentukan berapa frame yang akan dianimasikan
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"tick.h"

void delay(int delay_time_ms);
void animate(int h, int w, int count, char **array);

void delay(int delay_time_ms){
	// Menyimpan start_time agar dapat menghitung waktu yang digunakan
	clock_t start_time = clock();

	// looping hingga mencapai waktu yang diinginkan
	while (clock() < start_time + delay_time_ms);
}

void animate(int h, int w, int count, char** array){
    int i;
    // mengulang sebanyak count dengan parameter i
    for (i = 0; i < count; i++) {
		// delay 200 ms jika besar array kurang dari 3000
		if(h*w < 3000){
            delay(200);
		}
		// delay 100 jika besar array lebih dari 3000 karena print yang menghasilkan delay
		else{
            delay(100);
		}
		// melakukan tick array (melakukan print sekaligus mengikuti aturan Game of Life
		tick(array,h,w);
	}
}


