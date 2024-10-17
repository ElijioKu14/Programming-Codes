#include <iostream>
#include <string>
using namespace std;

int x;
int y;
int caseNo;
int Total;
char bitmap[32][33];
string command;

void clear_bitmap() {
  for (int row = 0; row < 32; bitmap[row++][32] = '\0')
    for (int col = 0; col < 32; ++col)
      bitmap[row][col] = '.';
}

void init()
{
    cin>>Total;
    caseNo = 0;
}

bool input()
{
    if(caseNo++ == Total)
    {
        return false;
    }
    if(caseNo>1)
    {
        cout<<endl;
    }
        clear_bitmap();
        cin>>x>>y>>command;
        return true;
}


void E() {
  bitmap[y-1][x] = 'X';
  x++;
}

void W() {
  x--;
  bitmap[y][x] = 'X';
}

void N() {
  bitmap[y][x] = 'X';
  y++;
}

void S() {
  y--;
  bitmap[y][x-1] = 'X';
}

void Process()
{
    for(int i = 0; i<command.length(); ++i)
    {
        if(command[i]== '.')
        {
            break;
        }
        switch(command[i])
        {
        case 'N':
        {
            N();
            break;
        }
        case 'S':
        {
            S();
            break;
        }
        case 'E':
        {
            E();
            break;
        }
        case 'W':
        {
            W();
            break;
        }
        }
    }
    cout<<"Bitmap #"<<caseNo<<endl;
    for(int r = 31; r>=0; --r)
    {
        cout<<bitmap[r]<<endl;
    }
}

int main()
{
    init();
    while(input())
    {
        Process();
    }
    return 0;
}