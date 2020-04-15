int check_cell(char* grid,int width,int height, int posX, int posY);
void read_inputFile(char filename[50],char** grid, int* width, int* height);
void delay_ms(int t);
void print_grid(char* grid,int width,int height);
void tick(char** grid,int width, int height);
void animate(char** grid,int width,int height,int frame);
