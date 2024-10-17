#include <stdio.h>
int main()
{
    int num = 0;
    int counter = 0;

    scanf("%d", &num);

    if((num<4) || (num >32766))
    {

        printf("-1");
    }
    else
    {
        int initial = 3;
        int last = num - 3;
        do
        {
            if((initial + last) == num)
            {
                int p1 = 1, p2 = 1;
                for(int i=2; i <= initial/2; i++)
                {
                    if(initial%i==0)
                    {
                      	p1 = 0;
                        break;
                    }
                }
                for(int i=2; i <= last / 2; i++)
                {
                    if(last%i==0)
                    {
                        p2 = 0;
                        break;
                    }
                }


                if((p1 == 1) && (p2 == 1)){
                        counter++;
                    }

            }
            initial++;
            last--;
        }
        while(initial <=last);  

    }
    printf("%d", counter);
    return 0;
}