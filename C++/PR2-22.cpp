#include <iostream>
#include <algorithm>
using namespace std;
class Fraction
{
private:
    int N;
    int D;

public:
    Fraction()
    {
        setNumerator(0);
        setDenominator(1);
    }
    Fraction(int numerator, int denominator)
    {
        setNumerator(numerator);
        setDenominator(denominator);

    }
    int getNumerator()
    {
        return N;
    }
    int getDenominator()
    {
        return D;
    }
    void setNumerator(int numerator)
    {
        N = numerator;
    }
    void setDenominator(int denominator)
    {
        D = denominator;
    }
    void reduced_fraction()
    {
        int Common_d = 0;
        Common_d = __gcd(N, D);
        N = N/Common_d;
        D = D/Common_d;
        if(D <0)
        {
            setNumerator(N*-1);
            setDenominator(D*-1);
        }
    }
    void display()
    {
        reduced_fraction();
        if(D !=1)
        {
            cout <<"("<<N<<"/"<<D<<")";
        }
        else
        {
            cout <<"("<<N<<")";
        }
    }
};