#pragma once
#include "CoordsXYZ.h"
#include "Model.h"
#include "Animations.h"
using namespace EDXFramework;
class Duck : public Model, public Animations
{
	CoordsXYZ mDuckCoords;
	float mDuckRotation;
	float mSwimRotation;
	bool mMoveFront, mMoveBack, mMoveRight, mMoveLeft;
public:
	Duck(string modelPath, string texturePath, bool mode, short index, short currentSpeed, float positionTraslate, float positionStart, float positionEnd, float rotation, float actualSize,
		float sizeLimit, float sizeMini, bool statusSmall, bool statusUp, bool statusDown, bool statusBack, bool statusFront, float duckRotation, short positionX, short positionY, short positionZ);
	void Swim();
};
