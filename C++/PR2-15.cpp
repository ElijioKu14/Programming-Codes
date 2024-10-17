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
        return sqrt((b.x-x)*(b.x-x)+(b.y-y)*(b.y-y));
    }
};

class Segment
{
private:
    Point p1;
    Point p2;

public:
    Segment()
    {
        p1.setX(0);
        p1.setY(0);
        p2.setX(0);
        p2.setY(0);
    }

    Segment(Point p1_value, Point p2_value)
    {
        p1.setX(p1_value.getX());
        p1.setY(p1_value.getY());
        p2.setX(p2_value.getX());
        p2.setY(p2_value.getY());
    }
    float getLength()
    {
        return p1.getDistance(p2);
    }
};