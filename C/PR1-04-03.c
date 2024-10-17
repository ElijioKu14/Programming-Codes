#include <stdio.h>
int main(void){
  int a = 0;
  int b = 0;
  int c = 0;
  int d = 0;
  int temp;
  scanf("%d%d%d%d", &a, &b, &c, &d);
  if(a > b)
  {
    temp = a;
    a = b;
    b = temp;
  }
  if(c > d)
  {
    temp = c;
    c = d;
    d = temp;
  }
  if( a > d || c > b ){
    printf("no overlay");
  }
  else {
    printf("overlay");
  }
  
}