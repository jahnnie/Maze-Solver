John Yoo
39296132
m3c9
L0E

Clarence Lam
41436130
f8w8
L0E

Essentially how our program works:

1) given a text file that contains a formatted maze,
	convert it to a 2D char array with 15 rows and 15 columns

2) for each char in that array, 
	we make a node with the node->value
		to the char, then add that to a list of Node objects

3) Then, we have to connect the nodes, like a linked list.
	We drew out a 15X15 grid, then found 9 possible cases
		- each corner had two NULL pointers
		- left edge is divisble by 15
		- right edge's remainder is 14
		- bottom and top have 1 NULL pointer to bot and top respectively
		- everything else in the middle has four pointers
		

4) once the nodes are connected, we pass it into generate_all_paths,
	which finds all solutions!
		- accounts for backtracking, as Nodes already seen are considered "visited"
		
