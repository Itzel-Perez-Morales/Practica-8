#pragma once
#include "Model.h"

using namespace EDXFramework;

class Items : public Model
{
	bool taken;
public:
	Items();
	Items(string modelPath, string texturePath, bool mode, bool colisionStatus, double cX, double cY, double cZ, double cRX, double cRY, double cRZ, short i, short aSpeed, float pos, float pS, float pE, float rot, float actSize, float sizeL, float sizeM, bool sS, bool stUp, bool stDown, bool stBack, bool stFront, bool initTaken);
	void MoveObject(float spinI, float spinLimit, float sizeI, double positionX, double positionY, double positionZ);
	void TakeItem();
	bool getTaken();
	void setTaken(bool actStatus);
};
