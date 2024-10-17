#include <stdio.h>

int main(void) {
        int rows = 0;
        int star = 0;
        int spaces = 0;
        int number_of_stars = 0;

        scanf("%d", &number_of_stars);

        int number_of_rows = number_of_stars;



        for (rows=1; rows <= number_of_rows; rows++) {
                        if(rows >1) {
                                printf("\n");
                        }
                for (spaces=1; spaces < number_of_stars; spaces++) {
                        printf(" ");
                }
                for (star=1; star <= rows; star++) {
                        printf("*");
                        if(star < rows){
                        printf(" ");

                }}

                number_of_stars = number_of_stars - 1;
        }

}