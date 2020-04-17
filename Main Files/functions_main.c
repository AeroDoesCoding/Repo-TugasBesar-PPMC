#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Eka-----------------------------------------------------------------------------------------------------------------------------
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

//function XY_to_i mengubah posisi dalam koodinat ke dalam hitungan array 1 dimensi
int XY_to_i(int x,int y, int w,int h){
    int i;
    i = (x + (w*(y-1)))-1;
    return i;
};

//function i_to_XY mengubah hitungan i array 1 dimensi ke dalam koordinat XY
void i_to_XY(int i,int* x,int* y,int w,int h){
    int a,j;
    a = i+1;
    j=0;
    while(a > w){
        a = a-w;
        j++;
    }
    *x = a;
    *y = j+1;
};


int check_cell(char* grid,int width,int height, int posX, int posY){
    int n_X[8],n_Y[8],n_I,j;
    int n_total,alive;

//Default neighbours assignment
    n_X[0] = posX-1;
    n_Y[0] = posY-1;
    n_X[1] = posX;
    n_Y[1] = posY-1;
    n_X[2] = posX+1;
    n_Y[2] = posY-1;
    n_X[3] = posX-1;
    n_Y[3] = posY;
    n_X[4] = posX+1;
    n_Y[4] = posY;
    n_X[5] = posX-1;
    n_Y[5] = posY+1;
    n_X[6] = posX;
    n_Y[6] = posY+1;
    n_X[7] = posX+1;
    n_Y[7] = posY+1;

//Check if cell is on left wall
    if(posX == 1){
        n_X[0] = width;
        n_X[3] = width;
        n_X[5] = width;
    }
//Check if cell is on right wall
    if(posX == width){
        //2,4,7
        n_X[2] = 1;
        n_X[4] = 1;
        n_X[7] = 1;
    }
//Check if cell is on top wall
    if(posY == 1){
        n_Y[0] = height;
        n_Y[1] = height;
        n_Y[2] = height;
    }
//Check if cell is on bottom wall
    if(posY == height){
        n_Y[5] = 1;
        n_Y[6] = 1;
        n_Y[7] = 1;
    }

//Counting alive neighbours loop
    n_total = 0;
    for(j=0;j<8;j++){
        n_I = XY_to_i(n_X[j],n_Y[j],width,height);
        if(grid[n_I] == 'X'){
            n_total++;
        }
    }
    //Checking alive or not of a cell (According to Conway's Rule)
    n_I = XY_to_i(posX,posY,width,height);
    if(grid[n_I] == 'X'){
        if(n_total == 2 || n_total == 3){
            alive = 1;
        }else{alive = 0;}
    }else{
        if(n_total == 3){
            alive = 1;
        }else{alive = 0;}
    }

    return alive;
}

//Emergency----------------------------------------------------------------------------------
void print_grid(char* grid,int width,int height){
    int i,k;
    for(i=0;i<50;i++){
        printf("\n");
    }
    k = 0;
    for(i=0;i<(width*height);i++){
        if(k > width-1){
            k = 1;
            printf("\n");
        }else{
            k++;
        }
        printf("%c",grid[i]);
    }
    printf("\n");
}

void tick(char** grid,int width, int height){
    char* new_grid = (char*) malloc((width*height)*sizeof(char));
    int x,y,size,check,i;
    size = width * height;
    for(i=0;i<size;i++){
        i_to_XY(i,&x,&y,width,height);
        check = check_cell(*grid,width,height,x,y);
        if(check == 1){
            new_grid[i] = 'X';
        }else{
            new_grid[i] = '-';
        }
    }
    *grid = new_grid;
    print_grid(*grid,width,height);
}

//Cahya-----------------------------------------------------------------------------------------------------------------
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
		tick(array,w,h);
	}
}


