#include<stdio.h>
#include<conio.h>
 int main(){
    int array[100], s, key, found;
    printf("\n Enter the size of array :\n");
    scanf("%d",&s);
    printf("enter Elements of array :");
     for(int i = 0; i < s; i++){
        scanf("%d", &array[i]);
     }
     printf("\n All set nicely now Enter the No. to be search:\n");
     scanf("%d",&key);
     for(int i = 0; i < s; i++){
          if(key == array[i]){
            found = i;
            break;
          }
     } 
     if(found >= 0){
        printf("%d Number found at position %d",key,found + 1);
     }else{
        printf("Number Not Found\n");
     }
     getch();
     return 0;
 }