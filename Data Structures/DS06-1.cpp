#include<iostream>
#include<cstdlib>
#include<ctime>

#define SIZE 10

using namespace std;

class Node
{
public:
	Node(): Node(0, 0)
	{
	}
	Node(int r, int c)
	{
		row = r;
		col = c;
	}
	int getRow() const { return row; }
	int getCol() const { return col; }
	int getData() const {return data;}
	void setRow(int r)
	{
		if(r >= 0 && r < SIZE)
			row = r;
	}
	void setCol(int c)
	{
		if(c >= 0 && c < SIZE)
			col = c;
	}

	void setData(int d){
		if(d >= 0 && d<= 1) data = d;
	}
private:
	int col, row, data;
};

class List
{
public:
	List()
	{
		top = 0;
	}

	void addElement(int r, int c)
	{
		if((top != (SIZE  * SIZE)-1)){
			data[top].setRow(r);
			data[top].setCol(c);
			top++;
		}
	}

	Node *removeElement()
	{
		if (top==0)
			return NULL;
		top--;

		Node * c = new Node(data[top]);
		return c;
	}

	void printList()
	{
		int j;
		for(j = 0;j < top;j ++)
		{
			cout<<"("<<data[j].getRow() <<", "<<data[j].getCol()<<")"<<endl;
		}
	}
private:
	Node data[SIZE * SIZE];
	int top;
};

class Maze
{
public:
	Maze()
	{
		initMaze(SIZE);
	}

	void initMaze(int s)
	{
		srand(time(NULL));
        maze = new Node*[s];
        for(int i = 0;i<s;i++){
            maze[i] = new Node[s];
        }

		for(int i = 0;i < s;i++){
			for(int j = 0;j<s;j++){
				if((i == 0 && j==0) || (i == s-1 && j == s-1)){
					maze[i][j].setCol(j);
					maze[i][j].setRow(i);
					maze[i][j].setData(0);
				}else{
					maze[i][j].setCol(j);
					maze[i][j].setRow(i);
					int r = rand()%s;
					if(r >=2){
						maze[i][j].setData(0);
					}else{
						maze[i][j].setData(1);
					}
				}

			}
		}
	}

	List *getPath(int Row,int Col)
	{
		static List * c = new List();
		static bool found = false;
		if(Row == SIZE-1 && Col == SIZE-1){
			c->addElement(Row,Col);
			found = true;
		}
		if(found){
			return c;
		}
		if ((Row < 0 || Row >= SIZE) || (Col < 0 || Col >=SIZE))
			return c;

		if(maze[Row][Col].getData() == 0){

			c->addElement(Row,Col);
			maze[Row][Col].setData(1);
			getPath(Row+1,Col);
			getPath(Row,Col+1);
			getPath(Row - 1,Col);
			getPath(Row,Col-1);

			if(!found){
				c->removeElement();
			}

		}

		return c;
	}
	void printMaze()
	{
		int i, j;

		for(i = 0;i < SIZE;i ++)
		{
			for(j = 0;j < SIZE; j++)
			{
				if(maze[i][j].getData() == 0)
					cout<<" ";
				else if(maze[i][j].getData() == 1)
					cout<<"*";
			}
			cout<<"\n";
		}
	}
private:
	Node **maze;
};

int main()
{
	Maze *maze = new Maze();
	maze->printMaze();

	maze->getPath(0,0)->printList();

}