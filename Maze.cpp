/* File: Maze.cpp
    Implements the class specified in Maze.h
*/

#include "Maze.h"
#include <fstream>


/* Constructor
    Parameter: the filename containing the maze to be read in as
    a 2D array. The first line of a maze file contains the number
    of columns and rows respectively. All following lines gives the
    actual 2@ character array, with each line representing a row.

    Nothing is returned. There is console output only when the
    file fails to open.

    This is the only way to create a Maze - there are no other
    constructors, and no other member functions for setting up
    the maze array.
*/
Maze::Maze(string filename)
{
    ifstream in;
    in.open(filename.c_str());

    if(!in.fail())
    {
        //get the width and the height
        in >> width;
        in >> height;

        //allocate enough memory for the 2D array
        //once we do this, the size never changes
        mazeArray = new char*[height];
        //we need to allocate each row separately
        for (int i = 0 ; i < height ; i++)
        {
            mazeArray[i] = new char[width];
        }


        in.get(); //eating a newline

        //nested for loop for stepping through
        //each position in the array
        for(int i = 0; i < height; i++)
        {
            for(int j = 0; j < width; j++)
            {
                mazeArray[i][j] = (char)in.get(); //gets one character

                //check if this is the origin or the goal and save
                //the info to our member variables
                if( mazeArray[i][j] == 'o' )
                {
                    startc = j;
                    startr = i;
                }
                else if(mazeArray[i][j] == 'X')
                {
                    finishc = j;
                    finishr = i;
                }

            }
            //eat the newline character at the end of the row
            in.get();
        }
    }
    else  //the file failed to open
    {
        cerr << "couldn't open maze file" << endl;
        exit(1);
    }
    in.close();

}

/* Destructor
    The mazeArray and visited 2D arrays were allocated dynamically,
    so this simply goes row by row, deleting each array

    No parameters or return. Nothing input or output.
*/
Maze::~Maze()
{
    for (int i = 0 ; i < height ; i++)
    {
        delete [] mazeArray[i];
    }
    delete [] mazeArray;
}

/* Takes a boolean flag fog as a parameter. If fog is true,
    this function displays the maze map to the console with
    unexplored spaces represented by question marks (?).
    Otherwise, the full map is displayed without question marks.

    Nothing returned. No user input.

    This is a private, auxilliary function meant to be called
    internally for the two different versions of display.
*/
void Maze::display()
{
    cout << endl; //putting in some whitespace
    //traverse the 2D array and print each value
    int i, j;
    for(i = 0; i < height; i++)
    {
        for(j = 0; j < width; j++)
        {     
            cout << mazeArray[i][j];
        }
        cout << endl;
    }
    cout << endl;
}



/*
    Parameters: the row and column of the maze to explore
    Return: the character stored in the array at the position
        indicated by the parameters. This tells the caller what
        kind of spot they've found:

        # - wall
        o - starting position
        X - goal position
        . - open space
        * - visited

        There are also one "error" cases which output an error message
        and give a special sentinal return value.

        ? - the move is out-of-bounds - i.e. the parameter coordinates
            are not on the map


    After this function is called in a non-error case on the given position
    it will be considered to have been explored, if the location was an open space (.)
    the array will be updated indicate the location was visited (*).
*/
char Maze::explore(int row, int col)
{
    //checks if the parameters are within the map limites
    if( row >= height || col >= width )
    {
        cout << "That move is out of bounds" << endl;
        return 'X'; //an error return value
    }


    
    return mazeArray[row][col]; //return what's in this position
}

/*
    Parameters: the row and column of the maze
    Return: null
 
    sets the row and column position of the mazeArray to be *
    denoting that the spot has been visited.
    occurs only if the spot was free
 */
void Maze::setVisited(int row, int col)
{
    if (mazeArray[row][col] == '.' || mazeArray[row][col] == 'o')
    { 
        mazeArray[row][col] = '*';   //we've now visited this space
    }
}