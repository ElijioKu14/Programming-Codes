#include <stdio.h>
#include <stdlib.h>


int main()
{
    int candidates = 1, votes = 1;
    while(1)
    {
        scanf("%d",&candidates);
        scanf("%d",&votes);
        int box[candidates];
        int num[votes];
        int count = 0;
        int winner = 0;
        int noWinner = 0;

        if(candidates == 0 && votes == 0)
        {
            break;
        }
        for (int i = 0; i < votes; i++) //store votes in array
        {
            scanf("%d",&num[i]);//check
        }//2nd line

        for(int i = 0;i < candidates;++i)
        {
            box[i] = 0;
        }//set candidate score to zero

        for(int i = 0;i < votes;++i)
        {
            if(num[i] <= candidates)
                box[num[i]-1]++;
        }//votes to which candidates

        for(int i = 0; i < candidates; i++)
        {
            if(box[winner] < box[i])
                winner = i;
        }//set who's the winner

        for(int i = 0; i < candidates; i++)
        {
            if(box[winner] == box[i] && i != winner)
            {
                printf("No winner\n");
                noWinner++;
                break;
            }
        }//if tie
        if (box[winner] > votes/2 && noWinner == 0)
            printf("Majoritarian winner %d\n", winner+1);
        else if (noWinner == 0)
            printf("Plurality winner %d\n", winner+1);
    }
    return 0;
}