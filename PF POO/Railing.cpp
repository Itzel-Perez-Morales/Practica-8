#pragma once
#include "Railing.h"

Railing::Railing(string modelPath, string texturePath, bool mode, bool colisionStatus, double colisionPointX, double colisionPointY, double colisionPointZ, double colisionRadioX, double colisionRadioY,
	double colisionRadioZ) :
	Model(modelPath, texturePath, mode),
	Colision(colisionPointX, colisionPointY, colisionPointZ, colisionRadioX, colisionRadioY, colisionRadioZ)
{
	mColi[0] = new Colision(1.4 , 0 , -122.21 , 65 , 0 , 1.49);
	mColi[1] = new Colision(-62, 0, -84.1, 1.49, 0, 38.6);
	mColi[2] = new Colision(-36.14, 0, -46.3, 27.43, 0, 1.49);
	mColi[3] = new Colision(37.98, 0, -46.3, 28.39, 0, 1.49);
	mColi[4] = new Colision(64.9, 0, -84.1, 1.49, 0, 38.6);
	mColi[5] = new Colision(1.4, 0, 179.4, 65, 0, 1.49);
	mColi[6] = new Colision(-62, 0, 141.91, 1.49, 0, 38.6);
	mColi[7] = new Colision(38.12, 0, 103.79, 28.38, 0, 1.49);
	mColi[8] = new Colision(-36.4, 0, 103.79, 28.16, 0, 1.49);
	mColi[9] = new Colision(64.9, 0, 141.91, 1.49, 0, 38.6);
}

bool Railing::CheckHitbox(CoordsXYZ objCoords)
{
	for (short i = 0; i < 10; i++)
	{
		if (mColi[i]->Hitbox(objCoords))
		{ return true; }
	}
	return false;
	/*if (coli1->Hitbox(_objCoordX, _objCoordY, _objCoordZ) == true)
		return true;*/
}

Railing::~Railing()
{
	for (short i = 0; i < 10; i++)
	{ delete mColi[i]; }
}

