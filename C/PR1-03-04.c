#include <stdio.h>
int main(void){

    int num1 = 0;
    int num2 = 0;
    int add = 0;
    int sub = 0;
    int multiply = 0;
    int divide = 0;
    int modulus = 0;


    scanf("%d %d", &num1, &num2);
    add = num1 + num2;
    sub = num1 - num2;
    multiply = num1 * num2;
    divide = num1 / num2;
    modulus = num1 % num2;

    printf("%d + %d = %d\n", num1, num2, add);
    printf("%d - %d = %d\n", num1, num2, sub);
    printf("%d * %d = %d\n", num1, num2, multiply);
    printf("%d / %d = %d\n", num1, num2, divide);
    printf("%d %% %d = %d", num1, num2, modulus);

}