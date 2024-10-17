#include <stdio.h>
int main(void){
  int a = 0;
  int temp = 0;
  scanf("%d", &a);

 while( a != 0 ){
    temp += a;
   scanf("%d", &a);
 }

  printf("%d", temp);
}