#include<iostream>
#include<cstdlib>
#include<ctime>
#include <queue>

using namespace std;

class Tree
{
public:
    Tree()
    {
        int j;
        for(j = 0; j < 2000; j ++)
            root[j] = -1;
    }
    int insert(int node)
    {
        int index = 0;
        while(index < 2000 && root[index] != -1)
        {
            if(root[index] < node)
                index = index * 2 + 2;
            else
                index = index * 2 + 1;
        }
        root[index] = node;
    }
    void inorder(int root[], int index)
    {
        if (root[index] == -1)
        {
            return;
        }
        int New = (index*2)+1;
        if(New <=2000)
        {
            inorder(root, New);
        }
        cout<<root[index]<< " ";
        if(New+1 <=2000)
        {
            inorder(root,New+1);
        }
    }
    void preorder(int root[], int index)
    {
        if (root[index] == -1)
        {
            return;
        }
        int New = (index*2)+1;
        cout<<root[index]<< " ";
        if(New <=2000)
        {
            preorder(root, New);
        }
        if(New+1 <=2000)
        {
            preorder(root,New+1);
        }
    }
    void postorder(int root[], int index)
    {
        if (root[index] == -1)
        {
            return;
        }
        int New = (index*2)+1;

        if(New <=2000)
        {
            postorder(root, New);
        }
        if(New+1 <=2000)
        {
            postorder(root,New+1);
        }
        cout<<root[index]<< " ";
    }
    void levelorder()
    {
        if (root[0] == -1)
        {
            return;
        }

        queue<int> q;
        q.push(0);
        while(!q.empty())
        {
            int CurrentIndex = q.front();
            cout<<root[CurrentIndex]<<" ";

            if(root[(CurrentIndex*2)+1] != -1 && (CurrentIndex*2)+1 <=2000 )
            {
                q.push((CurrentIndex*2)+1);
            }
            if(root[(CurrentIndex*2)+2] != -1 && (CurrentIndex*2)+2 <=2000)
            {
                q.push((CurrentIndex*2)+2);
            }
            q.pop();
        }


    }
    int *getRoot()
    {
        return root;
    }
private:
    int root[2000];
};

int main()
{
    Tree *tree = new Tree();
    int j, node;
    srand(time(NULL));
    for(j = 0; j < 10; j ++)
    {
        node = j+1;
        tree->insert(node);
    }
    tree->inorder(tree->getRoot(), 0);
    cout<<"\n";
    tree->preorder(tree->getRoot(), 0);
    cout<<"\n";

    tree->postorder(tree->getRoot(), 0);
    cout<<"\n";
    tree->levelorder();
    cout<<"\n";
}