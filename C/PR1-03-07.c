#include <stdio.h>
int main(void){

    char letter;
    char new_letter;

    scanf("%c", &letter);
    new_letter = tolower(letter);

    printf("%c", new_letter);

}