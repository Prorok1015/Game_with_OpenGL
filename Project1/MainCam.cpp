#include "MainCam.h"

glm::mat4 MainCam::Use()
{
	glm::mat4 view = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
	float radius = 10.0f;
	float camX = sin(glfwGetTime()) * radius;
	float camZ = cos(glfwGetTime()) * radius;
	view = glm::lookAt(glm::vec3(camX, 0.0f, camZ), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	return view;
}

MainCam::MainCam()
{
	
}


MainCam::~MainCam()
{
}
