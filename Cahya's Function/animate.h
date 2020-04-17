// C program for clearing console and
// comparing two different methods
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"tick.h"

void delay();
void animate(int h, int w, int count, char array[h][w]);

void delay(int delay_time_ms){
	// Storing start time
	clock_t start_time = clock();

	// looping till required time is not achieved
	while (clock() < start_time + delay_time_ms);
}

void animate(int h, int w, int count, char **array){
    int i;
    for (i = 0; i < count; i++) {
		// delay of one second
		if(h*w < 3000){
            delay(200);
		}
		else{
            delay(100);
		}
		tick(array,h,w);
	}
}


