#include "VeggiesCamp.h"
VeggiesCamp::VeggiesCamp(string modelPath, string texturePath, bool mode) :
	Model(modelPath, texturePath, mode)
{
	mColi[0] = new Colision(0.08, 0, -108.67, 31.52, 0, 7.4);
	mColi[1] = new Colision(-49.84, 0, -86.74, 7.4, 0, 31.52);
	mColi[2] = new Colision(0.08, 0, -83.85, 31.52, 0, 7.4);
	mColi[3] = new Colision(0.08, 0, -62.73, 31.52, 0, 7.4);
	mColi[4] = new Colision(44.6, 0, -83.85, 7.4, 0, 31.52);
	mColi[5] = new Colision(-49.84, 0, 142.52 , 7.4, 0, 31.52);
	mColi[6] = new Colision(0.08, 0, 119.4, 31.52, 0, 7.4);
	mColi[7] = new Colision(0.08, 0, 143.8, 31.52, 0, 7.4);
	mColi[8] = new Colision(0.08, 0, 166.4, 31.52, 0, 7.4);
	mColi[9] = new Colision(44.6, 0, 142.52, 7.4, 0, 31.52);
}

bool VeggiesCamp::CheckHitbox(CoordsXYZ objCoords)
{
	for (short i = 0; i < 10; i++)
	{
		if (mColi[i]->HitboxPtP(objCoords))
		{ return true; }
	}
	return false;
}

VeggiesCamp::~VeggiesCamp()
{
	for (short i = 0; i < 10; i++)
	{ delete mColi[i]; }
}