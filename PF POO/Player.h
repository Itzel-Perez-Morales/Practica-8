#pragma once
#include <vector>
#include "Frames.h"
#include "Colision.h"
#include "Animations.h"
#include "CoordsXYZ.h"
using namespace std;

class Player : public Colision, public Animations
{
	CoordsXYZ mPlayerCoords;
	CoordsXYZ mPlayerDirection; 
	CoordsXYZ mCoordsDifCam;
	float mSpeed; //velocidad del jugador
	Animations mEddieRun;
	Animations mEddieHit;
	Animations mEddieIdle;
	//hacer que la animacion de golpear se reinstancie
public:
	Player(double pColisionPointX, double pColisionPointY, double pColisionPointZ, double pColisionRadioX, double pColisionRadioY,
		double pColisionRadioZ, short pIndex, short pCurrentSpeed, float pPositionTraslate, float pPositionStart, float pPositionEnd, float pRotation, float pActualSize,
		float pSizeLimit, float pSizeMini, bool pStatusSmall, bool pStatusUp, bool pStatusDown, bool pStatusBack, bool pStatusFront, short pIndexRun,
		short pIndexHit, short pIndexIdle);

	void Run();
	void Idle();
	void Hit();

	void Move(bool* pKeys[]);

	//GETTERS / SETTERS

	CoordsXYZ getPositions();
	CoordsXYZ getDirections();
	void setPositions(CoordsXYZ pCoords);

	~Player();
};
