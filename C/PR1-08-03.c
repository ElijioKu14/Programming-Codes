#include <stdio.h>
#include <stdbool.h>

void Build_array(int row, int column,int array[][column] )
{
    int i =0;
    int j = 0;
    for(i = 0; i<row; i++)
    {
        for(j = 0; j <column; j++)
        {
            scanf("%d", &array[i][j]);
        }
    }

}

void Scan_array(int row, int column, int array[][column])
{

    int i =0;
    int j = 0;
    int counter = 0;

   while( i <row && j <column)
    {
        for(counter = j; counter < column; counter++)
        {
            printf("%d ", array[i][counter]);
        }
        i++;
        for(counter= i; counter <row; counter++)
        {
            printf("%d ", array[counter][column -1]);
        }
        column--;

        if (i<row)
        {
            for(counter = column -1; counter >= j; counter--)
            {
                printf("%d ", array[row -1][counter]);
            }
        row--;
        }

        if( j < column)
        {
            for(counter = row -1; counter >= i; counter-- )
            {
                printf("%d ", array[counter][j]);

            }
            j++;
        }
    }



}


int main()
{
    int row = 0;
    int column = 0;
    scanf("%d %d",&row, &column);

    int array[row][column];

    Build_array(row, column, array);
    Scan_array(row, column, array);


    return 0;
}