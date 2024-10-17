#include <iostream>
void allocArray(int ***p, int m, int n)
{
  
      int i = 0;
    *p=new int*[m];
    for(i = 0;i < m; i++)
    {
        (*p)[i]=new int[n]; 

    }
  
}

int main()
{
  int **array, *a;
  int j, k;
  allocArray(&array, 5, 10);
  for(j = 0;j < 5;j ++)
    for(k = 0;k < 10;k ++)
      array[j][k] = j * 10 + k;
  for(j = 0;j < 5;j ++)
    for(k = 0;k < 10;k ++)
      printf("%p ", &(array[j][k]));
}