#include<iostream>
#include <string>
#include <cctype>
using namespace std;

class Decode
{
public:
    string str;
    Decode(string str_value)
    {
        str = str_value;
    }
    string decode()
    {
        string temp;
        for(int i=0; i<str.length(); i = i+3)
        {
            temp= temp + char(((int(str.at(i))-48)*100) +(int(str.at(i+1)-48)*10)+(int(str.at(i+2)-48)));
        }
        return temp;
    }
};

int main() {
  string str;
  cin>>str;
  Decode *code = new Decode(str);
  cout<<code->decode();
  return 0;
}