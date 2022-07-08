#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "iostream"

int g_WindowSizeX = 1920/2;
int g_WindowSizeY = 1080/2;

void glfwWindowSizeCallBack(GLFWwindow* pWindow, int Width, int Height)
{
	g_WindowSizeX = Width;
	g_WindowSizeY = Height;
	glViewport( 0, 0, g_WindowSizeX, g_WindowSizeY);
}

void glfwKeyCallback(GLFWwindow* pWindow, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_F1 && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(pWindow, GL_TRUE);
	}
}

int main()
{
	// Initialize GLFW 
	glfwInit();

	// Tell GLFW what version of OpenGl we are using 
	// In this case 
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	// Tell GLFW that we are using CORE profile
	// That means that we only have the modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	

	// Create GLFWwindow object of 800 by 800 pyxels, naming it "BattleCity"
	GLFWwindow* pWindow = glfwCreateWindow(g_WindowSizeX, g_WindowSizeY, "BattleCity", NULL, NULL);

	// Error check, if window fails to create
	if (!pWindow)
	{
		std::cout << "Failed to creat GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	// Callbacks
	glfwSetWindowSizeCallback(pWindow, glfwWindowSizeCallBack);
	glfwSetKeyCallback(pWindow, glfwKeyCallback);


	// Introduce the window into the current context
	glfwMakeContextCurrent(pWindow);

	// Load GLAD so it configures OpenGl
	if (!gladLoadGL())
	{
		std::cout << "Can't load gladGL" << std::endl;
	}

	std::cout << "Renderer : " << glGetString(GL_RENDERER) << std::endl;
	std::cout << "OpenGl version : " << glGetString(GL_VERSION) << std::endl;



	// Specify the viewport of OpenGl in the window 
	// In this case viewport goes from x = , y = 0, x = 800, y = 800
	glViewport(0, 0, 800, 800);


	// Specify the color of the background
	glClearColor(0.07, 0.13, 0.17, 1);

	// Clean the black buffer and assign the new color to it
	glClear(GL_COLOR_BUFFER_BIT);

	// Swap the black buffer with the front buffer
	glfwSwapBuffers(pWindow);

	// Main while loop
	while (!glfwWindowShouldClose(pWindow))
	{
		glClearColor(0.07, 0.13, 0.17, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(pWindow);

		// Take care of all GLFW events
		glfwPollEvents();

	}


	// Delete window before ending the program
	glfwDestroyWindow(pWindow);

	// Terminate GLFW before ending the program
	glfwTerminate();

	return 0;
}