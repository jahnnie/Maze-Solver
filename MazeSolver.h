#ifndef __MazeSolver_h__
#define __MazeSolver_h__
#include <string>

using namespace std;

struct Node{
	int key;
	char value;
	Node* right;
	Node* left;
	Node* top;
	Node* bot;
};

void generate_all_paths(Node* n, char* prev, int len);
Node** makeMaze(char maze[15][15]);
void linkMaze(Node** nodeList);
void textToMaze(char fifteener[15][15]);
bool isOver(Node** nodeList);

#endif