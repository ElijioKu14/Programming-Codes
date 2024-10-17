#include <stdio.h>
#include <string.h>
struct TrieNd
{
    int LK[26];
    int ac;
} array1[100000];
int TrieSize = 0;
void insert_(char s[])
{
    static int i, j, k;
    for(i = 0, j = 0; s[i]; i++)
    {
        k = s[i]-'a'; //change from char to ascii
        if(!array1[j].LK[k])
        {
            TrieSize++;
            memset(&array1[TrieSize], 0, sizeof(array1[0]));
            array1[j].LK[k] = TrieSize;
        }
        j = array1[j].LK[k];
    }
}
void matchTrie(char s[]) //checks for
{
    static int i, j, k;
    for(i = 0, j = 0; s[i]; i++)
    {
        k = s[i]-'a'; //change from char to ascii
        array1[j].ac = 1;
        if(array1[j].LK[k])
            j = array1[j].LK[k];
        else
            break;
    }
    array1[j].ac = 1;
}
int mxlen = -1; //if no sequence is found
void dfs(int nd, int dep)  //checks for all sequences
{
    int i;
    for(i = 0; i < 26; i++)
    {
        if(array1[nd].LK[i] && array1[array1[nd].LK[i]].ac)
        {
            if(dep+1 > mxlen)
                mxlen = dep+1;
            dfs(array1[nd].LK[i], dep+1);
        }
    }
}
char path[512];
void dfs2(int nd, int dep) //cycles through the array to find the sequence
{
    for(int i = 0; i < 26; i++)
    {
        if(array1[nd].LK[i] && array1[array1[nd].LK[i]].ac)
        {
            path[dep] = i+'a';
            if(dep+1 == mxlen)
            {
                path[dep+1] = '\0';
                puts(path);
            }
            dfs2(array1[nd].LK[i], dep+1);
        }
    }
}
int main()
{
    char string1[300], string2[300];
    int i, first = 0;
    while(gets(string1))
    {
        gets(string2); //input string2
        if(first)
            puts("");
        first = 1;
        memset(&array1[0], 0, sizeof(array1[0]));//initialize array to zero
        TrieSize = 0;
        for(i = 0; string1[i]; i++)
            insert_(string1+i); //builds array
        for(i = 0; string2[i]; i++)
            matchTrie(string2+i);
        mxlen = -1;
        dfs(0, 0);
        if(mxlen > 0) //if there are more than one sequence with the same length
            dfs2(0, 0);
        else
            puts("No common sequence.");
        gets(string1); //input string1
    }
    return 0;
}