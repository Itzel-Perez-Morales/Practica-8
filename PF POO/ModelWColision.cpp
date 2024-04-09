#include "ModelWColision.h"

ModelWColision::ModelWColision(string modelPath, string texturePath, bool mode, double colisionPointX, double colisionPointY, double colisionPointZ, double colisionRadioX, double colisionRadioY, double colisionRadioZ) :
	Model(modelPath, texturePath, mode),
	Colision(colisionPointX, colisionPointY, colisionPointZ, colisionRadioX, colisionRadioY, colisionRadioZ)
{

}

bool ModelWColision::CheckHitbox(CoordsXYZ objCoords)
{
	if (Hitbox(objCoords))
		return true;
	else
		return false;
}