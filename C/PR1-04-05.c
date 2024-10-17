#include <stdio.h>


int main(void) {

 int a,b,c;
 int sqa,sqb,sqc;
 scanf("%d%d%d",&a,&b,&c);

 sqa= a*a;
 sqb= b*b;
 sqc= c*c;
 if ((a+b)>c){
    if ((sqa+sqb)==sqc){
        printf("right triangle");
    } 
   else if ((sqa+sqb)>sqc){
        printf("acute triangle");
    } 
   else if ((sqa+sqb)<sqc){
    printf("obtuse triangle");
    }
 }
  else {
     printf("can not construct");
}
}