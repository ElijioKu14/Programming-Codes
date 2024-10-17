#include <stdio.h>
#include <stdlib.h>

int row;
int col;
int been=999;
int array[1000][1000];
int spiral(int curR,int curC);

int main()
{
  scanf("%d %d",&row,&col);
  
  for(int i=0;i<row;i++)
  {
   for(int j=0;j<col;j++)
   {
    scanf("%d",&array[i][j]); 
     
   }
  }
  spiral(0,0);
}


int spiral(int curR, int curC)
{
  printf("%d ",array[curR][curC]);
  
  array[curR][curC]=been;
  
  if(curR-1 >=0 && array[curR-1][curC]!=been && (curC==0))
  {
    spiral(curR-1,curC);
    
  }
  
  if(array[curR][curC+1]!=been && curC+1<col)
  {
    spiral(curR,curC+1);
    
  }
  
  
  
  if(array[curR+1][curC]!=been && curR+1<row)
  {
    spiral(curR+1,curC);
    
  }
  
  if(array[curR][curC-1]!=been && curC-1>=0)
  {
    
    spiral(curR,curC-1);
    
  }
  
  
  
 return 0; 
}