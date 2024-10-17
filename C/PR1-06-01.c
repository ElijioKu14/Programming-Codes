#include <stdio.h>
int main(){
 int num = 0;
 int low = 100;
 int high = 0;
 int flag;
 int counter = 0;
 int i = 0;
 int array[100000] ;

  do{
    flag = scanf("%d", &num);
    if(flag == -1)
        break;
    array[i] = num;
    i++;
    counter ++;
  } while(1);

 for(i = 0; i < counter ; i++){
   if( array[i] > high){
     high = array[i];
 }
    if( array[i] <low){
     low = array[i];
   }

 }
    printf("%d %d", high, low);
   return 0;
}