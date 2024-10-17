#include <stdio.h>
int main(void){
  int a = 0;
  int b = 0;
  int modulus = 0;
  
  scanf("%d %d", &a, &b);
  modulus = a % b;
  
  if(modulus == 0){
    printf("%d is a multiple of %d.", a, b);
  }
  else{
    printf("%d is not a multiple of %d.", a, b);
  }
    
}