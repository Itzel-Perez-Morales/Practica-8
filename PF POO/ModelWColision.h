#pragma once
#include "Model.h"
#include "Colision.h"

using namespace EDXFramework;

class ModelWColision : public Model, public Colision
{
public:
	ModelWColision(string modelPath, string texturePath, bool mode, double colisionPointX, double colisionPointY, double colisionPointZ, double colisionRadioX, double colisionRadioY, double colisionRadioZ);
	bool CheckHitbox(CoordsXYZ objCoords);
};