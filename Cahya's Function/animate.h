// C program for clearing console and
// comparing two different methods
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"tick.h"

void delay();
void animate(int h, int w, int count, char array[h][w]);

void delay(){
	// Storing start time
	clock_t start_time = clock();

	// looping till required time is not achieved
	while (clock() < start_time + 200);
}

void animate(int h, int w, int count, char array[h][w]){
    int i;
    system("cls");
    for (i = 0; i < count; i++) {
		// delay of one second
		delay();
		printf("\e[1;1H\e[2J");
		tick(array,h,w);
	}
}


