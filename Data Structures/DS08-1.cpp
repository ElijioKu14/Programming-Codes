#include<iostream>
#include<cstdlib>
#include<ctime>
#include<queue>

using namespace std;

class Node
{
public:
    int level, data;
    Node *left, *right;
};

class Tree
{
public:
    Tree()
    {
        root = NULL;
    }
    int insert(Node *n)
    {
        insert(&root, n);
    }
    Node *getRoot()
    {
        return root;
    }

    void inorder(Node *CurrentNode)
    {
        if(CurrentNode == NULL)
            return;
        inorder(CurrentNode->left);
        cout << CurrentNode->data << " ";
        inorder(CurrentNode->right);
    }

    void preorder(Node *CurrentNode)
    {
        if(CurrentNode == NULL)
            return;
        cout << CurrentNode->data << " ";
        preorder(CurrentNode->left);
        preorder(CurrentNode->right);
    }
    void postorder(Node *CurrentNode)
    {
        if(CurrentNode == NULL)
            return;
        postorder(CurrentNode->left);
        postorder(CurrentNode->right);
        cout << CurrentNode->data << " ";

    }
    void levelorder()
    {
        Node *temp = root;
        if(root == NULL)
            return;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            Node *CurrentNode = q.front();
            cout << CurrentNode->data << " ";
            if(CurrentNode->left != NULL)
            {
                q.push(CurrentNode->left);
            }
            if(CurrentNode-> right != NULL)
            {
                q.push(CurrentNode->right);
            }
            q.pop();
        }
    }

private:
    Node *root;
    void insert(struct Node **r, struct Node *n)
    {
        if(*r == NULL)
            *r = n;
        else if(n->data > (*r)->data)
            insert(&((*r)->right), n);
        else
            insert(&((*r)->left), n);
    }
};

int main()
{
    Tree *tree = new Tree();
    Node *node;
    int j;
    srand(time(NULL));
    for(j = 0; j < 10; j ++)
    {
        node = new Node();
        node->data = j+1;
        node->left = NULL;
        node->right = NULL;
        tree->insert(node);
    }
    tree->inorder(tree->getRoot());
    cout<<"\n";
    tree->preorder(tree->getRoot());
    cout<<"\n";
    tree->postorder(tree->getRoot());
    cout<<"\n";
    tree->levelorder();
    cout<<"\n";
}