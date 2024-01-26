
// GL Components
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// c++ specific components
#include "iostream"

// Class includes
#include "Main.h"

int main()
{
	// ------------------- Initialization ------------------- 
	// GLFW
	GLFInitialization();

	// Window
	GLFWwindow* window = initializeWindow("MainScreen");
	if (!window) return -1;

	// GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Faild to initialize GLAD" << std::endl;
		return -1;
	}

	// Shader
	Shader myShader("vertexShader.vs", "fragmentShader.fs");
	myShader.use();
	myShader.SetPerspectiveMode(PERSPECTIVE);

	// Camera
	myCamera.SetMovementMode(FLYING);

	// Geometry
	// -----------------------------------------------
	// CHANGE THIS TO ENUM TO TEST EACH ASSIGNMENT CODE:
	CurrentAssignment = AssignmentOne;
	// -----------------------------------------------
	if(CurrentAssignment == AssignmentOne)
	{
		myGeometry.Initialize(false);
		myGeometry.InitializeGeometryFromFile("Assignment1VertexFile.txt", false);
	}
	else if (CurrentAssignment == AssignmentTwo)
	{
		myGeometry.Initialize(false);
		myGeometry.InitializeGeometryFromFile("Assignment2VertexFile.txt", false);
	}
	else if (CurrentAssignment == AssignmentThree)
	{
		myGeometry.Initialize(false);
		myGeometry.InitializeGeometryFromFile("Assignment3VertexFile.txt", false);
	}
	

	// ------------------- Render loop ------------------- 

	while (!glfwWindowShouldClose(window))
	{
		// ---------- Input ----------
		updateDeltaTime();

		// ProcessInput
		processInput(window);

		// ---------- Rendering options ----------
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// ---------- Drawing ----------

		// Color

		// Transformations
		myShader.processTransformations(myCamera, SCR_WIDTH, SCR_HEIGHT);

		// Rendering

		if (CurrentAssignment == AssignmentOne)
			myGeometry.drawVertexGeometryAssignmentOne(false);
		
		else if (CurrentAssignment == AssignmentTwo)
			myGeometry.drawVertexGeometryAssignmentTwo(false);
		
		else if (CurrentAssignment == AssignmentThree)
			myGeometry.drawVertexGeometryAssignmentThree(false);
	

		// GLFW: swap buffers and process events
		// -------------------------------------------
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// De-allocates VBO, VAO and EBO resources
	myGeometry.~Geometry();

	glfwTerminate();
	return 0;
}
