char *mystrcat(char *dest, char *src)
{
  int length = 0;
  int i = 0;
  int length2 = 0;
  while( dest[length] != '\0')
  {
    length++;
  }
  while( src[length2] != '\0')
  {
	length2++;
  }

  for(i = 0; i<length2; i++)
  {
    *(dest+length+i) = *(src+i);
  }

  dest[length+length2] = '\0';
  return dest;
}

char *mystrncat(char *dest, char *src, int n)
{
  int length = 0;
  int i = 0;
  int length2 = 0;
  while( dest[length] != '\0')
  {
    length++;
  }
  while( src[length2] != '\0')
  {
	length2++;
  }

  for(i = 0; i<n; i++)
  {
    *(dest+length+i) = *(src+i);
  }

  dest[length+n] = '\0';
  return dest;
}