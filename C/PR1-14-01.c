char *replace(char *source, char const *pattern, char const *replacement)
{
    int length_pattern = strlen(pattern);
    int length_replacement = strlen(replacement);
    int length_difference_R_P = length_replacement - length_pattern;
    static char *result;
    static int i;
    if(source != NULL)
    {
        result = source;
        i = 0;
    }
    else
    {
        source = result;
    }
    int length_source = strlen(source);

    int j = 0;
    int k = 0;
    int l = 0;
    int m = 0;
    int match = 0;

    for(; i<length_source && match!=1 ; i++)
    {
        if(*(source+i)== *(pattern+0))
        {
            for(j = 0; j<length_pattern; j++)
            {
                if((j == (length_pattern -1)) && (*(source+i+j) == *(pattern+j)))
                {
                    match = 1;
                }
                else if(*(source+i+j) != *(pattern+j))
                {
                    break;
                }
            }

            if(match == 1)
            {
                length_source +=length_difference_R_P;
                char temp[length_source -i];
                for(k = 0; k<length_source-i; k++)
                {
                    *(temp+k) = *(source+i+length_pattern+k);
                }
                for(l = 0; l <length_replacement; l++)
                {
                    *(source+i+l) = *(replacement+l);
                }
                for(m = 0; m<=length_source-(i+length_replacement); m++)
                {
                    *(source+i+length_replacement+m) = *(temp+m);
                }
                i = i + length_replacement;
                break;
            }

        }
    }

    return source;
}