#include <stdio.h>
#include <stdlib.h>

#include "scanner.h"
#include "maze.h"

struct maze
{
	int startX, startY;//coordinates for the starting point
	int finishX, finishY; //coordinates for the finish point

	int rows, cols; //the number of rows and columns in the 2D arrays

	int **maze; //holds the encodings
	char **visits; //holds the path
};

//these are the prototypes for our static functions
static Maze createMaze(int rows, int columns);
static void initializePath(Maze newMaze, FILE *fp);
static int step(Maze maze, int row, int column);
static void debugPrint(Maze maze);
static void displayRowTop(Maze maze, int row, int columns);
static void displayRowContent(Maze maze, int row, int columns);
static void displayBottom(Maze maze, int columns);


static int getCellHasTop(Maze maze, int row, int column);
static int getCellHasBottom(Maze maze, int row, int column);
static int getCellHasRight(Maze maze, int row, int column);
static int getCellHasLeft(Maze maze, int row, int column);
static char getVisit(Maze maze, int row, int column);
static void setVisit(Maze maze, int row, int column, char visit);

//will call createMaze to allocate memory and will initialize the 2D arrays
Maze initializeMaze(FILE *fp)
{
	int rows = readInt(fp);
	int cols = readInt(fp);
	
	Maze newMaze = createMaze(rows, cols); //allocates memory
	initializePath(newMaze, fp);//initializes values in the path

	//TODO: INITIALIZE MAZE
	
	//debugPrint(newMaze); //Used for testing initializetion

	return newMaze;
}

//the next 4 functions check if there is a wall on top, bottom, right, or left
static int getCellHasTop(Maze maze, int row, int column)
{
	return maze->maze[row][column] & 1;
}

static int getCellHasBottom(Maze maze, int row, int column)
{
	return maze->maze[row][column] & 4;
}

static int getCellHasRight(Maze maze, int row, int column)
{
	return maze->maze[row][column] & 2;
}

static int getCellHasLeft(Maze maze, int row, int column)
{
	return maze->maze[row][column] & 8;
}

//these two functions will handle updating and getting values from the visits array
//these make for more readable code than accessing the array directly
static char getVisit(Maze maze, int row, int column)
{
	return maze->visits[row][column];
}

static void setVisit(Maze maze, int row, int column, char visit)
{
	maze->visits[row][column] = visit;
}

//takes in a maze and calls step to start backtracking, provides the starting
//point as the first point to visit in the maze
void findPath(Maze maze)
{
	//TODO: MAY NEED TO ALTER THIS FUNCION TO HANDLE SPECIAL CASE
	step(maze, maze->startX, maze->startY);	
}

static int step(Maze maze, int row, int column)
{
	//TODO: FINISH THE BACKTRACKING ALGORITHM
	return 0;
}

//this function handles allocating memory for the 2D arrays
static Maze createMaze(int rows, int columns)
{
	Maze newMaze = malloc(sizeof *newMaze);
	newMaze->rows = rows;
	newMaze->cols = columns;
	
	//TODO: ALLOCATE THE 2D ARRAYS

	return newMaze;
}

//this function handles initializing the values in the visits array
static void initializePath(Maze newMaze, FILE *fp)
{	
	//TODO: INITIALIZE THE VISITS ARRAT. REMEMBER TO USE THE DEFINES IN .h
}

//used only for debugging purposes
static void debugPrint(Maze maze)
{
	int i,j;
	printf("Maze\n");
	for(i = 0; i < maze->rows; ++i)
	{
		for(j = 0; j < maze->cols; ++j)
		{
			printf("%d ", maze->maze[i][j]);
		}
		printf("\n");
	}

	printf("Visits\n");
	for(i = 0; i < maze->rows; ++i)
	{
		for(j = 0; j < maze->cols; ++j)
		{
			printf("%c ", maze->visits[i][j]);
		}
		printf("\n");
	}
}	

//The next four functions handle displaying the maze
void displayMaze(Maze maze)
{
	int i;
	for(i = 0; i < maze->rows; ++i)
	{
		displayRowTop(maze, i, maze->cols);
		displayRowContent(maze, i, maze->cols);
	}
	displayBottom(maze, maze->cols);
}

void displayRowTop(Maze maze, int row, int columns)
{
	int i;
	for(i = 0; i < columns; ++i)
	{
		printf("+");
		if(getCellHasTop(maze, row, i)) //checks if wall is needed
			printf("---");
		else
			printf("   ");
	}
	printf("+\n");
}

void displayRowContent(Maze maze, int row, int columns)
{
	int i;
	for(i = 0; i < columns; ++i)
	{
		if(getCellHasLeft(maze, row, i)) //checks if wall is needed
			printf("|");
		else
			printf(" ");
		printf(" %c ",getVisit(maze,row, i));
	}
	printf("|\n");
}

void displayBottom(Maze maze, int columns)
{
	int i;
	for(i = 0; i < columns; ++i)
	{
		printf("+");
		printf("---");
	}
	printf("+\n");
}

void freeMaze(Maze maze)
{
	//TODO: FREE THE MEMORY FOR THE MAZE
}
