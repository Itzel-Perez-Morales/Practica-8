#include "Veggies.h"

Veggies::Veggies(string modelPath, string texturePath, bool mode, double colisionPointX, double colisionPointY, double colisionPointZ, double colisionRadioX, double colisionRadioY,
	double colisionRadioZ, short index, short currentSpeed, float positionTraslate, float positionStart, float positionEnd, float rotation, float actualSize,
	float sizeLimit, float sizeMini, bool statusSmall, bool statusUp, bool statusDown, bool statusBack, bool statusFront, bool _taken) :
	Model(modelPath, texturePath, mode),
	Colision(colisionPointX, colisionPointY, colisionPointZ, colisionRadioX, colisionRadioY, colisionRadioZ),
	Animations(index, currentSpeed, positionTraslate, positionStart, positionEnd, rotation, actualSize, sizeLimit, sizeMini, statusSmall, statusUp, statusDown, statusBack, statusFront)
{
	mVeggieCoords.x = colisionPointX;
	mVeggieCoords.y = colisionPointY;
	mVeggieCoords.z = colisionPointZ;
	mTaken = _taken;
}

void Veggies::Dance()
{
	Spin(10, 360);
	MoveUpNDown(0.25);
	Resizing(0.1);
	glPushMatrix();
	glTranslatef(mVeggieCoords.x, getPosition(),mVeggieCoords.z);
	glRotatef(getRotation(), 0, 1, 0);
	glScalef(getSize(),getSize(), getSize());
	Draw();
	glPopMatrix();
}


void Veggies::setCoordsX(double posX)
{
	mVeggieCoords.x = posX;
}
void Veggies::setCoordsY(double posY)
{
	mVeggieCoords.y = posY;
}
void Veggies::setCoordsZ(double posZ)
{
	mVeggieCoords.z = posZ;
}
double Veggies::getCoordsX()
{
	return mVeggieCoords.x;
}
double Veggies::getCoordsY()
{
	return mVeggieCoords.y;
}
double Veggies::getCoordsZ()
{
	return mVeggieCoords.z;
}