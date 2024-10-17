char *trim(char *dest)
{
    int length = 0;
    int i = 0;

    length = strlen(dest);

    for(; *(dest+0) == ' ' || *(dest+0) == '\t'  || *(dest+0) == '\n';)
    {
        for(i = 0; i<length; i++)
        {
            *(dest+i) = *(dest+i+1);
        }
        length--;
    }

    for(;*(dest+length-1) == ' ' || *(dest+length-1) == '\t'  || *(dest+length-1) == '\n';)
    {
        *(dest+length-1) = '\0';
      	length--;
    }

    return (dest);
}