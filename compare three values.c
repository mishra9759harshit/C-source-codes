#include<stdio.h>
#include<conio.h>
int main(){
    int a,b,c;
    printf("\n Enter three digits to compare\n\n");
     for(int i = 0; i < 3; i++){
        printf("Digit %d :\n",i + 1);
        scanf("%d%d%d",&a,&b,&c);
        break;
     }
     if(a>b){
        if(b<c)
            printf("A is grater %d",a);
            else
            printf("c is greater %d",c);
     }else{
        if(b>c)
        printf("B is greater %d",b);
        else
        printf("C is greater %d",c);
     }
     getch();
     return 0;
}