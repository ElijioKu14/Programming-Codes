#include <cmath>

class Point
{
private:
    float x;
    float y;

public:
    Point(): x(0), y(0)
    {}
    Point(float x_value, float y_value)
    {
        setX(x_value);
        setY(y_value);
    }
    void setX(float x_value)
    {
        x = x_value;
    }
    void setY(float y_value)
    {
        y = y_value;
    }
    float getX()
    {
        return x;
    }
    float getY()
    {
        return y;
    }
    float getDistance(Point a)
    {
        return sqrt((a.x - x)*(a.x-x) + (a.y-y)*(a.y-y));
    }


};

class Segment
{
private:
    Point a;
    Point b;

public:
    Segment()
    {
        a.setX(0);
        a.setY(0);
        b.setX(0);
        b.setY(0);
    }

    Segment( Point a_value, Point b_value)
    {
        a.setX(a_value.getX());
        a.setY(a_value.getY());
        b.setX(b_value.getX());
        b.setY(b_value.getY());
    }

    float getLength()
    {
        return a.getDistance(b);
    }

};

class Shape
{
private:
  Segment seg[10];
  int edgeCount;

public:
  Shape(): edgeCount(0)
  {}

  Shape(Segment *a, int num ) // to construct a shape with a serial of segment.
    {
        for(int i=0; i<num; i++)
        {
            seg[i] = a[i];
        }
    }
};