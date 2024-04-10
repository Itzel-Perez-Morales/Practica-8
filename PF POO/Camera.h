#ifndef __Camera
#define __Camera
#define TO_RAD(DEG) (DEG * 3.1416 / 180)
#define TO_DEG(RAD) (RAD / 3.1416 * 180.0)
#define CAM_DIFERENCE 41.5
#define INTERPOLATION 0.1
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

	float mAngle = 0, mDir = 0, mViewVectorMag = 0, mMagnitudX = 0, mMagnitudZ = 0;

	bool mAbleToMove;
	bool mEndAnimation = false;
	bool mCameraOn;
	bool mDisableLookUpAt = false;

	Camera()
	{
		mCameraPoints[0] = new CoordsXYZ(2, 23, -125);
		mCameraPoints[1] = new CoordsXYZ(-35.8, 80, -105.5); //puntos para cuando se inicie el juego
		//bool status
		//cameraOn = status;
	}

	void cameraInitialize(bool pGameStarted)
	{
		//positionX = -0.03, positionY = 23, positionZ = -162, directionX = 0, directionY = 23, directionZ = -25;
		// se valida si el jugador tuvo colisión con la barda de inicio de juego ->
		// se manda la posicion que se desea colocar la cámara ->
		// se aleja la cámara de jugador ->
		// ahora el jugador tiene la posición de la cámara sin procesar -> multiplicar los valores de la cámara por .5 o sumar diferencia? 
		// la camara se alejará


		//main.cpp
		//si el jugador teclea una o más teclas a la vez  //
		//se manda una bandera de que teclas presionó //
		//class Player
		//se valida y se entra a la función de Move//
		//en la función de move se ejecuta el codigo de move que está en la función de cámara//
		//se mandan las coordenadas nuevas a la función de cámara //
		//class Camera
		//se comparan las coordenadas nuevas del jugador con las de la camara/
		//se incrementa/decrementa de acuerdo a lo obtenido //OPC: multiplicar el factor para generar la sensación de poco movimiento 


		//si el juego ya ha iniciado...
		if (pGameStarted)
		{
			mDisableLookUpAt = true;
			setPosition(*mCameraPoints[1]); //coordenadas de la posición
			setDirection(-33, -150, -276);
		}
		else
		{
			mDisableLookUpAt = false;
			setPosition(*mCameraPoints[0]); //coordenadas de la posición
			setDirection(mDirection.x, mDirection.y, mDirection.z); // dirección/ángulo de la cámara
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

	void MoveOnGame(CoordsXYZ pPlayerCoords, bool pKeys[])
	{
		float finalPositionX = pPlayerCoords.x;
		float finalPositionZ = pPlayerCoords.z + CAM_DIFERENCE;
		//float finalPositionZ = mCoords.z + CAM_DIFERENCE;
		
		float distance = sqrt((pow((mCoords.x - finalPositionX), 2) + (pow((mCoords.z - finalPositionZ), 2)))); //distancia actual

		finalPositionX = mCoords.x + INTERPOLATION * (finalPositionX - mCoords.x);
		finalPositionZ = mCoords.z + INTERPOLATION * (finalPositionZ - mCoords.z);

		mCoords.x = finalPositionX;
		mCoords.z = finalPositionZ;
		if (mCoords.z > 24)  // hacia donde va? -> hacer que recupere su posición inicial
		{
			if (pKeys[1] && mDirection.y > -680)
			{
				mDirection.y -= 1; //poner limite de -680
			}
			else
			{

				if (pKeys[0] && mDirection.y < -150)
				{
					mDirection.y += 1;
				}
			}
		}
	}


	//void MoveOnGame(CoordsXYZ pPlayerCoords)
	//{
	//	float distance = sqrt((pow((mCoords.x - pPlayerCoords.x), 2) + (pow((mCoords.z - pPlayerCoords.z), 2)))); //distancia actual
	//	if (mCoords.x >= pPlayerCoords.x + 1)
	//	{
	//		mCoords.x -= 0.85;
	//	}
	//	if (mCoords.x <= pPlayerCoords.x - 1)
	//	{
	//		mCoords.x += 0.85;
	//	}
	//	if (distance > CAM_DIFERENCE + 2 || distance < CAM_DIFERENCE - 2)
	//	{
	//		if (mCoords.z - CAM_DIFERENCE > pPlayerCoords.z + 2)
	//		{
	//			mCoords.z -= 0.8;
	//			mDirection.y += 1;
	//		}
	//		else
	//		{
	//			if (mCoords.z - CAM_DIFERENCE < pPlayerCoords.z + 2)
	//			{
	//				mCoords.z += 0.8;
	//				mDirection.y -= 1;
	//			}
	//		}
	//	}
	//}
	/*	if (mCoords.x >= pPlayerCoords.x + 1)
		{
			mCoords.x -= 0.85;
		}
		if (mCoords.x <= pPlayerCoords.x - 1)
		{
			mCoords.x += 0.85;
		}

		if (distance > CAM_DIFERENCE + 2 || distance < CAM_DIFERENCE - 2)
		{
			if (mCoords.z - CAM_DIFERENCE > pPlayerCoords.z + 2)
			{
				mCoords.z -= 0.8;
				mDirection.y += 1;
			}
			else
			{
				if (mCoords.z - CAM_DIFERENCE < pPlayerCoords.z + 2)
				{
					mCoords.z += 0.8;
					mDirection.y -= 1;
				}
			}
		}*/

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