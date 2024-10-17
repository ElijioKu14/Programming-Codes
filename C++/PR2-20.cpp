#include <iostream>
#include <string>
#include <cctype>
using namespace std;
class Encode
{
public:
    string str;
    Encode(string str_value)
    {
        str = str_value;
    }
    string encode()
    {
        string temp;
        for(int i=0; i<str.length();i++)
        {
            if(int(str.at(i))<100)
            {
                if(int(str.at(i))<10)
                {
                    temp = temp + "00" +to_string(int(str.at(i)));
                }
                else temp = temp + "0"+ to_string(int(str.at(i)));
            }
            else temp = temp+to_string(int(str.at(i)));
        }
        return temp;
    }
};
int main() {
  string str;
  getline(cin, str);
  Encode *code = new Encode(str);
  cout<<code->encode();
  return 0;
}