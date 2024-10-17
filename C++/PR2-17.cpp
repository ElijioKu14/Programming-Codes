class Digit
{
private:
    int num;

public:
    Digit(): num(0){}
    Digit(int num_value)
    {
        setDigit(num_value);
    }

    void setDigit(int num_value)
    {
        if(num_value>=0 && num_value<10)
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