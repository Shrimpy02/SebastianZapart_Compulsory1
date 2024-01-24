#pragma once

// C++ Components
#include <vector>
#include <iomanip>

// Custom definitions
# define M_PI           3.14159265358979323846

// Namespaces
using namespace std;

class AssignmentTwo
{
public:
	// ------------ Global Variables -------------


private:
	// ------------ Local Variables -------------

	float defMin = 0;
	float defMax = 50;
	float resolution = 1;

	float lastX = 1;
	float lastY = 1;
	float lastZ = 1;

	struct Vertex
	{
		float x, y, z;
		float r, g, b;
	};

	vector<Vertex*> funcVertices;
	
public:
	// ------------ Global Functions -------------
	AssignmentTwo() {}

	void GenerateVertices(bool _shouldWriteToConsole = false)
	{
		// for the number of vertices we want, it will create and push them to a funcVertices vector
		for (float t = defMin; t < defMax; t += resolution)
		{
			if(_shouldWriteToConsole)
			{
				// Prints function values for x, y then z based on the function.
				cout << setprecision(3) << "Vector f(" << t << ") = (" << VecFuncX(t) << ", " << VecFuncY(t) << ", " << VecFuncZ(t) << ")" << "\n";
			}
			funcVertices.push_back(CreateVertex(VecFuncX(t), VecFuncY(t), VecFuncZ(t), calcR(VecFuncX(t)), calcG(VecFuncY(t)), calcB(VecFuncX(t))));
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

				outputFile << setprecision(3) << "("
					<< funcVertices[i]->x << ", "
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
			cerr << "Error opening file - Assignment 2";
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

	float VecFuncX(const float _t)
	{
		// Function at hand
		float x = cos(_t / 10 * M_PI);

		// Rounder to keep values from becoming too specific to 0
		if (x < 0.001 && x > -0.001)
			x = 0;

		return x;
	}

	float VecFuncY(const float _t)
	{
		// Function at had
		float y = sin(_t / 10 * M_PI);

		// Rounder to keep values from becoming too specific to 0
		if (y < 0.001 && y > -0.001)
			y = 0;

		return y;
	}

	float VecFuncZ(const float _t)
	{
		return _t;
	}

	float calcR(const float _t)
	{
		// Calculates the deltaX
		float currentX = _t;
		float deltaX = currentX - lastX;
		lastX = currentX;
		deltaX = abs(deltaX);

		// Restricts delta values between 5 and 0
		if (deltaX > 5)
			deltaX = 5;

		if (deltaX < 0.001)
			deltaX = 0;

		// returns the color red based on the delta value
		// times 2 so you can se the color better. 
		return deltaX*2;
	}

	float calcG(const float _t)
	{
		// Calculates the deltaX
		float currentY = _t;
		float deltaY = currentY - lastY;
		lastY = currentY;
		deltaY = abs(deltaY);

		// Restricts delta values between 5 and 0
		if (deltaY > 5)
			deltaY = 5;

		if (deltaY < 0.001)
			deltaY = 0;

		// returns the color red based on the delta value
		// times 2 so you can se the color better.
		return deltaY * 2;
	}

	float calcB(const float _t)
	{
		// Calculates the deltaX
		float currentZ = _t;
		float deltaZ = currentZ - lastZ;
		lastZ = currentZ;
		deltaZ = abs(deltaZ);

		// Restricts delta values between 5 and 0
		if (deltaZ > 5)
			deltaZ = 5;

		if (deltaZ < 0.001)
			deltaZ = 0;

		// returns the color red based on the delta value
		// times 2 so you can se the color better.
		return deltaZ * 2;
	}

public:
	// ------------ Getters and Setters -------------

};
