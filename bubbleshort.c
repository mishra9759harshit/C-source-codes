#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main(){
    int array[100], s, i, j, temp;
    printf("Enter Array element size\n");
    scanf("%d", &s);
    for(i = 0; i < s; i++){
        printf("\n Enter Elements to be sorting %d: ",i+1);
        scanf("%d", &array[i]);
    }
    for(i = 0; i < s; i++){
        for(j = 0; j < s - 1; j++){
            if(array[j] > array[j+1]){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
     printf("\n Sorted Elemnets:\n\n\n");
     for(i = 0; i < s; i++){
        printf("%d ",array[i]);
     }
     printf("\n\n\nProgram succesfully executed.........\n Now if You want to visit our website Click Enter\n we are waiting for your response......\n\n\n");
     getchar();
     getchar();
     system("start https:\\securecoder.vercel.app");
     getch();
     return 0;
}