#include <stdio.h>
void zero_array(int row, int column, int array[][column])
{
    int i = 0;
    int j = 0;
    for(i = 0; i <row; i++)
    {
        for(j = 0; j <column; j++)
        {
            array[i][j] = 0;
        }
    }
}
void construct_array(int num,int row, int column, int array[][column])
{
    int z = 0;
    int num1 = 0, num2 = 0, num3 = 0;

    for(z = 0; z < num; z++)
    {
        scanf("%d%d%d", &num1, &num2, &num3);
        array[num1][num2] = num3;
    }
}
void print_array(int row, int column, int array[][column])
{
    int i = 0;
    int j = 0;
    for(i = 0; i <row; i++)
    {
        for(j = 0; j <column; j++)
        {
            printf("%d ", array[i][j] );
        }
        if(i <row-1)
        {
            printf("\n");
        }
    }
}
int main()
{

    int row = 0;
    int column = 0;
    int num = 0;

    scanf("%d%d%d", &row, &column, &num);
    int array[row][column];

    zero_array(row, column,array);
    construct_array(num, row, column, array);
    print_array(row, column, array);

}