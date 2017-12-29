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
   int i,j;
   for(i = 0; i <rows; ++i)
   {
      for(j = 0; j <cols; ++j)
      {
         newMaze->maze[i][j]=readInt(fp);
      }
   }
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
   int notFinished=0;
   while(!notFinished)	//start loop
   {
   	//if start is finish
      if (maze->finishX == maze->startX && maze->finishY == maze->startY)
         notFinished = 1;
      else{//start stepping
         notFinished = step(maze, maze->startX, maze->startY);
         if (notFinished==-1){
            printf("NO SOLUTION\n");
            return;
         }
      }
   }
   printf("SUCCESSFUL CASE\n");
}
	//stepping algorithm
static int step(Maze maze, int row, int column)
{
   int i,j,successful;
   if (getVisit(maze, row, column)==FINISH){
      return 1;
   }
   if (getVisit(maze, row, column)!=FINISH && getVisit(maze, row, column)!=START)
	setVisit(maze, row, column,GOOD_PATH);
   if (getCellHasTop(maze,row,column)==0){
      if (getVisit(maze,row-1,column)==FINISH){
         return 1;
      }
      if (getVisit(maze,row-1,column)==UNVISITED){
         if (getVisit(maze,row,column)!=START){
            setVisit(maze,row,column,GOOD_PATH);
         }
         successful=step(maze,row-1,column);
         if (successful){
            return 1;
         }			
         if (!successful){
            if (getVisit(maze,row,column)==START){
               return -1;
            }
         }
      }
   }
   if (getCellHasRight(maze,row,column)==0){
      if (getVisit(maze,row,column+1)==FINISH){
         return 1;
      }
      if (getVisit(maze,row,column+1)==UNVISITED){
         if (getVisit(maze,row,column)!=START){
            setVisit(maze,row,column,GOOD_PATH);
         }
         successful=step(maze,row,column+1);
         if (successful){
            return 1;
         }		
         if (!successful){
            if (getVisit(maze,row,column)==START){
               return -1;
            }
         }
      }
   }
   if (getCellHasBottom(maze,row,column)==0){
      if (getVisit(maze,row+1,column)==FINISH){
         return 1;
      }
      if (getVisit(maze,row+1,column)==UNVISITED){
         if (getVisit(maze,row,column)!=START){
            setVisit(maze,row,column,GOOD_PATH);
         }
         successful=step(maze,row+1,column);
         if (successful){
            return 1;
         }
         if (!successful){
            if (getVisit(maze,row,column)==START){
               return -1;
            }
         }
      }
   }
   if (getCellHasLeft(maze,row,column)==0){
      if (getVisit(maze,row,column-1)==FINISH){
         return 1;
      }
      if (getVisit(maze,row,column-1)==UNVISITED){
         if (getVisit(maze,row,column)!=START){
            setVisit(maze,row,column,GOOD_PATH);
         }
         successful=step(maze,row,column-1);
         if (successful){
            return 1;
         }
         if (!successful){
	    if (getVisit(maze,row,column)==START){
               return -1;
            }
         }
      }
   }
   if (getVisit(maze,row,column)!=START && getVisit(maze,row,column)!=FINISH)
   {
      setVisit(maze,row,column,BAD_PATH);
   }
   return 0;
}

//this function handles allocating memory for the 2D arrays
static Maze createMaze(int rows, int columns)
{
   Maze newMaze = malloc(sizeof *newMaze);
   newMaze->rows = rows;
   newMaze->cols = columns;
   newMaze->maze=malloc(sizeof (int*) * rows);
   int i;
   for (i=0;i<rows;++i){
      newMaze->maze[i]=malloc(sizeof newMaze->maze[i] * columns);
   }
   newMaze->visits=malloc(sizeof (char*) * rows);
   for (i=0;i<rows;++i){
      newMaze->visits[i]=malloc(sizeof newMaze->visits[i] * columns);
   }
   return newMaze;
}

//this function handles initializing the values in the visits array
static void initializePath(Maze newMaze, FILE *fp)
{	
   newMaze->startX=readInt(fp);
   newMaze->startY=readInt(fp);
   newMaze->finishX=readInt(fp);
   newMaze->finishY=readInt(fp);	
   int i,j;
   for(i = 0; i < newMaze->rows; ++i)
   {
      for(j = 0; j < newMaze->cols; ++j)
      {
         newMaze->visits[i][j]=UNVISITED;
      }
   }
   newMaze->visits[newMaze->startX][newMaze->startY]=START;
   newMaze->visits[newMaze->finishX][newMaze->finishY]=FINISH;
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
   int i;
   for (i=0;i<maze->rows;++i){
      free(maze->maze[i]);
   }
   free(maze->maze);
   for (i=0;i<maze->rows;++i){
      free(maze->visits[i]);
   }
   free(maze->visits);
}
