#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int binarysearch(int arr[], int size, int target){
    int low = 0, high = size - 1;
     while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] == target){
            return mid;
        }else if(arr[mid] < target){
           
           low = mid + 1;
        }else{
            high = mid - 1;
        }
     }
     return -1;
}
 int main(){
     int size, target;
     printf("Enter the size of the array:\n");
     scanf("%d", &size);
     int arr[size];
     printf("Enter %d sorted numbers:", size);
     for(int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
     }
     printf("Enter the number to search:\n");
     scanf("%d", &target);
     int result = binarysearch(arr,size,target);
     if(result != -1){
        printf("Element found at index %d", result+1);
     }else{
        printf("Element not found\n");
     }
      char input,right ='y';
     printf("\n Do you want to visit my website\n");
     printf("y/n\n");
     getchar();
     scanf("%c",input);
      if(input == right){
        printf("redirecting.......\n\n\n");
        system("start https://securecoder.vercel.app");
      }else{
        printf("thanks for visiting\n");
      }

     getch();
     return 0;
 }