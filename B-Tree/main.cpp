#include <iostream>
#include <stdlib.h>

// Defines the max of 4 for the non-leaf nodes
// Defines the min of 2 for the non-leaf nodes
#define MAX 5
#define MIN 3

// create the structure of each b-tree node
struct treeNode {
    // each node has this structure
	int m[MAX + 1];
	int counter;
	treeNode *link[MAX + 1];
};

// identify the tree root that will be at the root of the tree
treeNode *root;


// creating a new Node -for each individual element-
treeNode * createNode(int m, treeNode *child){
    // each root will loop through this
	treeNode *newNode = new treeNode;
	newNode -> m[1] = m;
	newNode -> counter = 1;
	newNode -> link[0] = root;
	newNode -> link[1] = child;
	return newNode;
    // sends the new node to the function
}
	
// inserts the value into its place in the node
// makes sure values are in order in the node
void insertinNode(int m, int location, treeNode *node, treeNode *child){
    // this will insert the node into its place
    // each node will likey not remain in the same place throughout the durration of the program
	int count = node -> counter;
    // loop whle the theres still space
	while (count > location) {
		node->m[count + 1] = node -> m[count];
        node->link[count + 1] = node -> link[count];
        count--;
	}
	node -> m[count + 1] = m;
    node -> link[count + 1] = child;
    node -> counter++;
}


// this function will transfer the node to another value 
// this will be called when the max nodes of a value is reached
void transferNode(int m, int *ptrm, int location, treeNode *node, treeNode *child, treeNode **newNode){
	// this splits the node when the btree has to many
    // max is 5 and min is 3
    int mid;
	int temp;

    // assigns the mid a value
	if (location > MIN){
		mid = MIN + 1;
	}
	else{
		mid = MIN;
	}
    // gets a new node 
	*newNode = new treeNode;
	temp = mid + 1;
    // loops until the max is reached
	while ( MAX >= temp ){
		(*newNode)->m[temp - mid] = node -> m[temp];
        (*newNode)->link[temp - mid] = node -> link[temp];
        temp++;
	}
    // gives the counter a value
	node -> counter = mid;
	(*newNode) -> counter = MAX - mid;

    // ensures the min is reached
	if (MIN >= location){
		insertinNode(m, location, node, child);
	}
	else {
		insertinNode(m, location - mid, *newNode, child);
	}
    // counter is there to check for space
	*ptrm = node -> m[node -> counter];
	(*newNode) -> link[0] = node -> link [node -> counter];
	node -> counter--;
}


// places the value of the element into the node
int nodeValue(int m, int *ptrm, treeNode *node, treeNode **child) {
    // the function returns the node value to the insert function
	int location;
    // assigned values if no node is found
	if(!node){
		*ptrm = m;
		*child = NULL;
		return 1;
	}
    // sets the location
	if ( node -> m[1] > m ){
		location = 0;
	}
	else {
		for ( location = node -> counter; ( node -> m[location] > m && location > 1 ); location -- );			
	}
    // ensures there is still space, if not then the node is split
	if (nodeValue(m, ptrm, node -> link[location], child)) {
		if (node -> counter < MAX){
			insertinNode(*ptrm, location, node, *child);
		}
		else {
			transferNode( *ptrm, ptrm, location, node, *child, child);
			return 1;
		}
	}
	return 0;
}	

// insert the value into the actual tree
void insertinTree(int m){
    // puts the values of the randKeys into the tree
	int value;
	int insert;
    treeNode *child;
    value = nodeValue(m, &insert, root, &child);
    // gets the node for each value
    if (value)
        root = createNode(insert, child);
}

// looks for element in the tree
// if element is there, it prints it
/*void nrangePrint(int m, int *location, treeNode *current) {
	
	if(!current){
		std::cout << "wtf" << std::endl;
		return;
	}
	if ( current -> m[1] > m){
		*location = 0;
		std::cout << "here" << std::endl;
	}
	else {
		//std::cout << "wtf1" << std::endl;
		for (*location = current -> counter;
			(m < current -> m[*location] && *location > 1); (*location)--);
		if ( m == current -> m[*location] ){
			std::cout << "wtf2" << std::endl;
			std::cout << m <<" ";
			return;
		}
	}
	nrangePrint(m, location, current -> link[*location]);
	return;
} */

// this function will traverse the tree
void traverse(treeNode *current){
    // a counter variable 
	int index;
    // goes through and finds the smallest element and keeps going until the biggest element
    // prints each element that is found
	if (current){
		for (index = 0; index < current ->counter ; index++) {
            traverse(current -> link[index]);
            std::cout<< current -> m[index + 1]<<" ";
        }
        traverse(current -> link[index]);
    }
}



// this will be the runner of the entire program
// it will perform the task of the btree as explained in the assignment
int main() {
	// declare the variable the will be used for the user input of the value of N randon int keys
	int N;
	std::cout << "How many random integer keys would you like in your B-tree? " << std::endl;
	// store the input
	std::cin >> N;

	// ensure the input of N is greater than or equal to the value 400
	while ( N < 399 ){
			std::cout << "The value you entered was less than 400, please enter a value greater than 400. " << std::endl;
			std::cout << "How many random integer keys would you like in your B-tree? " << std::endl;
			// store the input
			std::cin >> N;}

//	std::cout << N << std::endl;
	// create an array to store the random ints and declare its size
	int randArray[N];
	// create a variable that gives the max value for each int in the array
	// the plus 1 is there to make sure the N*3 value can be included
	int randIntMax = 3*N+1;
	//std::cout << randIntMax << std::endl;

	int findbtwnRange = 2*N;

	//std::cout << findbtwnRange << std::endl;
	// for loop that goes through each spot in the array and gives it a value
	for ( int i = 0; i < N; i++){
			// create a int and boolean that will be used to check if the value is already in the array or not.
			int x;
			bool check;

			// create a do while loop that will loop through the array to ensure a value is not being repeated
			do {
					// make x equal to the random value
					// set the bool as true
					x = rand() % randIntMax;
					check = true;

					// for loop and if statement that checks if value is already in array
					for (int j = 0 ; j < i ; j++)
							if ( x == randArray[j]){
							// set the bool to false since the value is already in the array
							check = false;
							break;}} // end if and do

			// while look that keeps going until a new value is found
			while (!check);
					// store the value in the array
					randArray[i] = x;} // end for loop
		  
	// prints each individual element in the array for testing
//	std::cout << "\n Element " << std::endl;
	for (int i = 0 ; i < N; i++){
		//std::cout << " " << randArray[i];
		insertinTree(randArray[i]);
//		nrangePrint(randArray[i], &i, root);
	}
	std::cout << "\nThe following keys are all of the random keys generated between 0 and 3N that appear in the B-Tree:" << std::endl;	
	traverse(root);
	std::cout << " \n\nThe following keys are all of the random keys in the range of N and 2N that appear in the B-Tree:" << std::endl;	
	for (int j = 0; j < N; j++){
		if ((randArray[j] <= findbtwnRange) && (randArray[j] >= N)){
            // tried my hardest to get it to work through the nrangePrint function but I couldnt get it working
            // prints through the array.
			std::cout << randArray[j] << " ";
		}
	}
	
	std::cout << "\n";



// end of the main function
return 0;}





