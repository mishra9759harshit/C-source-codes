#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main(){
  int m,n,p,q;
  printf("\n This Program is Made By Harshit Mishra for adding matrix\n\n");
  printf("\n----------------------------------------------------------\n\n");
  printf("Enter Row and column for the first matrix: ");
  scanf("%d%d",&m, &n);
  printf("Enter Row and column for the Second matrix: ");
  scanf("%d%d",&n, &q); 
 
  if(n != p){
    printf("\n Matrix multiplication not possible! Becuse(Second Row is not equal to First Column)\n\n Program executed successfully..........\n\n Click enter to visit my website\n\n We are waiting for your Response......\n\n");
          getchar();
          getchar();
          system("start https://securecoder.vercel.app");
    getch();
    return 0;
  } 
  int mat1[50][50], mat2[50][50], result[50][50];
  int i,j,k;
  // Input first matrix
   printf("\n Enter Elements for First matrix:\n");
    for(i = 0; i < m; i++)
     for(j = 0; j < n; j++)
       scanf("%d", &mat1[i][j]);
       
       printf("\n Enter Elements for second matrix:\n");
    for(i = 0; i < p; i++)
     for(j = 0; j < q; j++)
       scanf("%d", &mat2[i][j]);
       //multiply matrix
       for(i = 0; i < m; i++)
         for(j = 0; j < q; j++){
         result[i][j] = 0;
          for(k = 0; k < n; k++)
           result[i][j] += mat1[i][k] * mat2[k][i];
         }
          printf("\n Resultant Matrix\n\n");
          for(i = 0; i < m; i++){
           for(j = 0; j < q; j++){
              printf("%d", result[i][j]);
           }
             printf("\n");
          }
          printf("\n Program executed successfully..........\n\n Click enter to visit my website\n\n We are waiting for your Response......\n\n");
          getchar();
          getchar();
          system("start https://securecoder.vercel.app");
          getch();
           return 0;
}
           


          