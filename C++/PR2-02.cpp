#include <iostream>
using namespace std;

int main()
{
    int num = 0;
    cin>>num;

    for(int i=0; i<4; i++)
    {
        int temp = num%10;
        num /=10;
        cout<< temp;
    }

    return 0;
}