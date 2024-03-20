#ifndef __Camera
#define __Camera
#define TO_RAD(DEG) (DEG * 3.1416 / 180)
#define TO_DEG(RAD) (RAD / 3.1416 * 180.0)
#define ANGLE_INC 3.5
#define POSITION_INC 1


#include "VectorRR.h"
#include <math.h>

class Camera : public VectorRR
{
public:
	VectorRR posc, dirc;
	double positionX, positionY, positionZ, directionX, directionY, directionZ, ux, uy, uz, antPosX, antPosY, antPosZ;

	float angle = 0, dir = 0;
	float viewVectorMag = 0, magnitudX = 0, magnitudZ = 0;

	bool ableToMove;

	Camera()
	{
	}

	void cameraInitialize()
	{
		//positionX = -0.03, positionY = 23, positionZ = -162, directionX = 0, directionY = 23, directionZ = -25;
		positionX = -164, positionY = 23, positionZ = 20, directionX = 0, directionY = 23, directionZ = -25;
		ux = 0, uy = 1, uz = 0;
		gluLookAt(positionX, positionY, positionZ, directionX, directionY, directionZ, ux, uy, uz);
		viewVectorMag = sqrt(pow(directionX - positionX, 2) + pow(directionZ - positionZ, 2));
		ableToMove = true; //ITZEL: Cuando entre al modo juego -> desabilitar, alt: escalar camara
	}

	void cameraUpdate()
	{
		gluLookAt(positionX, positionY, positionZ, directionX, directionY, directionZ, ux, uy, uz);
	}

	void move(char movDir)
	{
		dir = 0;

		magnitudX = directionX - positionX;
		magnitudZ = directionZ - positionZ;

		switch (movDir)
		{
		case 'f':
			dir = TO_DEG(atan2(magnitudZ, magnitudX));
			break;
		case 'b':
			dir = TO_DEG(atan2(magnitudZ, magnitudX)) - 180;
			break;
		case 'l':
			dir = TO_DEG(atan2(magnitudZ, magnitudX)) - 90;
			break;
		case 'r':
			dir = TO_DEG(atan2(magnitudZ, magnitudX)) + 90;
			break;
		}
		if (ableToMove)
		{
			positionZ += POSITION_INC * sin(TO_RAD(dir));
			directionZ += POSITION_INC * sin(TO_RAD(dir));
			positionX += POSITION_INC * cos(TO_RAD(dir));
			directionX += POSITION_INC * cos(TO_RAD(dir));
		}
	}

	void turnRight()
	{
		angle = angle + ANGLE_INC;
		directionX = sin(TO_RAD(angle)) * viewVectorMag + positionX;
		directionZ = -cos(TO_RAD(angle)) * viewVectorMag + positionZ;
	}

	void turnLeft()
	{
		angle = angle - ANGLE_INC;
		directionX = sin(TO_RAD(angle)) * viewVectorMag + positionX;
		directionZ = -cos(TO_RAD(angle)) * viewVectorMag + positionZ;
	}

	void turnUp()
	{
		if (directionY < 50 + positionY)
			directionY += 1;
	}

	void turnDown()
	{
		if (directionY > -50 + positionY)
			directionY -= 1;
	}
};
#endif