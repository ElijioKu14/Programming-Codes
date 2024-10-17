#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; //variable declaration for size of array
    while(cin >> n && n){ //input size of array
        bool arr[n][n]; //declaration of 2-d array of size n
        int rowSum[n] = {0}, colSum[n] = {0}; //declares new arrays and sets values in arrays to zero
        for(int i = 0; i < n; i++){ //for loop to allow input and enter the values into array // row
            for(int j = 0; j < n; j++){ //column
                cin >> arr[i][j]; //values entered into the specified position
                if(arr[i][j]){ //if this position is in the array - valid range
                    rowSum[i]++; //counter for size  of row
                    colSum[j]++; // counter for size of column
                }
            }
        }
        int changeRow = -1, changeCol = -1; //will stored the position in the array to make it have parity property
        bool printed = false; //flag
        for(int i = 0; i < n; i++){
            if(rowSum[i] % 2){ //if more than 2 places need their values changed(row)
                if(changeRow != -1){ //if no possible position for the value to be changed
                    cout << "Corrupt" << endl; //print corrupt
                    printed = true; //change flag
                    break;
                }
                changeRow = i; //update the position of the value that needs to be changed (row)
            }
            if(colSum[i] % 2){ //if more than 2 places need their values changed(column)
                if(changeCol != -1){ //if no possible position for the value to be changed
                    cout << "Corrupt" << endl; //print corrupt
                    printed = true; //change counter
                    break;
                }
                changeCol = i; //update the position of the value that needs to be changed (column)
            }
        }
        if(!printed){ //if the flag is not true
            if((changeRow == -1 && changeCol != -1) || (changeRow != -1 && changeCol == -1)){
                cout << "Corrupt" << endl; //if the only the row can be changed but not the column position or vice versa //corrupt
            }
            if(changeRow != -1 && changeCol != -1){ //if  both row and column positions can be changed
                cout << "Change bit (" + to_string(changeRow + 1) + "," + to_string(changeCol + 1) + ")" << endl; //print out the position (row,column)
            }
            if(changeRow == -1 && changeCol == -1){ //if both row and column have parity
                cout << "OK" << endl; //just print okay
            }
        }
    }
    return 0;
}