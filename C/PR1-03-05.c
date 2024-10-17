#include <stdio.h>
int main(void){

    float num1 = 0;
    float num2 = 0;
    float add = 0;
    float sub = 0;
    float multiply = 0;
    float divide = 0;

    scanf("%f %f", &num1, &num2);
    add = num1 + num2;
    sub = num1 - num2;
    multiply = num1 * num2;
    divide = num1 / num2;

    printf("%f + %f = %.2f\n", num1, num2, add);
    printf("%f - %f = %.2f\n", num1, num2, sub);
    printf("%f * %f = %.2f\n", num1, num2, multiply);
    printf("%f / %f = %.2f", num1, num2, divide);

}