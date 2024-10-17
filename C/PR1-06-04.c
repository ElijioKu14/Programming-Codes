#include <stdio.h>
int main(){
  int height = 0;
  int day = 0;
  int night = 0;
  int total = 0;
  int day_taken = 1;


  scanf("%d %d %d", &height, &day, &night);
  if(day > height){
    printf("1");
  }
  else if(day < night)
  {
      printf("-1");
  }
else{
  while(total <= height){
        total = day + total;

  if( total >=height){
    goto done;
  }
  else{

   total = total - night;
   day_taken ++;
  }

  }
   done: printf("%d", day_taken);
}
  return 0;
}