#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>

using namespace std;

struct point
{
    double x;
    double y;
};

int N;
double dist;
vector<point> V;


void inputs() //reads the points and sorts them out
{
    double a, b;
    V.clear();
    for (int i = 0; i < N; ++i)
        cin >> a >> b, V.push_back({ a, b }); //adds new element to the end of the vector
}

double find_distance(point& a, point& b) //returns distance between two points
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

double Combine(int& a, int& b, int& mid, double& l, double& r)
{
    double d = min(l, r);
    double line = (V[mid].x + V[mid + 1].x) / 2;  //imaginary line that divides the points into left and right part
    double Min = d;

    for (int i = mid + 1; i <= b && V[i].x < line + d; ++i) //these for loops go through the right and left part and finds the min distance
        for (int j = mid; j >= a && V[j].x > line - d; --j)
            Min = min(Min, find_distance(V[i], V[j]));

    return Min;
}

double Divide(int a, int b) //recursion of divide and conquer algorithm
{
    if (a >= b) return 10000;

    int mid = (a + b) / 2;
    double l = Divide(a, mid); //left part
    double r = Divide(mid + 1, b); //right part

    return Combine(a, b, mid, l, r);
}

void display() //prints the results
{
    if (dist < 10000) cout << setprecision(4) << fixed << dist << "\n";
    else cout << "INFINITY\n";
}

int main()
{
    while (cin >> N, N)
    {
        inputs();
        sort(V.begin(), V.end(), [](point& a, point& b){return a.x < b.x;});
        dist = Divide(0, N - 1);
        display();
    }
}