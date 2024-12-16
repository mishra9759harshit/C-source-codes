#include<stdio.h>
#include<conio.h>
 int main(){
    int  r,c;
    printf("\n Enter Array Row and column :\n");
    scanf("%d%d",&r,&c);
     int array[50][50];
     for( int i = 0; i < r; i++)
        for( int j = 0; j < c; j++){
       printf("Enter Array Elements for Row %d and column %d: ",i,j);
       scanf("%d", &array[i][j]);
       
 
     }
     printf("Index is :\n");
     for( int i = 0; i < r; i++){
        for( int j = 0; j < c; j++){
       
       printf("%d ",array[i][j]);
 }
     
     printf("\n");
     }
     printf("Bravo Program executed succesfully .......\n now Hit entr to close terminal\n.......");
     getch();
     return 0;
 }