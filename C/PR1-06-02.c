#include<stdio.h>

int main(void)
{
    int num1,num2,num3;
    int GCD;

    while(scanf("%d %d %d",&num1, &num2, &num3)!= -1){

    for(int i=1;i<=num1 || i<=num2 || i<=num3;i++)
    {


        if ((num1%i==0) && (num2%i==0) && (num3%i==0))

        {
            GCD=i;
        }



    }
printf("%d\n",GCD);

    }




}