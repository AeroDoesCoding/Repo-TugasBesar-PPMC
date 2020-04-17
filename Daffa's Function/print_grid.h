void print_grid(char* grid,int h,int w){
    int i,j;
    j=0;

    for (i=0;i<100;i++){
        printf("\n");
    }
    j=0;
   for (i=0;i<(w*h);i++){
        if (j>(w-1)){
            j=1;
            printf("\n");
        }
        else{
            j++;
        }
        printf("%c", grid[i]);
        }
        printf("\n");
    }
