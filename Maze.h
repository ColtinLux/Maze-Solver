/* File: Maze.h
    This file contains the specification for a Maze class.
    The Maze is stored as a two-dimensional character array
    in which each character has the following meaning:

        # - wall
        o - starting position
        X - goal position
        . - open space
        * - visited

    The position of start is available with public
    member functions. Non-start positions can only be explored
    after a vertically or horizontally adjacent position has
    already been explored.
*/


#ifndef MAZE_H
#define MAZE_H

#include <string>
#include <iostream>

using namespace std;

class Maze
{
    private:
        char **mazeArray; //our maze representation

        int startc;     //The column of the starting positions
        int startr;     //The row of the starting positions
        int finishc;    //The column of the goal
        int finishr;    //The row of the goal
        int width;      //The number of columns in the map
        int height;     //The number of rows in the map

    public:
        Maze(string);   //constructor
        ~Maze();        //destructor
        void display(); //display the maze - unexplored represented by ?
        char explore(int,int); //for exploring a particular positions
        void setVisited(int, int);//set position as visited (*)

        //accessor member functions
        int getWidth(){return width;}
        int getHeight(){return height;}
        int getStartRow(){return startr;}
        int getStartCol(){return startc;}
        int getEndRow(){return finishr;}
        int getEndCol(){return finishc;}
};

#endif // MAZE_H