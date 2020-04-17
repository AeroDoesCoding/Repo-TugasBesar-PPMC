void tick(char **grid,int h,int w){
    char* new_grid=(char*) malloc((w*h)*sizeof(char));
    int x,y,i,check;
    for (i=0;i<(w*h);i++){
        i_to_XY(i,&x,&y,w,h);

        if (check_cell(*grid,w,h,x,y)=1){
            new_grid[i]='X';
            }
        else{
            new_grid[i]='-';
        }
        }
    *grid=new_grid;
    print_grid(*grid,w,h);
    }
