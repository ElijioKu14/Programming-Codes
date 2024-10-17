#include <iostream>
using namespace std;

int main()
{
    int num = 0;
    cin>>num;

    if(num%2 == 0)
    {
        cout<<num;
    }
    else{
        cout<<num-1;
    }

    return 0;
}