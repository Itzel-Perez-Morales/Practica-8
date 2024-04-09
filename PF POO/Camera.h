#ifndef __Camera
#define __Camera
#define TO_RAD(DEG) (DEG * 3.1416 / 180)
#define TO_DEG(RAD) (RAD / 3.1416 * 180.0)
#define ANGLE_INC 3.5
#define POSITION_INC 1


#include "VectorRR.h"
#include "Animations.h"
#include <math.h>
#include "Player.h"

// Analizar la posibilidad de utilizar solo una camara
	// Tener los datos de variantes de la camara
		// Arreglos de posiciones, direcciones...
class Camera : public VectorRR, public Animations
{
public:
	VectorRR mPos, mDirec;
	CoordsXYZ* mCameraPoints[2];
	CoordsXYZ mCoords;
	CoordsXYZ mDirection;
	CoordsXYZ mVector;
	CoordsXYZ mPastCoords;
	//double positionX, positionY, positionZ,
	//float cameraDiference = 0.5;
	float cameraDiference = 41.5;

	float mAngle = 0, mDir = 0, mViewVectorMag = 0, mMagnitudX = 0, mMagnitudZ = 0;

	bool mAbleToMove;
	bool mEndAnimation = false;
	bool mCameraOn;
	bool mDisableLookUpAt = false;

	Camera()
	{
		mCameraPoints[0] = new CoordsXYZ(2, 23, -125);
		mCameraPoints[1] = new CoordsXYZ(-35.8, 90, -64); //puntos para cuando se inicie el juego
		//bool status
		//cameraOn = status;
	}

	void cameraInitialize(bool pGameStarted)
	{
		//positionX = -0.03, positionY = 23, positionZ = -162, directionX = 0, directionY = 23, directionZ = -25;
		// se valida si el jugador tuvo colisi�n con la barda de inicio de juego ->
		// se manda la posicion que se desea colocar la c�mara ->
		// se aleja la c�mara de jugador ->
		// ahora el jugador tiene la posici�n de la c�mara sin procesar -> multiplicar los valores de la c�mara por .5 o sumar diferencia? 
		// la camara se alejar�


		//main.cpp
		//si el jugador teclea una o m�s teclas a la vez  //
		//se manda una bandera de que teclas presion� //
		//class Player
		//se valida y se entra a la funci�n de Move//
		//en la funci�n de move se ejecuta el codigo de move que est� en la funci�n de c�mara//
		//se mandan las coordenadas nuevas a la funci�n de c�mara //
		//class Camera
		//se comparan las coordenadas nuevas del jugador con las de la camara/
		//se incrementa/decrementa de acuerdo a lo obtenido //OPC: multiplicar el factor para generar la sensaci�n de poco movimiento 


		//si el juego ya ha iniciado...
		if (pGameStarted)
		{
			mDisableLookUpAt = true;
			setPosition(*mCameraPoints[1]); //coordenadas de la posici�n
			setDirection(-33, -150, -276);
		}
		else
		{
			mDisableLookUpAt = false;
			setPosition(*mCameraPoints[0]); //coordenadas de la posici�n
			setDirection(mDirection.x, mDirection.y, mDirection.z); // direcci�n/�ngulo de la c�mara
		}
		//positionX = pX, positionY = pY, positionZ = pZ, directionX = dX, directionY = dY, directionZ = dZ;

		mVector.x = 0, mVector.y = 1, mVector.z = 0;
		gluLookAt(mCoords.x, mCoords.y, mCoords.z, mDirection.x, mDirection.y, mDirection.z,
			mVector.x, mVector.y, mVector.z);
		mViewVectorMag = sqrt(pow(mDirection.x - mCoords.x, 2) + pow(mDirection.z - mCoords.z, 2));
		mAbleToMove = true; //Cuando entre al modo juego -> desabilitar, alt: escalar camara
		//}
		//else
		//{
		//	positionX = 
		//}
	}

	void setPosition(CoordsXYZ pCoords)
	{
		mCoords.x = pCoords.x;
		mCoords.y = pCoords.y;
		mCoords.z = pCoords.z;
	}

	// Si el movimiento de la camara va a estar animado -> Investigar Interpolation
	// SetPosition(0, 0, 0)
	// SetPosition(10, 0, 0)

	void setDirection(double pDirectionX, double pDirectionY, double pDirectionZ)
	{
		mDirection.x = pDirectionX;
		mDirection.y = pDirectionY;
		mDirection.z = pDirectionZ;
	}

	void cameraUpdate(bool gameStarted)
	{
		gluLookAt(mCoords.x, mCoords.y, mCoords.z, mDirection.x, mDirection.y, mDirection.z, mVector.x, mVector.y, mVector.z);
	}

	void cameraModeGame(CoordsXYZ pCoords)
	{
		gluLookAt(mCoords.x, mCoords.y, mCoords.z, pCoords.x, pCoords.y, pCoords.z, mVector.z, mVector.y, mVector.z);
		//mViewVectorMag = sqrt(pow(mDirection.y - mCoords.x, 2) + pow(mDirection.z - mCoords.z, 2));
		//mAbleToMove = true; //ITZEL: Cuando entre al modo juego -> desabilitar, alt: escalar camara
	}

	//void AnimationInitGame()
	//{
	//	if (!mEndAnimation)
	//	{
	//		GoAcross(mCoords.x, -200, mDirection.y, -15, mEndAnimation); 
	//		gluLookAt(mCoords.x, mCoords.y, mCoords.z, mDirection.x, mDirection.y, mDirection.z, mVector.x, mVector.y, mVector.z);
	//	}
	//}

	void MoveOnGame(CoordsXYZ pPlayerCoords)
	{
		if (mCoords.x >= pPlayerCoords.x)
		{
			mCoords.x -= 0.5;
		}
		else
		{
			if (mCoords.x <= pPlayerCoords.x)
			{
				mCoords.x += 0.5;
			}
		}

		if (mCoords.z - cameraDiference >= pPlayerCoords.z)
		{
			mCoords.z -= 0.5;
		}
		else
		{
			if (mCoords.z - cameraDiference <= pPlayerCoords.z)
			{
				mCoords.z += 0.5;
			}
		}
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
		if (!mDisableLookUpAt)
		{
			if (mDirection.y < 50 + mCoords.y && !mDisableLookUpAt)
			mDirection.y += 1;
		}
	}

	void turnDown()
	{
		if (!mDisableLookUpAt)
		{
		if (mDirection.y > -50 + mCoords.y && !mDisableLookUpAt)
			mDirection.y -= 1;
		}
	}
};
#endif