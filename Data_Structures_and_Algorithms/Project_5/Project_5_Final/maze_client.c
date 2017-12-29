#include <stdio.h>

#include "maze.h"

int main(int argc, char **argv)
{
	FILE *fp = fopen(argv[1], "r");
	Maze maze = initializeMaze(fp);
	findPath(maze);
	displayMaze(maze);
	return 0;
}
