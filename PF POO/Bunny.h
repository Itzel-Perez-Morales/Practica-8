#pragma once
#include<vector>
#include "Frames.h"
#include "Colision.h"
#include "Animations.h"

class Bunny : public Colision, public Animations
{
	CoordsXYZ coords;
	float speed; //variable para cada conejo
	Animations CatchCarrot;
	bool Status;
	bool CarrotTaken;
	//hacer que la animacion de golpear se reinstancie
public:
	Bunny(double colisionPointX, double colisionPointY, double colisionPointZ, double colisionRadioX, double colisionRadioY,
		double colisionRadioZ, short index, short currentSpeed, float positionTraslate, float positionStart, float positionEnd, float rotation, float actualSize,
		float sizeLimit, float sizeMini, bool statusSmall, bool statusUp, bool statusDown, bool statusBack, bool statusFront, short indexCatch);

	void Catch();
	void setCarrotsX(float posX);
	void setCarrotsY(float posY);
	void setCarrotsZ(float posZ);
	double getCarrotsX();
	double getCarrotsY();
	double getCarrotsZ();
	bool getCarrotTaken();

	~Bunny();
};
