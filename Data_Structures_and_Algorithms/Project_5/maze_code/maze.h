#ifndef MAZE_H
#define MAZE_H

//list of defines for filling the visits matrix
#define UNVISITED ' '
#define START 'S'
#define FINISH 'F'
#define GOOD_PATH 'O'
#define BAD_PATH 'X'

//handle for our maze
typedef struct maze *Maze;

/* Initializes and creates a new maze from file input
 * @param fp input file describing the maze
 * @return a newly created maze
 */
Maze initializeMaze(FILE *fp);

/* finds the path through the maze
 * @param maze the maze to search
 */
void findPath(Maze maze);
/*displays a maze on the console
 * @param maze the maze to display
 */
void displayMaze(Maze maze);

//frees memory for the maze
void freeMaze(Maze maze);

#endif
