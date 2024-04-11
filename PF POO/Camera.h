#ifndef __Camera
#define __Camera
#define TO_RAD(DEG) (DEG * 3.1416 / 180)
#define TO_DEG(RAD) (RAD / 3.1416 * 180.0)
#define CAM_DIFERENCE 41.5
#define INTERPOLATION 0.1 //if gameStarted && gameInitialized
#define ANGLE_INC 3.5
#define POSITION_INC 1


#include "VectorRR.h"
#include "Animations.h"
#include <math.h>
#include "CoordsXYZ.h"

class Camera : public VectorRR, public Animations
{
public:
	VectorRR mPos, mDirec;
	CoordsXYZ* mCameraPoints[2];
	CoordsXYZ mCoords;
	CoordsXYZ mDirection;
	CoordsXYZ mVector;
	CoordsXYZ mPastCoords;

	float mAngle = 0, mDir = 0, mViewVectorMag = 0, mMagnitudX = 0, mMagnitudZ = 0;

	bool mAbleToMove;
	bool mCameraOn;

	Camera()
	{
		mCameraPoints[0] = new CoordsXYZ(2, 23, -125);
		mCameraPoints[1] = new CoordsXYZ(-35.8, 75, -105.5);
	}

	void cameraInitialize()
	{
		setPosition(*mCameraPoints[0]); //coordenadas de la posición
		setDirection(mDirection.x, mDirection.y, mDirection.z); // dirección/ángulo de la cámara
		mVector.x = 0, mVector.y = 1, mVector.z = 0;
		gluLookAt(mCoords.x, mCoords.y, mCoords.z, mDirection.x, mDirection.y, mDirection.z, mVector.x, mVector.y, mVector.z);
		mViewVectorMag = sqrt(pow(mDirection.x - mCoords.x, 2) + pow(mDirection.z - mCoords.z, 2));
		mAbleToMove = true; //Cuando entre al modo juego -> desabilitar, alt: escalar camara
	}

	void setPosition(CoordsXYZ pCoords)
	{
		mCoords.x = pCoords.x;
		mCoords.y = pCoords.y;
		mCoords.z = pCoords.z;
	}

	void setDirection(double pDirectionX, double pDirectionY, double pDirectionZ)
	{
		mDirection.x = pDirectionX;
		mDirection.y = pDirectionY;
		mDirection.z = pDirectionZ;
	}

	void cameraUpdate()
	{
		gluLookAt(mCoords.x, mCoords.y, mCoords.z, mDirection.x, mDirection.y, mDirection.z, mVector.x, mVector.y, mVector.z);
	}

	void move(char pMovDir)
	{
		mDir = 0;

		mMagnitudX = mDirection.x - mCoords.x;
		mMagnitudZ = mDirection.z - mCoords.z;

		switch (pMovDir)
		{
		case 'f':
			mDir = TO_DEG(atan2(mMagnitudZ, mMagnitudX));
			break;
		case 'b':
			mDir = TO_DEG(atan2(mMagnitudZ, mMagnitudX)) - 180;
			break;
		case 'l':
			mDir = TO_DEG(atan2(mMagnitudZ, mMagnitudX)) - 90;
			break;
		case 'r':
			mDir = TO_DEG(atan2(mMagnitudZ, mMagnitudX)) + 90;
			break;
		}
		if (mAbleToMove)
		{
			mCoords.z += POSITION_INC * sin(TO_RAD(mDir));
			mCoords.x += POSITION_INC * cos(TO_RAD(mDir));

			mDirection.z += POSITION_INC * sin(TO_RAD(mDir));
			mDirection.x += POSITION_INC * cos(TO_RAD(mDir));
		}
	}

	void turnRight()
	{
		mAngle = mAngle + ANGLE_INC;
		mDirection.x = sin(TO_RAD(mAngle)) * mViewVectorMag + mCoords.x;
		mDirection.z = -cos(TO_RAD(mAngle)) * mViewVectorMag + mCoords.z;
	}

	void turnLeft()
	{
		mAngle = mAngle - ANGLE_INC;
		mDirection.x = sin(TO_RAD(mAngle)) * mViewVectorMag + mCoords.x;
		mDirection.z = -cos(TO_RAD(mAngle)) * mViewVectorMag + mCoords.z;
	}

	void turnUp()
	{
		if (mDirection.y < 50 + mCoords.y)
		mDirection.y += 1;
	}

	void turnDown()
	{
		if (mDirection.y > -50 + mCoords.y)
		mDirection.y -= 1;
	}
};
#endif
