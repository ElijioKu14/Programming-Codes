#include <iostream>
using namespace std;
class Fraction
{
  private:
  	int num;
  	int denum;

  public:
  	Fraction()
    {
      setNumerator(0);
      setDenominator(0);
    }
  	Fraction(int numerator, int denominator)
    {
      setNumerator(numerator);
      setDenominator(denominator);
    }

  	int getNumerator() const
    {
      return num;
    }
  	void setNumerator( int numerator)
    {
      num = numerator;
    }

  	int getDenominator()const
    {
      return denum;
    }
  	int setDenominator(int denominator)
    {
      denum = denominator;
    }

  	void display() const
    {
        int a = num, b = denum;
        while (b) { 
          int temp = b;
          b = a%b;
          a = temp;
        }
        cout << "(" << num/a;
        if (denum != a) cout << "/" << denum/a;
       cout << ")";
    }

  	 Fraction operator+(const Fraction& a)
    {
      Fraction c;
      if(getDenominator() == a.getDenominator())
         {
           c.setNumerator(getNumerator() + a.getNumerator());
           c.setDenominator(a.getDenominator());
         }
       else
         {
           c.setNumerator((getNumerator()*a.getDenominator()) + (a.getNumerator()*getDenominator()));
           c.setDenominator(a.getDenominator()*getDenominator());
         }
      return c;
    }

  	 Fraction operator-(const Fraction& a)
    {
      Fraction c;
      if(getDenominator() == a.getDenominator())
         {
           c.setNumerator(getNumerator() - a.getNumerator());
           c.setDenominator(a.getDenominator());
         }
       else
         {
           c.setNumerator((getNumerator()*a.getDenominator()) - (a.getNumerator()*getDenominator()));
           c.setDenominator(a.getDenominator()*getDenominator());
         }
      return c;
    }

     Fraction operator*(const Fraction& a)
    {
      Fraction c;
      c.setNumerator(getNumerator() * a.getNumerator());
      c.setDenominator(getDenominator() * a.getDenominator());
      return c;
    }
     Fraction operator/(const Fraction& a)
    {
      Fraction c;
      c.setNumerator(getNumerator() * a.getDenominator());
      c.setDenominator(getDenominator() * a.getNumerator());
      return c;
     }

  	 Fraction& operator=(const Fraction& b)
   	{
      		setNumerator(b.getNumerator());
            setDenominator(b.getDenominator());
            return *this;
     }

     friend ostream& operator <<(ostream& out, Fraction& f)
		{
        int a = f.num, b = f.denum;
        while (b) { 
          int temp = b;
          b = a%b;
          a = temp;
        }
        out << "(" << f.num/a;
        if (f.denum != a) cout << "/" << f.denum/a;
       out << ")";
          return out;
       	}
      Fraction operator!() 
    {
      Fraction *c= new Fraction();
        c->setNumerator(getDenominator());
        c->setDenominator(getNumerator());

      	return *c;

    }



};