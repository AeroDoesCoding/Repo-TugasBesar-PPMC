// C program for clearing console and
// comparing two different methods
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void delay(){
	// Storing start time
	clock_t start_time = clock();

	// looping till required time is not achieved
	while (clock() < start_time + 200);
}

void animate(int count){
    int i;
    system("cls");
    for (i = 0; i < count; i++) {
		// delay of one second
		delay();
		printf("\e[1;1H\e[2J");
		tick();
	}
}

// Driver code to test above function
int main(){
	return 0;
}
