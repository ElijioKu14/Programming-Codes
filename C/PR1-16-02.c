#include <stdio.h>
int main()
{
    int num1 = 0;
    int num2 = 0;
    int num_1[4]= {0,0,0,0};
    int num_2[4]= {0,0,0,0};
    int i = 0;
    int j = 0;
    int match = 0;
    int differ = 0;

    scanf("%d%d", &num1, &num2);

    for(i = 0; i<4; i++)
    {
        num_1[i] = num1%10;
        num1 = num1/10;
    }
    for(i = 0; i<4; i++)
    {
        num_2[i] = num2%10;
        num2 = num2/10;
    }


    for(i = 0; i <4; i++)
    {
        if(num_1[i] == num_2[i])
        {
            match++;
        }
        else
        {
            for(j =0; j <4; j++)
            {
                if(num_1[i] == num_2[j])
                {
                    differ++;
                }
            }
        }
    }

    printf("%d %d", match, differ);

}