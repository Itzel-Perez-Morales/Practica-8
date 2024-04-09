#pragma once
#include "Model.h"
#include "Colision.h"
using namespace EDXFramework;

class Barn : public Model, public Colision
{
	Colision* mColi[12];

public:
	Barn(string modelPath, string texturePath, bool mode, bool colisionStatus, double colisionPointX, double colisionPointY, double colisionPointZ, double colisionRadioX, double colisionRadioY,
		double colisionRadioZ);
	bool CheckHitbox(CoordsXYZ objCoords); //pasar coords
	~Barn();
};