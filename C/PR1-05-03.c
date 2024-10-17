#include <stdio.h>
int main(void){
   int i, num, p;

   scanf("%d", &num);

while( num != 0){
    p=0;
    for(i=1; i<=num; i++){
    if(num%i==0){
     p++;
    }
    }
    if(p==2){
        printf("prime");
            }
        else{
          printf("not a prime");
       }
        printf("\n");
       scanf("%d", &num);
       }
}