#include <stdio.h>

int main(){
    FILE *file;
    int a,i,j;
    char b;
    file = fopen("file.txt","r");
    fscanf(file,"%d",&a);
    printf("%d\n",a);
    fscanf(file,"%d",&a);
    printf("%d\n",a);
    b = fgetc(file);
    for(i=0;i < 40;i++){
        b = fgetc(file);
        printf("%c",b);
    }

}