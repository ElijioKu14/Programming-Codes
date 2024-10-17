#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

#define SIZE 10
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

class Grid
{
public:
    Grid() : Grid(0)
    {
    }
    Grid(int s)
    {
        state = s;
        dir[UP] = NULL;
        dir[DOWN] = NULL;
        dir[LEFT] = NULL;
        dir[RIGHT] = NULL;
    }
    Grid* getDir(int d) const
    {
        return dir[d];
    }
    int getState() const
    {
        return state;
    }
    void setDir(int d, Grid* g)
    {
        dir[d] = g;
    }
    void setState(int s)
    {
        state = s;
    }
private:
    Grid* dir[4];
    int state;
};

class List
{
public:
    List()
    {
        top = 0;
    }
    void addElement(Grid* g)
    {
        data[top] = g;
        top++;
    }
    Grid* removeElement()
    {
        if (!top)
        {
            return NULL;
        }
        Grid* removed = data[top - 1];
        top--;
        return removed;
    }
    void printPath() const
    {
        int i;
        for (i = 1; i < top; i++)
        {
            if (data[i] == data[i - 1]->getDir(UP))
            {
                cout << "UP\n";
            }
            else if (data[i] == data[i - 1]->getDir(DOWN))
            {
                cout << "DOWN\n";
            }
            else if (data[i] == data[i - 1]->getDir(LEFT))
            {
                cout << "LEFT\n";
            }
            else if (data[i] == data[i - 1]->getDir(RIGHT))
            {
                cout << "RIGHT\n";
            }
        }
    }
private:
    Grid* data[SIZE * SIZE];
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
        int fullSize = s * s;
        maze = new Grid[fullSize];
        for (int i = 0; i < fullSize * 0.2; i++)
        {
            int randomWall = rand() % fullSize;
            while (maze[randomWall].getState() == 1 || randomWall == 0 || randomWall == fullSize - 1)
            {
                randomWall = rand() % fullSize;
            }
            maze[randomWall].setState(1);
        }

        //point Grid pointers to neighbours
        for (int i = 0; i < fullSize; i++)
        {
            int row = i / s;
            int col = i % s;

            //set UP
            if (row > 0)
            {
                maze[i].setDir(UP, &maze[(row - 1) * s + (col)]);
            }
            //set DOWN
            if (row < s - 1)
            {
                maze[i].setDir(DOWN, &maze[(row + 1) * s + (col)]);
            }
            //SET RIGHT
            if (col < s - 1)
            {
                maze[i].setDir(RIGHT, &maze[(row)*s + (col + 1)]);
            }
            //SET LEFT
            if (col > 0)
            {
                maze[i].setDir(LEFT, &maze[(row)*s + (col - 1)]);
            }
        }
    }
    /*
    function getPath
    This function will find a path between start point and finish point.
    Return a list content the path information inside.
    If there is no path between two point then the list will be empty.
    */
    List* getPath()
    {
        List* path = new List();
        bool found = findPath(path, &maze[0]);
        return (found) ? path : NULL;
    }

    bool findPath(List *path, Grid *m)
    {
        static bool found = false;

        if (m == &maze[(SIZE * SIZE) - 1])
        {
            path->addElement(m);
            found = true;
            return true;
        }

        bool up = (m->getDir(UP)) ? true : false;
        bool down = (m->getDir(DOWN)) ? true : false;
        bool left = (m->getDir(LEFT)) ? true : false;
        bool right = (m->getDir(RIGHT)) ? true : false;

        m->setState(2);

        if (!found && down && (m->getDir(DOWN)->getState() == 0))
        {
            path->addElement(m);
            //cout << "down ";
            findPath(path, m->getDir(DOWN));
        }

        if (!found && right && (m->getDir(RIGHT)->getState() == 0))
        {
            //cout << "right ";
            path->addElement(m);
            findPath(path, m->getDir(RIGHT));
        }

        if (!found && up && (m->getDir(UP)->getState() == 0))
        {
            //cout << "up ";
            path->addElement(m);
            findPath(path, m->getDir(UP));
        }

        if (!found && left && (m->getDir(LEFT)->getState() == 0))
        {
            //cout << "left ";
            path->addElement(m);
            findPath(path, m->getDir(LEFT));
        }

        if (!found)
        {
            path->removeElement();
        }

        return found;

    }

    void printMaze() const
    {
        Grid* j = maze, * k;
        while (j != NULL)
        {
            k = j;
            while (k != NULL)
            {
                cout << k->getState()<< " ";
                k = k->getDir(RIGHT);
            }
            cout << endl;
            j = j->getDir(DOWN);
        }
    }
private:
    Grid* maze;
};

int main()
{
    Maze* maze = new Maze();
    maze->printMaze();
    //maze->getPath()->printPath();
    List* list = maze->getPath();
    if (list)
    {
        list->printPath();
    }
    else
    {
        cout << "No path";
    }
}