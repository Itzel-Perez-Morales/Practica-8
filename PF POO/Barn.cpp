#include "Barn.h"

Barn::Barn(string modelPath, string texturePath, bool mode, bool colisionStatus, double colisionPointX, double colisionPointY, double colisionPointZ, double colisionRadioX, double colisionRadioY,
	double colisionRadioZ) :
	Model(modelPath, texturePath, mode), 
	Colision(colisionPointX, colisionPointY, colisionPointZ, colisionRadioX, colisionRadioY, colisionRadioZ)
{
	mColi[0] = new Colision(-45, 0, -146, 38, 0, 7.5);
	mColi[1] = new Colision(9, 0, -146, 33.3, 0, 7.5);
	mColi[2] = new Colision(37.4, 0, -193, 7.5, 0, 47.6);
	mColi[3] = new Colision(-45, 0, -195, 89, 0, 7.5);
	mColi[4] = new Colision(-45, 0, -193, 7.5, 0, 47.6);
	mColi[5] = new Colision(-37.5, 0, -170.3, 18.3, 0, 7.5);
	mColi[6] = new Colision(-24.5, 0, -175, 7.5, 0, 13.5);
	mColi[7] = new Colision(-24.5, 0, -189, 7.5, 0, 9.5);
	mColi[8] = new Colision(20.5, 0, -186.8, 7.5, 0, 21.4);
	mColi[9] = new Colision(34, 0, -169.5, 3.2, 0, 7.5);
	mColi[10] = new Colision(-10.6, 0, -145.6, 7.5, 0, 13.5);
	mColi[11] = new Colision(8.41, 0, -145.6, 7.5, 0, 13.5);
}

bool Barn::CheckHitbox(CoordsXYZ objCoords) 
{
	for (short i = 0; i < 12; i++)
	{
		if (mColi[i]->HitboxPtP(objCoords))
		{ return true; }
	}
	return false;
}

Barn::~Barn()
{
	for (short i = 0; i < 12; i++)
	{ delete mColi[i]; }
}
