#include "Window.h"



void Window::GLFWBackendInit()
{
	if (glfwInit() != 1) {

		printf("Error initializing GLFW");
		exit(EXIT_FAILURE);
	}

	int Major, Minor, Rev;
	glfwGetVersion(&Major, &Minor, &Rev);
	printf("GLFW %d.%d.%d initialized\n", Major, Minor, Rev);

}

Window::Window(int window_width, int window_height, std::string title, GLFWmonitor* monitor, GLFWwindow* shape)
{
	this->Wheight = window_height;
	this->Wwidth = window_width;
	this->window = glfwCreateWindow(this->Wheight, this->Wwidth, title.c_str(), monitor, shape);

}

Window::~Window()
{
	
}

void Window::Use(void(*render)())
{
	while (!glfwWindowShouldClose(this->window))
	{
		render();

		glfwSwapBuffers(this->window);
		glfwPollEvents();
	}
}
