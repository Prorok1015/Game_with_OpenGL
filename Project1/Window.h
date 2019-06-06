#pragma once
#define WINDOW_H
#ifdef WINDOW_H

#include "glfw3native.h"
#include "glfw3.h"
#include <iostream>

class Window
{
public:
	Window(int window_width, int window_height, std::string title, GLFWmonitor* monitor = 0, GLFWwindow *shape = 0);
	~Window();

	void Use(void (*render)());
	GLFWwindow* GetWindow() { return this->window; };
	int GetWidth() { return this->Wwidth; };
	int GetHeight() { return this->Wheight; };
	void SetWidth(const int width) { this->Wwidth = width; }
	void SetHeight(const int height) { this->Wheight = height; };
	static void GLFWBackendInit();

private:
	int Wwidth;
	int Wheight;
	GLFWwindow* window;
	
	
};


#endif // 
