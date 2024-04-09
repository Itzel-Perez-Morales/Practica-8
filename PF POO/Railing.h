#pragma once
#include "Model.h"
#include "Colision.h"
using namespace EDXFramework;

class Railing : public Model, public Colision
{
	Colision* mColi[10];
public:
	Railing(string modelPath, string texturePath, bool mode, bool colisionStatus, double colisionPointX, double colisionPointY, double colisionPointZ, double colisionRadioX, double colisionRadioY,
		double colisionRadioZ);
	bool CheckHitbox(CoordsXYZ objCoords);
	~Railing();
};
