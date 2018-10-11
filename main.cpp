//author: Coltin Lux
//date: Nov 3, 2014
//description:  This program searches maze for a solution by either using the stack or the queue
// 10/10 uses stack and queue successfully to search maze for solution

#include <iostream>
#include "Maze.h"
#include <queue>
#include <stack>

using namespace std;

struct Location
{
    int row;
    int col;
};

/* 
    Entry point of the program. Simply gets the filename from the user and then
    launches the one-player game. 
*/
int main()
{
    string fileName;
    cout << "Enter a maze file name: ";
    cin >> fileName;

    Maze m(fileName);
    m.display();
    cout << "Starting in " << m.getStartRow() << ", " << m.getStartCol() << endl;

    int selection;
    cout << "How would you like to explore the maze?" << endl;
    cout << "0: Exit" << endl;
    cout << "1: Stack" << endl;
    cout << "2: Queue" << endl;
    cout << "What would you like to do? ";
    cin >> selection;

    if (selection == 0)
    {
        exit(0);
    }
    else if (selection == 1)
    {
        stack<Location> st;

        bool endReached = false;

        Location loc;

        loc.row = m.getStartRow();
        loc.col = m.getStartCol();

        st.push(loc);

        while(endReached == false && !st.empty())
        {
            Location l;
            l = st.top();
            st.pop();
            if(l.row == m.getEndRow() && l.col == m.getEndCol())
            {
                cout << "There is a solution! YAY! :)" << endl;
                endReached = true;
            }
            else if(m.explore(l.row, l.col) == '.' || m.explore(l.row, l.col) == 'o')
            {
                //go up, down, left and right
                Location left;
                left.row = l.row;
                left.col = l.col - 1;
                st.push(left);

                Location right;
                right.row = l.row;
                right.col = l.col + 1;
                st.push(right);

                Location up;
                up.row = l.row + 1;
                up.col = l.col;
                st.push(up);

                Location down;
                down.row = l.row - 1;
                down.col = l.col;
                st.push(down);

                //set position l as visited
                m.setVisited(l.row, l.col);
                m.display();
            }
            else if(l.row != m.getEndRow() && l.col != m.getEndCol())
            {
                if(st.empty())
                {
                    cout << "There is no solution." << endl;
                }
            }
        }
    }

    else if (selection == 2)
    {
        queue<Location> que;

        bool endReached = false;

        Location loc;

        loc.row = m.getStartRow();
        loc.col = m.getStartCol();

        que.push(loc);

        while(endReached == false && !que.empty())
        {
            Location l;
            l = que.front();
            que.pop();
            if(l.row == m.getEndRow() && l.col == m.getEndCol())
            {
                cout << "There is a solution! YAY! :)" << endl;
                endReached = true;
            }
            else if(m.explore(l.row, l.col) == '.' || m.explore(l.row, l.col) == 'o')
            {
                //go up, down, left and right
                Location left;
                left.row = l.row;
                left.col = l.col - 1;
                que.push(left);

                Location right;
                right.row = l.row;
                right.col = l.col + 1;
                que.push(right);

                Location up;
                up.row = l.row + 1;
                up.col = l.col;
                que.push(up);

                Location down;
                down.row = l.row - 1;
                down.col = l.col;
                que.push(down);

                //set position l as visited
                m.setVisited(l.row, l.col);
                m.display();
            }
            else if(l.row != m.getEndRow() && l.col != m.getEndCol())
            {
                if(que.empty())
                {
                    cout << "There is no solution." << endl;
                }
            }
        }
    }

    //~Maze;
    return 0;
}