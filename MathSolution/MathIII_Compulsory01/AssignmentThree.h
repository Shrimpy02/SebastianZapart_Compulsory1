#pragma once

// C++ Components
#include <vector>
#include <algorithm>
#include <iomanip>

// Namespaces
using namespace std;

class AssignmentThree
{
public:
	// ------------ Global Variables -------------

private:
	// ------------ Local Variables -------------

	float defXMin = -10;
	float defXMax = 10;

	float defYMin = -10;
	float defYMax = 10;

	float resolution = 0.5;

	float lastX = 0;
	float lastY = 0;
	float lastZ = 0;

	struct Vertex
	{
		float x, y, z;
		float r, g, b;
	};
	
	vector<Vertex*> Vertices;

public:
	// ------------ Global Functions -------------

	AssignmentThree(){}

	void GenerateVertices()
	{
		for (float x = defXMin; x < defXMax; x += resolution)
		{
			for(float y = defYMin; y < defYMax; y += resolution)
			{

				// Creates first triangle
				// Vertex 1
				float z = twoVariableFunction(x, y);
				Vertices.push_back(CreateVertex(x, y, z, calcR(x), calcG(y), calcB(z)));

				// Vertex 2
				z = twoVariableFunction(x+resolution, y);
				Vertices.push_back(CreateVertex(x + resolution, y, z, calcR(x + resolution), calcG(y), calcB(z)));

				// Vertex 3
				z = twoVariableFunction(x, y + resolution);
				Vertices.push_back(CreateVertex(x, y + resolution, z, calcR(x), calcG(y + resolution), calcB(z)));

				// Creates second triangle
				// Vertex 4
				z = twoVariableFunction(x + resolution, y);
				Vertices.push_back(CreateVertex(x + resolution, y, z, calcR(x + resolution), calcG(y), calcB(z)));

				// Vertex 5
				z = twoVariableFunction(x, y + resolution);
				Vertices.push_back(CreateVertex(x, y + resolution, z, calcR(x), calcG(y + resolution), calcB(z)));

				// Vertex 6
				z = twoVariableFunction(x + resolution, y + resolution);
				Vertices.push_back(CreateVertex(x + resolution, y + resolution, z, calcR(x + resolution), calcG(y + resolution), calcB(z)));
			}
		}
	}

	void WriteVerticesToFile(int _numVertexVariables, const char* fileName)
	{
		// takes the funcVertices vector and writes its values into a file.
		// Opens / creates the output file
		ofstream outputFile(fileName);

		if (outputFile.is_open()) {
			// writes the first line, witch is the number of lines in total
			outputFile << Vertices.size() << "\n";
			// Writes the second line, witch is the number of vertex variables
			outputFile << _numVertexVariables << "\n";

			// Loops through all vertices generated and writes them their own line
			for (auto i = 0; i < Vertices.size(); i++)
			{
				// There is one rule when writing to file,
				// each number must be followed by a ',' to indicate the number has ended.

				outputFile << setprecision(3) << "("
					<< Vertices[i]->x << ", "
					<< Vertices[i]->y << ", "
					<< Vertices[i]->z << ",) "
					<< Vertices[i]->r << ", "
					<< Vertices[i]->g << ", "
					<< Vertices[i]->b << ",\n";
			}

			// closes file when finished
			outputFile.close();
		}
		else {
			cerr << "Error opening file - Assignment 3";
		}
	}

private:
	// ------------ Local Functions -------------

	Vertex* CreateVertex(const float _x, const float _y, const float _z, const float _r, const float _g, const float _b)
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

	float twoVariableFunction(const float x, const float y)
	{
		return sin(x) * cos(y) * ((x + y) / 10);
	}

	float calcR(const float _x)
	{
		// gets the absolute x value
		float r = abs(_x);

		if (r > 10)
			r = 10.f;

		// make sure x is between 10 or 1 for the divide
		if (r < 2.f)
			r = 2.f;

		// returns the color red based on the x value input
		// divided by 10 for a value between 0 and 1. 
		return r / 10;
	}

	float calcG(const float _y)
	{
		// gets the absolute y value
		float g = abs(_y);

		// make sure y is between 10 or 1 for the divide
		if (g > 10)
			g = 10.f;

		if (g < 2.f)
			g = 2.f;

		// returns the color red based on the x value input
		// divided by 10 for a value between 0 and 1. 
		return g / 10;
	}

	float calcB(const float _z)
	{
		// gets the absolute z value * 3 for more depth
		float b = abs(_z*3);

		// make sure z is between 10 or 1 for the divide
		if (b > 10)
			b = 10.f;

		if (b < 1.f)
			b = 1.f;

		// returns the color red based on the x value input
		// divided by 10 for a value between 0 and 1. 
		return b / 10;
	}

public:
	// ------------ Getters and Setters -------------


};
