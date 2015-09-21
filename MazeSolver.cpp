#include <iostream>
#include <fstream>
#include <string>
#include "MazeSolver.h"
#include  "tgmath.h"
using namespace std;

int solutionCounter = 1;
int overCount = 0;
char visited = '_';
Node* nodeList[225];

char testMaze[6][6] = {
	{'#', '#', '#', '#', '#', '#'} , 
	{'S', 'a', '#', '#', 'l', '#'},
	{'#', 'b', 'd', 'p', 'h', 'n'},
	{'#', '#', '#', 'k', '#', '#'},
	{'#', '#', '#', 'j', 'x', 'z'},
	{'#', '#', '#', '#', '#', '#'}
};

char testMaze2[5][5] = {
	{'#', '#', '#', '#', '#'} , 
	{'S', 'a', '#', '#', 'l'},
	{'#', 'b', 'd', 'p', 'h'},
	{'#', '#', '#', 'k', '#'},
	{'#', '#', '#', '#', '#'},
};

char fifteen[15][15]={{0}};

char testMaze1[15][15] = {
	{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#','#'}, 
	{'S', 'a', '#', '#', 'l', '#', '#', '#', '#', '#', '#', '#', '#', '#','#'},
	{'#', 'b', 'd', 'p', 'h', 'n', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'x'},
	{'#', 'q', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#','#'} , 
	{'#', 'r', 's', 't', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#','#'} , 
	{'#', '#', '#', 'u', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#','#'} , 
	{'#', 'x', 'w', 'v', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#','#'} , 
	{'#', 'y', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#','#'} , 
	{'#', 'z', 'n', 'o', 'm', 'a', 'b', 'c', 't', 'w', 'u', 's', 'w', 'm','e'} , 
	{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#','#'} , 
	{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#','#'} , 
	{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#','#'} , 
	{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#','#'} , 
	{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#','#'} , 
	{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#','#'} , 
};
//methods TODO

//Pre-condition: The head of the maze (i.e. starting point) is provided, as well as an array of 
//possible paths, and the length of the paths array
// Post-condition: Path arrays that are maze solutions are printed to console, then return.
void generate_all_paths(Node* n, char* prev, int len){
	n->value = visited;			
	
	if(n->right == NULL){
		cout << "Path " << solutionCounter << ":" << " ";
		for(int i = 0; i < len; i++){
			if(prev[i+1] == '\0')
				cout << prev[i];
			else 
				cout << prev[i] << ","<< " ";
		}
		cout << "\n";
		solutionCounter++;
		return;
	}

	
	if(isOver(nodeList))
		cout << solutionCounter-1<< " total paths" << endl;
	
	if(n->right != NULL && isalpha(n->right->value) && n->right->value != visited){
		//do something
		char newPath[len+1];
		int j=0;;
		while(j<len){
			newPath[j] = prev[j];
			j++;
	}
	newPath[j] = n->right->value;
	int newlen = len+1;
	generate_all_paths(n->right, newPath, newlen);
	}

	if(n->top != NULL && isalpha(n->top->value) && n->top->value != visited){
		//do something
		char newPath1[len+1];
		int k=0;
		while(k < len){
			newPath1[k] = prev[k];
			k++;
	}
	
	newPath1[k] = n->top->value;
	int newlen1 = len+1;
	generate_all_paths(n->top, newPath1, newlen1);
	}
	
	if(n->bot!= NULL && isalpha(n->bot->value) && n->bot->value != visited){
		//do something
		char newPath2[len+1];
		int l=0;
		while(l<len){
			newPath2[l] = prev[l];
			l++;
		}
	newPath2[l] = n->bot->value;
	int newlen2 = len+1;
	generate_all_paths(n->bot, newPath2, newlen2);
	}
	
	if(n->left!= NULL && isalpha(n->left->value) && n->left->value != visited){
		//do something
		char newPath3[len+1];
		int m = 0;
		while(m < len){
			newPath3[m] = prev[m];
			m++;
	}
	newPath3[m] = n->left->value;
	int newlen3 = len+1;
	generate_all_paths(n->left, newPath3, newlen3);
	}
	return;
	
}

//Pre-condition: The maze in the form of a 2D char array is provided
//Post-condition: An array of Node objects is returned, 
//where each node->value contains a char of the maze.
Node** makeMaze(char maze[15][15]){
		//take the char from the index,
		//make a new node
		//set the node value = to char
		//set the node key to some int
		//increment key
		int key = 0;
		
		for(int j = 0; j < 15; j++){
			
			for(int i = 0; i < 15; i++){
			
				Node* n = new Node;
				n->value = maze[j][i];
				n->key = key;
				nodeList[key] = n;
				key++;
			 
				}
		}
				
		return nodeList;
}
//Pre-condition: An array of Node objects is provided.
//Post-condition: Link each Node in the array, setting their left, right, top, and bottom nodes
//to their respective positions in the original maze
//(e.g. the top left node's pointers are as follows: node->left = NULL, node->right = 
//maze[0][1], node->top = NULL, node->bot = maze[1][0]) note: maze variable is not actually used,
//it was simply to serve as an example
void linkMaze(Node** nodes){
	
	for(int i = 0; i < 225; i++){
		if(i ==0){
			nodes[i]->left = NULL;
			nodes[i]->top = NULL;
			nodes[i]->right = nodes[i+1];
			nodes[i]->bot = nodes[i+15];
		}
		
		else if (i == 14){
			nodes[i]->right = NULL;
			nodes[i]->top = NULL;
			nodes[i]->left = nodes[i-1];
			nodes[i]->bot = nodes[i+15];
		}
		
		else if(i < 15){
			nodes[i]->top = NULL;
			nodes[i]->right = nodes[i+1];
			nodes[i]->bot = nodes[i+15];		
			nodes[i]->left = nodes[i-1];			
		}
		
		else if (i == 210){
			nodes[i]->left = NULL;
			nodes[i]->bot = NULL;
			nodes[i]->right = nodes[i+1];
			nodes[i]->top = nodes[i-15];
		}
		else if (i == 224){
			nodes[i]->right = NULL;
			nodes[i]->bot = NULL;
			nodes[i]->left = nodes[i-1];
			nodes[i]->top = nodes[i-15];
		}
		
		
		else if(i % 15 == 0){
			nodes[i]->left = NULL;
			nodes[i]->right = nodes[i+1];
			nodes[i]->bot = nodes[i+15];		
			nodes[i]->top = nodes[i-15];			
		}
		
		else if(i % 15 ==14){
			nodes[i]->right = NULL;
			nodes[i]->left = nodes[i-1];
			nodes[i]->bot = nodes[i+15];		
			nodes[i]->top = nodes[i-15];		
		}
		
		else if(i < 210){
			nodes[i]->right = nodes[i+1];
			nodes[i]->left = nodes[i-1];
			nodes[i]->bot = nodes[i+15];		
			nodes[i]->top = nodes[i-15];		
		}
		
		else if(i < 224){
			nodes[i]->bot = NULL;
			nodes[i]->right = nodes[i+1];
			nodes[i]->left = nodes[i-1];		
			nodes[i]->top = nodes[i-15];	
	}}
}

//Pre-condition: an uninitialized global char array[15][15] is passed, and a .txt file containing a maze
//Post-condition: initialize the argument 2D array to take the values of the .txt file, containing maze data
void textToMaze(char array [15][15]){
	ifstream inFile;
	
	inFile.open("maze.txt");

	if(inFile.is_open()){
		while(!inFile.eof()){
	for(int r = 0; r < 15; r++){
		{
			for(int c=0; c < 15; c++){
				inFile >> array[r][c];
			}
		}
	}}}
	inFile.close();
}

//Pre-condition: the global nodeList that is being updated after every recursive call in generate
//Post-condition: return true if every possible route in the maze has been visited, in order to
//officially end generate_all_paths (it's essentially a helper function)
bool isOver(Node** nList){
	for(int i = 0; i < 225; i++){
		if(nList[i]->value == visited||nList[i]->value == '#')
				overCount++;
	}
	if (overCount == 225)
		return true;
	else
		overCount = 0;
	return false;
}
int main(){
	
textToMaze(fifteen); //convert text file to 2D char array like above
Node** nodeList1 = makeMaze(fifteen); //convert 2D array to nodes
linkMaze(nodeList1);		// link nodes
Node* head = nodeList1[0]->bot; //set the head = to the start

char init[1]; //initialize a char array that contains the initial path {S}
init[0] = head->value; 
generate_all_paths(head, init, 1);
return 0;
}
