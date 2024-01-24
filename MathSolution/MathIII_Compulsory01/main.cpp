
// C++ Components 
#include <iostream>
#include <fstream>
#include <chrono>

// Classes
#include "AssignmentOne.h"
#include "AssignmentTwo.h"
#include "AssignmentThree.h"

// Name spaces
using namespace std;
using namespace std::chrono;

int main()
{
	// Pointers to class objects
	shared_ptr<AssignmentOne> AOne = make_shared<AssignmentOne>();
	shared_ptr<AssignmentTwo> ATwo = make_shared<AssignmentTwo>();
	shared_ptr<AssignmentThree> AThree = make_shared<AssignmentThree>();

	// Assignment 1 ------------------
	cout << "Assignment 1: " << endl;

	AOne->GenerateVertices();
	AOne->WriteVerticesToFile(6, "Assignment1VertexFile.txt");

	cout << endl;
	cout << endl;

	// Assignment 2 ------------------
	cout << "Assignment 2: " << endl;

	ATwo->GenerateVertices();
	ATwo->WriteVerticesToFile(6, "Assignment2VertexFile.txt");

	cout << endl;
	cout << endl;

	// Assignment 3 ------------------
	cout << "Assignment 3: " << endl;

	AThree->GenerateVertices();
	AThree->WriteVerticesToFile(6, "Assignment3VertexFile.txt");

	cout << endl;
	cout << endl;

	return 0;
}
