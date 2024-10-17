#include <iostream>
using namespace std;
template<typename T>
class Set
{
private:
    T element[100];
    int count;

public:
    Set()
    {
        count = 0;
    }

    Set(const Set<T> &a)
    {
        for(int i=0; i<a.count; i++)
        {
            element[i]= a.element[i];
        }
        count = a.count;
    }

    int add(const T num)
    {
        bool flag = false;
        for(int i =0; i <count; i++)
        {
            if(element[i]==num)
            {
                flag = true;
                break;
            }
        }
        if(!flag)
        {
            element[count] = num;
            count++;
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int add(const Set<T> a)
    {
        bool flag = false;
        int added = 0;
        for(int i = 0; i <a.count; i++)
        {
            for(int j = 0; j<count; j++)
            {
                if(a.element[i]== element[j])
                {
                    flag = true;
                    break;
                }

            }
            if(!flag)
            {
                element[count]=a.element[i];
                count++;
                added++;

            }
            flag = false;
        }
        return added;

    }

    void display()
    {
        int j;
        for(j = 0; j < count; j ++)
            std::cout<<element[j]<<" ";
    }

    Set<T> operator+ (Set<T> a)
    {
        Set<T> Union;
        for(int i = 0; i <count; i++)
        {
            Union.element[i] = element[i];
        }
        Union.count = count;
        Union.add(a);
        return Union;
    }

    Set<T> operator- (Set<T> a)
    {
        bool flag = false;
        Set<T> intersect;
        for(int i = 0; i <a.count; i++)
        {
            for(int j = 0; j<count; j++)
            {
                if(a.element[i]== element[j])
                {
                    flag = true;
                    break;
                }
            }
            if(flag)
            {
                intersect.element[intersect.count]= a.element[i];
                intersect.count++;
                flag = false;
            }

        }
        return intersect;
    }

};