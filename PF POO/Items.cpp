#include "Items.h"

Items::Items() {};

Items::Items(string modelPath, string texturePath, bool mode, double colisionPointX, double colisionPointY, double colisionPointZ, double colisionRadioX, double colisionRadioY,
	double colisionRadioZ, short index, short currentSpeed, float positionTraslate, float positionStart, float positionEnd, float rotation, float actualSize,
	float sizeLimit, float sizeMini, bool statusSmall, bool statusUp, bool statusDown, bool statusBack, bool statusFront, bool initTaken, bool initAble) :
	Model(modelPath, texturePath, mode),
	Colision(colisionPointX, colisionPointY, colisionPointZ, colisionRadioX, colisionRadioY, colisionRadioZ),
	Animations(index, currentSpeed, positionTraslate, positionStart, positionEnd, rotation, actualSize, sizeLimit, sizeMini, statusSmall, statusUp, statusDown, statusBack, statusFront)
{
	mAble = initAble;
	mTaken = initTaken;
}

void Items::MoveObject(float pSpinI, float pSpinLimit, float pSizeI)
{
	if (mTaken == false)
	{
		Spin(pSpinI, pSpinLimit);
		Resizing(pSizeI);
		glPushMatrix();
		glTranslatef(getCoordsColisionX(), getCoordsColisionY(), getCoordsColisionZ());
		glRotatef(getRotation(), 1, 1, 1);
		glScalef(getSize(), getSize(), getSize());
		Draw();
		glPopMatrix();
	}
}

bool Items::CheckHitbox(CoordsXYZ objCoords)
{
	if (Hitbox(objCoords) == true)
		return true;
	else
		return false;
}

bool Items::getAble()
{ return mAble; }

void Items::setAble(bool actAble)
{ mAble = actAble; }

bool Items::getTaken()
{ return mTaken; }

void Items::setTaken(bool actStatus)
{ mTaken = actStatus; }