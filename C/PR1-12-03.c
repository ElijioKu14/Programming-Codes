int merger(int *a, int *b, int *c)
{
  int i = 0;
  int j = 0;
  for(i = 0; i <5; i++)
  {	
    *(c+i) = *(a+i);
  }
   for(i = 0; i <5; i++)
  {	
    *(c+5+i) = *(b+i);
  }
  
  
  
  for(i = 0; i<10; i++)
  {
    for( j = i + 1; j <10; j++)
    {
      if(*(c+i) >*(c+j))
      {
        int temp= 0;
        temp = *(c+i);
        *(c+i) = *(c+j);
        *(c+j) = temp;
      }
    }
  }
}