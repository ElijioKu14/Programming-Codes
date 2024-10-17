#include <iostream>
#include <cctype>
#include <cmath>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <array>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std ;

class Digit
{
    public :
        Digit()
        {
            setDigit(0) ;
        }
        Digit(int n)
        {
            setDigit(n) ;
        }
        int getDigit()
        {
            return this -> n ;
        }
        int setDigit(int n)
        {
            if(n < 0 || n > 9) this -> n = 0 ;
            else this -> n = n ;
        }
    private :
        int n ;
} ;

class IntNumber
{
    public :
        IntNumber(char *number)
        {
            this -> numChar = number ;
            string numbers(number) ;
            for(int i = 0 ; i < numbers.size() ; i++)
            {
                if(numbers[0] == '+') i++ ;
                else if(numbers[0] == '-' && !neg)
                {
                    this -> neg = true ;
                    i++ ;
                }
                if(!isdigit(numbers[i])) break ;
                if(numbers[i] > '0' && numbers[i] <= '9') this -> go = true ;
                if(numbers[i] >= '0' && numbers[i] <= '9' && go)
                {
                    this -> num[this -> count].setDigit(numbers[i] - '0') ;
                    this -> count++ ;
                }
            }
        }
        void display()
        {
            if(this -> count == 0)
            {
                cout << "0" ;
                return ;
            }
            else if(this -> neg) cout << "-" ;
            for(int i = 0 ; i < this -> count ; i++)
            {
                cout << this -> num[i].getDigit() ;
            }
        }
        IntNumber *add(const IntNumber *a) const
        {
            long long int sum = atoll(this -> numChar) + atoll(a -> numChar) ;
            string Sum = to_string(sum) ;
            char *sumChar = &Sum[0] ;
            return new IntNumber(sumChar) ;
        }
    private :
        Digit num[10000] ;
        int count ;
        char *numChar ;
        bool go = false ;
        bool neg = false ;
} ;

int main()
{
    char num1[10000], num2[10000] ;
    cin >> num1 >> num2 ;
    IntNumber *number1 = new IntNumber(num1) ;
    IntNumber *number2 = new IntNumber(num2) ;
    number1 -> display() ;
    cout << endl ;
    number2 -> display() ;
    cout << endl ;
    number1 -> add(number2) -> display() ;
    cout << endl ;
    number2 -> add(number1) -> display() ;
}