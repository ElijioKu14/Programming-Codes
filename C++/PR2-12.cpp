#include <iostream>
using namespace std;

class Point
{
private:
    float x;
    float y;

public:
    Point()
    {
        x=0;
        y=0;
    }
    Point(float x_value, float y_value)
    {
        x = x_value;
        y = y_value;
    }
    void printPoint()
    {
        cout <<"("<<x<<", "<<y<<")";
    }
};