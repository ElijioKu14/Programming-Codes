#include <stdio.h>
int main(){

    char string [1000];
    int i = 0;
    int length = 0;
    int counter = 0;


    scanf("%s", string);


    length = strlen(string);

    for( i = 0; i < length/2; i++){

        if(tolower(string[i]) == tolower(string[length - 1 - i])){
            counter++;
        }

    }

    if( counter == i){
        printf("%s is a palindrome.", string);

    }
    else{
        printf("%s is not a palindrome.", string);
    }







}