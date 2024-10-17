#include <iostream>
using namespace std;
class Digit
{
private:
    int num;

public:
    Digit(): num(0) {}
    Digit(int num_value)
    {
        setDigit(num_value);
    }

    void setDigit(int num_value)
    {
        if((num_value>=0 && num_value<10)||num_value ==-1 || num_value ==-2 || num_value ==-3)
        {
            num = num_value;
        }
        else
        {
            num = 0;
        }

    }
    int getDigit()
    {
        return num;
    }
};

class IntNumber
{
private:
    Digit number[1000];
public:
    IntNumber()
    {
        number[0].setDigit(0);
    }
    IntNumber(char *num)
    {
        int i = 0;
        int j = 0;
        while(num[i]!='\0')
        {
            if(num[i] =='+' && i==0)
            {
                i++;
            }
            else if(num[i]=='-' && i ==0)
            {
                number[j].setDigit(-1);
                i++;
                j++;
            }
            else if((num[i] -'0'<0)||(num[i]-'0'>9))
        {
            number[i].setDigit(-2);
                i++;
                j++;
            }
            else
            {
                number[j].setDigit(num[i]-'0');
                j++;
                i++;
            }
        }

        number[j].setDigit(-3);
    }
    void display()
    {
        int i = 0;
        if(number[0].getDigit()==-1)
        {
            if(number[1].getDigit()>0 && number[1].getDigit()<10)
            {
                cout<<"-";
                i++;
            }
            else
            {
                cout<<0;
            }
        }
        else if(number[0].getDigit()==-2)
        {
            cout<<0;
        }

        if(number[1].getDigit()==0)
        {
            while(number[i].getDigit()==0)
            {
                i++;
            }
        }
        while(number[i].getDigit()>=0 && number[i].getDigit()<10 && number[i].getDigit()!=-3)
        {
            cout<<number[i].getDigit();
            i++;
        }


    }

};
int main()
{
    char num[10000];
    cin>>num;
    IntNumber *number = new IntNumber(num);
    number->display();
    return 0;
}