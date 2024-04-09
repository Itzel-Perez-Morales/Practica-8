#pragma once
#define TO_RAD(DEG) (DEG * 3.1416 / 180)
#define TO_DEG(RAD) (RAD / 3.1416 * 180.0)
#define ANGLE_INC 3.5
#define POSITION_INC 1
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

	void Move(char pMove);

	//GETTERS / SETTERS

	CoordsXYZ getPositions();
	CoordsXYZ getDirections();
	void setPositions(CoordsXYZ pCoords);

	~Player();
};
