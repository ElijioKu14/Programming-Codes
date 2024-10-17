#include <iostream>
#include <string.h>
#define SIZE 100

using namespace std;

class Queue
{
public:
    Queue()
    {
        data[0];
        front_ = 0;
        back_ = 0;

    }
    int enqueue(int d)
    {
        if(front_ <100)
        {
            data[front_] = d;
            front_++;
            return 1;
        }
        else return -1;
    }
    int *dequeue()
    {
        if(front_ != back_)
        {
            int *p;
            *p = data[back_];
            back_++;

            return p;
        }
        else return NULL;
    }
private:
    int data[SIZE];
    int front_;
    int back_;
};

int main()
{
    int data, *temp;
    char command[50];
    Queue *queue = new Queue();
    while(1)
    {
        cin>>command;
        if(strcmp(command, "exit") == 0)
        {
            break;
        }
        else if(strcmp(command, "enqueue") == 0)
        {
            cout<<"Please input a integer data:";
            cin>>data;
            if(queue->enqueue(data) == 1)
            {
                cout<<"Successfully enqueue data "<<data<<" into queue."<<endl;
            }
            else
            {
                cout<<"Failed to enqueue data into queue."<<endl;
            }
        }
        else if(strcmp(command, "dequeue") == 0)
        {
            temp = queue->dequeue();
            if(temp == NULL)
            {
                cout<<"Failed to dequeue a data from queue.\n";
            }
            else
            {
                cout<<"Dequeue data "<<*temp<<" from queue."<<endl;
            }
        }
    }
}