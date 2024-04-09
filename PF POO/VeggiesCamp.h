#pragma once
#include "Model.h"
#include "Colision.h"
using namespace EDXFramework;

class VeggiesCamp : public Model
{
	Colision* mColi[10];
public:
	VeggiesCamp(string modelPath, string texturePath, bool mode);
	bool CheckHitbox(CoordsXYZ objCoords);
	~VeggiesCamp();
};