#include <iostream>
#include <math.h>
using namespace std;

class Point
{

    public:
        Point();
        Point(float setx, float sety);
        void printPoint();
        float getX();
        float getY();
        float setX(float newY);
        float setY(float newY);
        float getDistance(Point secondP);


    private:
        float x;
        float y;
};

Point::Point(){
    x = 0;
    y =0;
}

Point::Point(float setx, float sety){
    x = setx;
    y = sety;
}

void Point::printPoint(){
    std::cout<<"("<<x<<", "<<y<<")";
}

float Point::getX(){
    return x;
}

float Point::getY(){
    return y;
}

float Point::setX(float newX){
    x = newX;
}

float Point::setY(float newY){
    y = newY;
}

float Point::getDistance(Point secondP){
    float x1 = x;
    float x2 = secondP.getX();
    float y1 = y;
    float y2 = secondP.getY();

    return sqrt(((x2-x1)*(x2-x1))+((y2-y1) * (y2-y1)));
}


class Segment{

public:
    Segment();
    Segment(Point firstP, Point secondP);
    float getLength();
public:
    Point point1;
    Point point2;

};


Segment::Segment(){
    point1.setX(0);
    point1.setY(0);
    point2.setX(0);
    point2.setY(0);
}


Segment::Segment(Point firstP, Point secondP){
    point1.setX(firstP.getX());
    point2.setX(secondP.getX());
    point1.setY(firstP.getY());
    point2.setY(secondP.getY());
}


float Segment::getLength(){

    return point1.getDistance(point2);

}

class Shape
{
public:
  Shape():edgeCount(0){}
  Shape(Segment *S, int n) // to construct a shape with a serial of segment.
  {
   edgeCount=n;
  //cout<<n<<endl;
 for (int i =0;i<n;i++)
 {
        seg[i] = Segment(S[i]);  
 }
  }
   
  float getArea();
  Segment seg[10];
  int edgeCount;
};

class Rectangle : public Shape 
{
 public:
  Rectangle (){ 
  }

  Rectangle(Segment *S,int n=4):Shape(S,n){
  } 

        float getPerimeter(){
            return seg[0].getLength() + seg[1].getLength() + seg[2].getLength() + seg[3].getLength();
        } 
        float getArea(){
            float horizontal=0;
            float vertical=0;
            int startX = seg[0].point1.getX();
            int startY = seg[0].point1.getY();
            for(int i = 0; i <= 3; i++){ 
                if(i > 0 && startX == seg[i].point1.getX()){
                    //cout<<startX<<" ==1 "<<seg[i].point1.getX()<<endl;
                    vertical = seg[0].point1.getDistance(seg[i].point1);
                    //cout<<"vertical len is "<<vertical<<endl;
                    break;
                }
                if(startX == seg[i].point2.getX()){
                    //cout<<startX<<" ==2 "<<seg[i].point2.getX()<<endl;
                    vertical = seg[0].point1.getDistance(seg[i].point2);
                    //cout<<"vertical len is "<<vertical<<endl;
                    break;
                }     
            }

            for(int i = 1; i <= 3; i++){
                if(i > 0 && startY == seg[i].point1.getY()){
                    horizontal = seg[0].point1.getDistance(seg[i].point1);
                    break;
                }
                if(startY == seg[i].point2.getY()){
                    horizontal = seg[0].point1.getDistance(seg[i].point2);
                    break;
                }     
            }
            return horizontal*vertical;
        }

};