#include <stdio.h>
int main(void)
{
    int num;

    scanf("%d",&num);

    while(num!=0){
    printf("%d = ",num);
    for( int i=2;i<=num;i++)
    {
       while(num%i==0)
       {
           if(i<num)
        { printf("%d * ",i);
        num/=i;
        } else
        {
            num/=i;
            printf("%d\n",i);
        }
       }
    }

        scanf("%d\n",&num);

    }



}