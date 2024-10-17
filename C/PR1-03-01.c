#include <stdio.h>
int main(void){
  float distance = 0;
  float time = 0;
  float velocity = 0;

  scanf("%f %f",&distance, &time);

  velocity = distance/time;

  printf("%f", velocity);
}