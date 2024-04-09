#pragma once
#include "Model.h"
#include "Colision.h"
#include "Animations.h"

using namespace EDXFramework;

class Items : public Model, public Colision, public Animations
{
	bool mTaken;
	bool mAble;
public:
	Items(); //array de texturas
	Items(string modelPath, string texturePath, bool mode, double colisionPointX, double colisionPointY, double colisionPointZ, double colisionRadioX, double colisionRadioY,
		double colisionRadioZ, short index, short currentSpeed, float positionTraslate, float positionStart, float positionEnd, float rotation, float actualSize,
		float sizeLimit, float sizeMini, bool statusSmall, bool statusUp, bool statusDown, bool statusBack, bool statusFront, bool initTaken, bool initAble);
	void MoveObject(float spinI, float spinLimit, float sizeI);
	void TakeItem();
	bool getTaken();
	bool getAble();
	bool CheckHitbox(CoordsXYZ objCoords);
	void setTaken(bool actStatus);
	void setAble(bool actAble);
};
