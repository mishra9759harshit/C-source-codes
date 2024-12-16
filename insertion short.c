#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main(){
    int array[100], i, j, size, temp;
    printf("\n Enter the size of Array \n");
    scanf("%d",&size);
    for(i = 0; i < size; i++){
        scanf("%d",&array[i]);
    }
    for(i = 1; i < size; i++){
        temp = array[i];
        j = i - 1;
        while(j >= 0 && array[j] > temp){
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = temp;
    }
     printf("\n Array Sorted after insertion sort:\n");
     for(i = 0; i < size; i++){
        printf("%d",array[i]);
     }
      printf("\n\n Program executed succsesfully:\n\n Do you want to visit our website?\n\n Click Enter\n\n We are waiting for your response......\n\n\n");
      getchar();
      getchar();
      system("start https://securecoder.vercel.app");
     getch();
     return 0;
}