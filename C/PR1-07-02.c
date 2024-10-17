#include <stdio.h>
int main(){
  int i = 0;
  int array[10];
  int first,second, temp;

    for(i = 0; i < 10; i++){
      scanf("%d", &array[i]);
    }


  for(first = 0; first < 10; first++){

    for(second = first + 1;second < 10; second++){
    if(array[first] > array[second]){

      temp = array[first];
      array[first] = array[second];
      array[second] = temp;
    }
  }  }
    for(i = 0; i < 10; i++){
            printf("%d ", array[i]);
}
}