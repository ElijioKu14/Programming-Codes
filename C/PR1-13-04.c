#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void){


char str[100];

gets(str);
int length=strlen(str);
int i;
int words=length-1;
int end=length;

while(words>=0)
{
    if (str[words]==' '&& words>0){
        for(i=words+1;i<end;i++){
        printf("%c", str[i]);
        }

        printf(" ");
        end=words;

    }else if(words==0){
        for(i=0;i<end;i++)
        {
            printf("%c",str[i]);
        }
    }
    words--;
}
  
}