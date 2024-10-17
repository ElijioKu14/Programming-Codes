#include <stdio.h>
#define NUM 15

void reverse()
{
    char letter;
    scanf("%c", &letter);

    if(letter != '\n')
    {
        reverse();
        printf("%c", letter);
    }

}

int main()
{
    reverse();
}