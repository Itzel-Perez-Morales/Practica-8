#pragma once
#include "Model.h"
using namespace EDXFramework;

//manejo de frames cuando hay animaciones de fpf
class Frames : public Model
{
public:
	Frames();
	Frames(string modelPath, string texturePath, bool mode);
};
