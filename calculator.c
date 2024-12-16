#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
 int main(){
  
    int  choice;
    double num1, num2;
    printf("-- Calculator by Harshit Mishra --\n");
    printf("\n------------------------------------\n");
    do{
        printf("\n\n\n\n-- Choose any operation --\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n"); 
        printf("4. Devision\n");
        printf("5. Help\n");
        printf("6. Visit website\n");
        printf("7. Exit\n\n enter your choice....\n\n");
          
        scanf("%d",&choice);
        if(choice >= 1 && choice <= 4){
            printf("Enter Values \n");
            scanf("%lf%lf",&num1,&num2);
        }
        switch(choice){
            case 1:
             printf("\n Calculating.........\n");
             printf("Result: %.2lf + %.2lf \n\n\n= %.2lf\n\n\n--------------------------\n\n\n\n ",num1,num2,num1+num2);
             break;
            case 2:
             printf("\n Calculating.........\n");
             printf("Result: %.2lf - %.2lf \n\n\n= %.2lf\n\n\n------------------------\n\n\n\n ",num1,num2,num1-num2);
             break;
            case 3:
             printf("\n Calculating.........\n");
             printf("Result: %.2lf * %.2lf \n\n\n = %.2lf\n\n\n-------------------------\n\n\n\n ",num1,num2,num1*num2);
             break;
            case 4:
              if(num2 != 0){
             printf("\n Calculating.........\n");
             printf("Result: %.2lf / %.2lf \n\n\n= %.2lf \n\n\n-------------------------\n\n\n\n",num1,num2,num1/num2);
              }else{
                printf("\n Devision by 0 (zero) is not possible !\n\n");
              }
             break;
            case 5:
             printf("\n Loading.........\n");
             printf("Help\n\n\n");
             break;
            case 6:
             printf("\npress enter to Visit Website\n");
             getchar();
             getchar();
             printf("\n Redirecting.........\n");
             system("start https://securecoder.vercel.app");

            break;
            case 7:
             printf("\n Thanks for visiting.........\n");
             printf("Exiting.....................good bye");
             printf("Press Enter to close the terminal\n\n");
             break;      
        }
    }while(choice != 7);
    getch();
    return 0;
 }