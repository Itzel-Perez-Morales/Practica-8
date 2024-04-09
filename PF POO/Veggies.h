#pragma once
#include "Model.h"
#include "Colision.h"
#include "Animations.h"

using namespace EDXFramework;

class Veggies : public Model, public Colision, public Animations
{
	enum Status {normal, bomb}; //si el enum == bomb y player colisiona entonces explota
	CoordsXYZ mVeggieCoords;
	bool mTaken;
	bool mExplote;
public:
	Veggies(string modelPath, string texturePath, bool mode, double colisionPointX, double colisionPointY, double colisionPointZ, double colisionRadioX, double colisionRadioY,
		double colisionRadioZ, short index, short currentSpeed, float positionTraslate, float positionStart, float positionEnd, float rotation, float actualSize,
		float sizeLimit, float sizeMini, bool statusSmall, bool statusUp, bool statusDown, bool statusBack, bool statusFront, bool _taken);
	double getCoordsX();
	double getCoordsY();
	double getCoordsZ();
	void setCoordsX(double posX);
	void setCoordsY(double posY);
	void setCoordsZ(double posZ);
	void Dance();
};
