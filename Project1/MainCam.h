#pragma once

#ifndef MAINCAM_H
#define MAINCAM_H

#include "Shader.h"

class MainCam
{
public:
	glm::mat4 Use();
	MainCam();
	~MainCam();
};

#endif // MAINCAM_H


