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

  	void display()
    {
		for (int i = (denum * num)/10; i > 1; i--)
        {
         	if ((denum % i == 0) && (num % i == 0))
            	{
            		setDenominator(denum/i);
                	setNumerator(num/i);
        		}
        }

      	if(denum ==1)
        {
          cout<<"("<<num<<")";
        }
      else
      {
        cout<<"("<<num<<"/"<<denum<<")";
      }
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

  	 Fraction operator=(const Fraction& b)
   	{
      		setNumerator(b.getNumerator());
            setDenominator(b.getDenominator());
     }

     friend ostream& operator <<(ostream& output, Fraction& a)
		{
       
       		for (int i = (a.getDenominator() * a.getNumerator())/10; i > 1; i--)
        {
         	if ((a.getDenominator() % i == 0) && (a.getNumerator() % i == 0))
            	{
            		a.setDenominator(a.getDenominator()/i);
                	a.setNumerator(a.getNumerator()/i);
        		}
        }

      	if(a.getDenominator() ==1)
        {
          output<<"("<<a.getNumerator()<<")";
        }
      else
      {
        output <<"("<<a.getNumerator()<<"/"<<a.getDenominator()<<")";
      }

          return output;
       	}



};