#include <stdio.h>
#include <stdlib.h>
#define ROW 19
#define COL 19

int main()
{
   char gomoku[ROW][COL];
   char winner;

   for(int i=0;i<ROW;++i)
    {
        for(int j=0;j<COL;++j)
        {

        scanf("%c",&gomoku[i][j]);

        }
        getchar();
    }
/*
    printf("\n\n");

    for(int i=0;i<ROW;++i)
    {
        for(int j=0;j<COL;++j)
        {

        printf("%c",gomoku[i][j]);

        }

    printf("\n");

    }
   */

   for(int i=0;i<ROW;i++)
   {
       for(int j=0;j<COL ;j++)
       {

           if(gomoku[i][j]!='_')
           {        // does negative linear line  \\\\\\\\\\\\\\\

               if(i+4<=18 && j+4<=18)
                {
                    if(gomoku[i][j]==gomoku[i+1][j+1] && gomoku[i+1][j+1]==gomoku[i+2][j+2] && gomoku[i+2][j+2]==gomoku[i+3][j+3] && gomoku[i+3][j+3]==gomoku[i+4][j+4])
                 {
                     winner=gomoku[i][j];
                     break;
                 }
                   //next is positive linear line
               }if(i+4<=18 && j-4>=0)
               {
                   if(gomoku[i][j]==gomoku[i+1][j-1] && gomoku[i+1][j-1]==gomoku[i+2][j-2] && gomoku[i+2][j-2]==gomoku[i+3][j-3] && gomoku[i+3][j-3]==gomoku[i+4][j-4])
                {
                   winner=gomoku[i][j];
                   break;
                }
               }if(gomoku[i][j]==gomoku[i][j+1] && gomoku[i][j+1]==gomoku[i][j+2] && gomoku[i][j+2]==gomoku[i][j+3] && gomoku[i][j+3]==gomoku[i][j+4]) //right
               {
                   winner=gomoku[i][j];
                   break;
               }if(gomoku[i][j]==gomoku[i+1][j] && gomoku[i+1][j]==gomoku[i+2][j] && gomoku[i+2][j]==gomoku[i+3][j] && gomoku[i+3][j]==gomoku[i+4][j] )//down
               {
                   winner=gomoku[i][j];
                   break;
               }
           }
       }

   }

if(winner=='O')
{
    printf("White");
}else if (winner=='X')
{
    printf("Black");
}else
{
    printf("No winner");
}


return 0;




}