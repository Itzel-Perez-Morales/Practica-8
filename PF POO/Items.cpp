#include "Items.h"

Items::Items() {};

Items::Items(string modelPath, string texturePath, bool mode, bool colisionStatus, double cX, double cY, double cZ, double cRX, double cRY, double cRZ, short i, short aSpeed, float pos, float pS, float pE, float rot, float actSize, float sizeL, float sizeM, bool sS, bool stUp, bool stDown, bool stBack, bool stFront, bool initTaken) :
	Model(colisionStatus, cX, cY, cZ, cRX, cRY, cRZ, i, aSpeed, pos, pS, pE, rot, actSize, sizeL, sizeM, sS, stUp, stDown, stBack, stFront, modelPath, texturePath, mode),
	Colision(colisionStatus, cX, cY, cZ, cRX, cRY, cRZ),
	Animations(i, aSpeed, pos, pS, pE, rot, actSize, sizeL, sizeM, sS, stUp, stDown, stBack, stFront)
{
	taken = initTaken;
}

void Items::MoveObject(float spinI, float spinLimit, float sizeI, double positionX, double positionY, double positionZ)
{
	Spin(spinI, spinLimit);
	Resizing(sizeI);
	glPushMatrix();
	glTranslatef(positionX, positionY, positionZ);
	glRotatef(getRotation(), 1, 1, 1);
	glScalef(getSize(), getSize(), getSize());
	Draw();
	glPopMatrix();
}