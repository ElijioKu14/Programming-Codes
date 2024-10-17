#include <iostream>
#include<cmath>
#include <stdexcept>
using namespace std;
class Point
{
private:
public:
    float x,y;
    Point()
    {
        x=y=0;
    }
    Point(float x_,float y_)
    {
        x=x_;y=y_;
    }
    string printPoint()
    {
        cout<<"("<<x<<", "<<y<<")";
    }
    float getX(){return x;}
    void setX(float x){this->x=x;}
    float getY(){return y;}
    void setY(float y){this->y=y;}
    float getDistance(Point n)
    {
        float dx(0),dy(0);
        dx=getX()-n.getX();
        dy=getY()-n.getY();
        return sqrt(dx*dx+dy*dy);
    }
};
class Segment
{
public:
    Point point1,point2;
    Segment()
    {
        point1={0,0};
        point2={0,0};
    }
    Segment(Point pt1,Point pt2)
    {
        point1=pt1;
        point2=pt2;
    }
    float getLength()
    {
        float dx,dy;
        dx=point1.getX()-point2.getX();
        dy=point1.getY()-point2.getY();
        return sqrt(dx*dx+dy*dy);
    }
};
class Shape
{
public:
  Shape():edgeCount(0){}
  Shape(Segment *S, int n)
  {
      edgeCount=n;
      for(int i=0;i<n;i++)
        seg[i]=Segment(S[i]);
      for(int i=0;i<n;i++)
      {
          if(seg[i].point2.x==seg[i+1].point1.x&&seg[i].point2.y==seg[i+1].point1.y){}
        else if(seg[n-1].point2.x==seg[0].point1.x&&seg[n-1].point2.y==seg[0].point1.y){}  
        else{throw invalid_argument("invalid_argument");}

      }
  }
  virtual float getArea() = 0;
  float getPerimeter();
  Segment &getSeg(int index)
  {
   return seg[index];
  }
private:
  Segment seg[10];
  int edgeCount;
};