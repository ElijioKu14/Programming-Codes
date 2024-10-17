#include <stdio.h>
#include <string.h>
int SuDoku[9][9], row[9][10], column[9][10], grid[9][10]; //declaration of array
int n, tn, flag; //declaration of variables
void DFS(int now) { //Function declaration of DFS
    if(flag == 1)
        return; //if flag is true, just exit function
    if(now == n*n) { //if the passed value ==n*n
        int i, j; //declares variables to be used
        flag = 1; //sets flag to true
        for(i = 0; i <n; i++ ) { //access sudoku array row
            for(j = 0; j <n; j++) { //access sudoku array column
                if(j)
                    printf(" ");
                printf("%d", SuDoku[i][j]); //prints out the value in that position in the sudoku array
            }
            puts("");
        }
    }
    int x = now/n, y = now%n;
    if(SuDoku[x][y] != 0) //if the value is not zero, call the function
        DFS(now+1);
    else { //if the value is zero, does have a number between 1-9
        int i,g = x/tn*tn+y/tn; //declaration of variables
        for(i = 1; i <= n; i++) { //access to the multiple arrays
            if(row[x][i] == 0 && column[y][i] == 0 && grid[g][i] == 0) { //starting position of the array
                row[x][i] = 1;
                column[y][i] = 1;
                grid[g][i] = 1;
                SuDoku[x][y] = i; //sets the position with a new value to complete the sudoku
                DFS(now+1); //calls the DFS function
                SuDoku[x ][y] = 0;
                row[x][i] = 0;
                column[y][i] = 0;
                grid[g][i] = 0;
            }
        }
    }
}
int main() {
    int first = 1 , i, j; //declaration of variables
    while(scanf("%d", &n) == 1) { //inputs an integer value into n
        tn = n; //stores n into tn
        n = n*n; //updates n to n*n
        memset(row, 0, sizeof(row)); //sets all values in row to 0's
        memset(column, 0, sizeof(column)); //sets all values in column to 0's
        memset(grid, 0, sizeof(grid)); //sets all values in grid to 0's
        for(i = 0; i <n; i++) { //array access of sudoku row
            for(j = 0; j <n; j++) { //array access of sudoku column
                scanf("%d", &SuDoku[i][j]); //inputs and stores the values into sudoku array
                row[i][SuDoku[i][j]] = 1;
                column[j][SuDoku[i][j]] = 1;
                grid[ i/tn*tn+j/tn][SuDoku[i][j]] = 1;
            }
        }
        if(!first) //if first is not 1
            puts(""); //removes the \0 from the last position
        flag = 0; //sets flag to false
        DFS(0); //calls function
        if(!flag) //if  flag is false
            puts ("NO SOLUTION"); ////replaces the \0 from the last position with the "NO SOLUTION"
        first = 0; //sets first to 0
    }
    return 0;
}