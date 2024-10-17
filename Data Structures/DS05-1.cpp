#include<iostream>
#include<cstdlib>

using namespace std;

struct Node
{
    Node()
    {
        data = 0;
        next = NULL;
    }
    int data;
    Node *next;
};

class Set
{
public:
    Set()
    {
        element = NULL;
    }

    int addElement(int e)
    {
        Node *temp = new Node;
        temp->data = e;
        temp->next = NULL;

        if(element == NULL)
        {
            element = temp;
        }
        else
        {
            Node *current = element;

            if(temp->data < current->data )
            {
                temp->next=element ;
                element = temp;
            }
            else
            {
                while(current != NULL)
                {
                    if(current->data == temp->data)
                    {
                        break;
                    }

                    if(current->data > temp->data)
                    {
                        temp->next = current;
                        Node *temp2 = element;

                        while(temp2 != NULL)
                        {
                            if(temp2->next == current)
                            {
                                temp->next = temp;
                                break;
                            }
                        }
                        break;
                    }

                    if(current->next == NULL)
                    {
                        current->next=temp;
                        break;
                    }
                    current=current->next;
                }
            }
        }
    }

    Set *unions(const Set *b) const
    {
        Node* current;
        Set *Union = new Set;
        current = element;

        while(current !=NULL)
        {
            Union->addElement(current->data);
            current=current->next;
        }
        current = b->element;

        while(current!=NULL)
        {
            Union->addElement(current->data);
            current = current->next;
        }
        return Union;
    }

    Set *intersections(const Set *b) const
    {


        Node* current;
        Node * temp;
        Set *Intersect = new Set ();

        current = element;

        while(current != NULL)
        {
            temp = b->element;
            while(temp!=NULL)
            {

                if(current->data == temp->data)
                {
                    Intersect->addElement(current->data);

                }
                temp = temp->next;
            }
            current = current->next;
        }
            return Intersect;
    }

    bool equivalent(const Set *b) const
    {
        Node* current = element;
        Node *temp;
        bool Equivalent=false;

        temp = b->element;

        while(current!=NULL)
        {
            if(current->data == temp->data)
            {
                Equivalent = true;
                temp = temp->next;
            }
            else
            {
                Equivalent = false;
                break;

            }
            current = current->next;
        }
        return Equivalent;
    }

    void listAll() const
    {
        Node *current = element;
        while(current != NULL)
        {
            cout<<current->data<<" ";
            current = current->next;
        }
    }
private:
    Node *element;
};

int main()
{
    Set *a = new Set();
    Set *b = new Set();
    Set *c;
    Node *cur;

    a->addElement(1);
    a->addElement(2);
    a->addElement(3);

    //a->listAll();
    b->addElement(1);
    b->addElement(2);
    b->addElement(3);
    b->addElement(5);

    c = a->unions(b);
    c->listAll();
    cout<<endl;
    c = a->intersections(b);
    c->listAll();

    if(a->equivalent(b) == 0)
        cout<<"Not equivalent.\n";
    else
        cout<<"Equivalent!\n";
}