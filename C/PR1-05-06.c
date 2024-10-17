#include <stdio.h>
int main(void){
        int num = 0;
        int i = 0;
        int array[10];

        scanf("%d", &num);

        while( num !=0 ){
            //num = num % 10;
            array[i] = num % 10;

            i +=1;
            num = num / 10;
        }

        for( ; i > 0; i--){
            switch(array[i - 1]){
                case 9: printf("----. ");
                        break;
                case 8: printf("---.. ");
                        break;
                case 7: printf("--... ");
                       break;
                case 6: printf("-.... ");
                       break;
                case 5: printf("..... ");
                       break;
                case 4: printf("....- ");
                       break;
                case 3: printf("...-- ");
                       break;
                case 2: printf("..--- ");
                       break;
                case 1: printf(".---- ");
                       break;
                case 0: printf("----- ");
                       break;

            }
        }

}