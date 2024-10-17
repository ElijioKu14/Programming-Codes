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
		int j, k;
		for(j = 0;j < 20;j ++)
			for(k = 0;k < 4;k ++)
				root[j][k] = -1;
	}
	int insert(int node)
	{
		int f = 0, index = 0;
		while(root[index][0] != -1)
			index ++;
		if(index >= 20)
			return -1;
		if(index == 0)
		{
			root[0][0] = 1;
			root[0][1] = node;
			return 1;
		}
		else
		{
			root[index][0] = 1;
			root[index][1] = node;
			while(1)
			{
				if(root[f][1] < node)
				{
					if(root[f][3] == -1)
					{
						root[f][3] = index;
						return 1;
					}
					else
					{
						f = root[f][3];
					}
				}
				else
				{
					if(root[f][2] == -1)
					{
						root[f][2] = index;
						return 1;
					}
					else
					{
						f = root[f][2];
					}
				}
			}
		}
	}
	void inorder(int row)
	{
		if(root[row][0]!=-1){
			if(root[row][2]!=-1){
                inorder(root[row][2]);
			}
            cout<<root[row][1]<<" ";
            if(root[row][3]!=-1){
                inorder(root[row][3]);
            }
		}
		return;
	}
	void preorder(int row)
	{
	            if(root[row][0]!=-1){
			cout<<root[row][1]<<" ";
			if(root[row][2]!=-1){
                preorder(root[row][2]);
			}
            if(root[row][3]!=-1){
                preorder(root[row][3]);
            }
		}
		return;
	}
	void postorder(int row)
	{
	            if(root[row][0]!=-1){
			if(root[row][2]!=-1){
                    postorder(root[row][2]);
			}
            if(root[row][3]!=-1){
                    postorder(root[row][3]);
            }
            cout<<root[row][1]<<" ";
		}
		return;
	}
	void levelorder()
	{
        queue<int> q;
	    int row = 0;
	    while(root[row][0]!=-1){
            cout<<root[row][1]<<" ";
            if(root[row][2]!=-1){
                    q.push(root[row][2]);
            }
            if(root[row][3]!=-1){
                    q.push(root[row][3]);
            }
            if(q.empty())
                return;
            row = q.front();
            q.pop();
	    }
	}

private:
	int root[20][4];
};

int main()
{
	Tree *tree = new Tree();
	int j, node;
	srand(time(NULL));
	for(j = 0;j < 10;j ++)
	{
		node = j+1;
		tree->insert(node);
	}
	tree->inorder(0);
    cout<<"\n";
	tree->preorder(0);
    cout<<"\n";
	tree->postorder(0);
    cout<<"\n";
	tree->levelorder();
    cout<<"\n";
}