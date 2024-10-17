#include <stdio.h>

int main(void)
{
    int numbers[1000];
    int i=0,turn=1;


    do{
            if(turn==1)
                {scanf("%d",&numbers[i]);
                ++i;
                turn=0;}
            else
            {
            scanf("%s",&numbers[i]);
            ++i;
            turn=1;}
    }while(getchar()==32);

    int result=numbers[0];

    for(int z=1;z<i;z+=2){
            switch (numbers[z]){
                case 42: result*=numbers[z+1];break;
                case 43: result+=numbers[z+1];break;
                case 45: result-=numbers[z+1];break;
                case 47: result/=numbers[z+1];break;
            }
    }


    printf("%d",result);
    return 0;
}