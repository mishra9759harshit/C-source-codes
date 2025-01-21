#include<stdio.h>

int main(){
    int choice;
    
    printf("\n SecureCoder\n");
    printf("Choose an option\n");
    do{
        printf("1. Subscribe Securecoder\n");
        printf("2. Like Securecoder\n");
        printf("3. Next time\n");
        printf("Enter Your Choice\n");
        
        scanf("%d", &choice);
        switch(choice){
            case 1:
              printf("\n Thank you for subscribe i am honored take your Love!\n");
              break;

            case 2:  
              printf("Thank you for your like I am glad you like it\n");
              break;

            case 3:
              printf("It's Okay my freind\n");
              break;  
        }
    }while(choice != 3);
    
    return 0;
}