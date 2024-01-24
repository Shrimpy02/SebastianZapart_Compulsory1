#pragma once

// C++ Components
#include <vector>
#include <algorithm>

// Namespaces
using namespace std;

class AssignmentOne
{
public:
	// ------------ Global Variables -------------

private:
	// ------------ Local Variables -------------

	const float defLow = -1;
	const float defHigh = 4;
	const float resolution = 0.5;

	float lastY = 0;

	struct Vertex
	{
		float x, y, z;
		float r, g, b;
	};

	vector<Vertex*> funcVertices;

public:
	// ------------ Global Functions -------------
	AssignmentOne(){}

	void GenerateVertices(bool _shouldWriteToConsole = false)
	{
		// Generates and pushes vertices into storage vector with function values
		for (float i = defLow; i <= defHigh; i += resolution)
		{
			if (_shouldWriteToConsole)
			{
				// Prints function values for f(x) = y for each value.
				cout << "f(" << i << ") = " << Function(i) << endl;
			}
			
			funcVertices.push_back(CreateVertex(i, Function(i), 0, resolution, calcG(Function(i)), 0));
		}
	}

	void WriteVerticesToFile(int _numVertexVariables, const char* fileName)
	{
		// takes the funcVertices vector and writes its values into a file.
		// Opens / creates the output file
		ofstream outputFile(fileName);

		if (outputFile.is_open()) {
			// writes the first line, witch is the number of lines in total
			outputFile << funcVertices.size() << "\n";
			// Writes the second line, witch is the number of vertex variables
			outputFile << _numVertexVariables << "\n";

			// Loops through all vertices generated and writes them their own line
			for (auto i = 0; i < funcVertices.size(); i++)
			{
				// There is one rule when writing to file,
				// each number must be followed by a ',' to indicate the number has ended.
				outputFile << "(" << funcVertices[i]->x << ", "
				<< funcVertices[i]->y << ", "
				<< funcVertices[i]->z << ",) "
				<< funcVertices[i]->r << ", "
				<< funcVertices[i]->g << ", "
				<< funcVertices[i]->b << ",\n";
			}
			// closes file when finished
			outputFile.close();
		}
		else {
			cerr << "Error opening file - Assignment 1";
		}
	}

private:
	// ------------ Local Functions -------------

	float Function(float x)
	{
		return x * x * x - 4 * x * x + 2 * x + 2;
	}

	float calcG(float _t)
	{
		// Calculates the deltaX
		float currentY = (float)_t;
		float deltaY = currentY - lastY;
		lastY = currentY;
		deltaY = abs(deltaY);

		// Restricts delta values between 5 and 0
		if (deltaY > 5)
			deltaY = 5;

		if (deltaY < 0.001)
			deltaY = 0;

		// returns the color red based on the delta value
		// divided by 5 for a value between 0 and 1. 
		return deltaY / 5;
	}

	Vertex* CreateVertex(float _x, float _y, float _z = 0.0, float _r = 0, float _g = 0, float _b = 0)
	{
		Vertex* newVertex = new Vertex();
		newVertex->x = _x;
		newVertex->y = _y;
		newVertex->z = _z;
		newVertex->r = _r;
		newVertex->g = _g;
		newVertex->b = _b;
		return newVertex;
	}

public:
	// ------------ Getters and Setters -------------

	
};
