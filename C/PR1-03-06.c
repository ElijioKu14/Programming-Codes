#include <stdio.h>
int main(void){

    int num = 0;

    scanf("%d", &num);

    if (num % 2 == 0){
        printf("%d", num);
    }
    else{
        num = num - 1;

        printf("%d", num);
    }
}