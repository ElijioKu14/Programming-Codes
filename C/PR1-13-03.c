char *replace(char *source, char *pattern, char *replacement)
{
    int length_source = strlen(source);
    int length_pattern = strlen(pattern);
    int length_replacement = strlen(replacement);
    int length_difference_R_P = length_replacement - length_pattern;
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int m = 0;
    int match = 0;

    for(i = 0; i<length_source && match!=1 ; i++)
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
            }

        }
    }
    return source;
}

char *replaceAll(char *source, char *pattern, char *replacement)
{
    int length_source = strlen(source);
    int length_pattern = strlen(pattern);
    int length_replacement = strlen(replacement);
    int length_difference_R_P = length_replacement - length_pattern;
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int m = 0;
    int match = 0;

    for(i = 0; i<length_source ; i++)
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
            }

        }
        match = 0;
    }
    return source;
}