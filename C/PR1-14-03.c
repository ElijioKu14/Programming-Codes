#include <stdio.h>
#include <string.h>

void compare(char array[][1000], int total)
{
    int i = 0;
    int j = 0;
    char temp[1000] = {'\0'};

    for(i = 0; i <total; i++)
    {
        for(j = 0; j<total-1; j++)
        {

            if(strcmp(array[j], array[j+1]) > 0)
            {
                strcpy(temp, array[j]);
                strcpy(array[j], array[j+1]);
                strcpy(array[j+1], temp);
            }
        }
    }

    for(i = 0; i <total; i++)
    {
        printf("%s\n", array[i]);
        /*if(i<(total-1))
        {
            printf("\n");
        }*/
    }

}


int main()
{
    int total = 0;
    int i = 0;

    scanf("%d", &total);

    char array[total][1000];

    for(i = 0; i <total; i++)
    {
        scanf("%s",array[i]);
    }

    compare(array, total);


}