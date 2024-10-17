#include <iostream>
#include <cmath>
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

    float getX()
    {
        return x;
    }
    float setX(float x_value)
    {
        x = x_value;
    }
        float getY()
    {
        return y;
    }
    float setY(float y_value)
    {
        y = y_value;
    }


    void printPoint()
    {
        cout <<"("<<x<<", "<<y<<")";
    }

    float getDistance(Point b)
    {
        return sqrt((x-b.x)*(x-b.x)+(y-b.y)*(y-b.y));
    }
};