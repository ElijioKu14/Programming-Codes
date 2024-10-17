#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double x = 0;
    double y = 0;

    cin>>x>>y;

    double result = x/y;

    cout <<fixed<<setprecision(6)<<result;
    return 0;
}