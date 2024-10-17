#include <stdio.h>
int main(void){
  int num = 0;
  
  scanf("%d", &num);
  
  if( num % 2 == 0){
    printf("even");
  }
  else{
    printf("odd");
  }
}