#pragma once
#include "Player.h"

Player::Player(double pColisionPointX, double pColisionPointY, double pColisionPointZ, double pColisionRadioX, double pColisionRadioY,
	double pColisionRadioZ, short pIndex, short pCurrentSpeed, float pPositionTraslate, float pPositionStart, float pPositionEnd, float pRotation, float pActualSize,
	float pSizeLimit, float pSizeMini, bool pStatusSmall, bool pStatusUp, bool pStatusDown, bool pStatusBack, bool pStatusFront, short pIndexRun,
	short pIndexHit, short pIndexIdle) :
	Colision(pColisionPointX, pColisionPointY, pColisionPointZ, pColisionRadioX, pColisionRadioY, pColisionRadioZ),
	Animations(pIndex, pCurrentSpeed, pPositionTraslate, pPositionStart, pPositionEnd, pRotation, pActualSize, pSizeLimit, pSizeMini, pStatusSmall, pStatusUp, pStatusDown, pStatusBack, pStatusFront)
{//manejar por enums
	// TODO: Reutilizar textura
	mEddieRun.AddFrames(new Frames("Modelos//Player//Run//R0.obj", "Modelos//Player//Player.bmp", 1));
	mEddieRun.AddFrames(new Frames("Modelos//Player//Run//R1.obj", "Modelos//Player//Player.bmp", 1));
	mEddieRun.AddFrames(new Frames("Modelos//Player//Run//R2.obj", "Modelos//Player//Player.bmp", 1));
	mEddieRun.AddFrames(new Frames("Modelos//Player//Run//R3.obj", "Modelos//Player//Player.bmp", 1));
	mEddieRun.AddFrames(new Frames("Modelos//Player//Run//R4.obj", "Modelos//Player//Player.bmp", 1));
	mEddieRun.AddFrames(new Frames("Modelos//Player//Run//R5.obj", "Modelos//Player//Player.bmp", 1));
	mEddieRun.AddFrames(new Frames("Modelos//Player//Run//R6.obj", "Modelos//Player//Player.bmp", 1));
	mEddieRun.AddFrames(new Frames("Modelos//Player//Run//R7.obj", "Modelos//Player//Player.bmp", 1));
	mEddieRun.AddFrames(new Frames("Modelos//Player//Run//R8.obj", "Modelos//Player//Player.bmp", 1));
	mEddieRun.AddFrames(new Frames("Modelos//Player//Run//R9.obj", "Modelos//Player//Player.bmp", 1));
	mEddieRun.AddFrames(new Frames("Modelos//Player//Run//R10.obj", "Modelos//Player//Player.bmp", 1));

	mEddieHit.AddFrames(new Frames("Modelos//Player//Hit//H1.obj", "Modelos//Player//PlayerHamm.bmp", 1));
	mEddieHit.AddFrames(new Frames("Modelos//Player//Hit//H2.obj", "Modelos//Player//PlayerHamm.bmp", 1));
	mEddieHit.AddFrames(new Frames("Modelos//Player//Hit//H3.obj", "Modelos//Player//PlayerHamm.bmp", 1));
	mEddieHit.AddFrames(new Frames("Modelos//Player//Hit//H4.obj", "Modelos//Player//PlayerHamm.bmp", 1));
	mEddieHit.AddFrames(new Frames("Modelos//Player//Hit//H5.obj", "Modelos//Player//PlayerHamm.bmp", 1));
	mEddieHit.AddFrames(new Frames("Modelos//Player//Hit//H6.obj", "Modelos//Player//PlayerHamm.bmp", 1));
	mEddieHit.AddFrames(new Frames("Modelos//Player//Hit//H7.obj", "Modelos//Player//PlayerHamm.bmp", 1));
	mEddieHit.AddFrames(new Frames("Modelos//Player//Hit//H8.obj", "Modelos//Player//PlayerHamm.bmp", 1));
	mEddieHit.AddFrames(new Frames("Modelos//Player//Hit//H9.obj", "Modelos//Player//PlayerHamm.bmp", 1));
	mEddieHit.AddFrames(new Frames("Modelos//Player//Hit//H10.obj", "Modelos//Player//PlayerHamm.bmp", 1));
	mEddieHit.AddFrames(new Frames("Modelos//Player//Hit//H11.obj", "Modelos//Player//PlayerHamm.bmp", 1));
	mEddieHit.AddFrames(new Frames("Modelos//Player//Hit//H12.obj", "Modelos//Player//PlayerHamm.bmp", 1));
	mEddieHit.AddFrames(new Frames("Modelos//Player//Hit//H13.obj", "Modelos//Player//PlayerHamm.bmp", 1));

	mEddieIdle.AddFrames(new Frames("Modelos//Player//Idle//I1.obj", "Modelos//Player//Player.bmp", 1));
	mEddieIdle.AddFrames(new Frames("Modelos//Player//Idle//I2.obj", "Modelos//Player//Player.bmp", 1));
	mEddieIdle.AddFrames(new Frames("Modelos//Player//Idle//I3.obj", "Modelos//Player//Player.bmp", 1));
	mEddieIdle.AddFrames(new Frames("Modelos//Player//Idle//I4.obj", "Modelos//Player//Player.bmp", 1));
	mEddieIdle.AddFrames(new Frames("Modelos//Player//Idle//I5.obj", "Modelos//Player//Player.bmp", 1));
	mEddieIdle.AddFrames(new Frames("Modelos//Player//Idle//I6.obj", "Modelos//Player//Player.bmp", 1));
	mEddieIdle.AddFrames(new Frames("Modelos//Player//Idle//I7.obj", "Modelos//Player//Player.bmp", 1));
	mEddieIdle.AddFrames(new Frames("Modelos//Player//Idle//I8.obj", "Modelos//Player//Player.bmp", 1));
	mEddieIdle.AddFrames(new Frames("Modelos//Player//Idle//I9.obj", "Modelos//Player//Player.bmp", 1));
	mEddieIdle.AddFrames(new Frames("Modelos//Player//Idle//I10.obj", "Modelos//Player//Player.bmp", 1));
	mEddieIdle.AddFrames(new Frames("Modelos//Player//Idle//I11.obj", "Modelos//Player//Player.bmp", 1));
	mEddieIdle.AddFrames(new Frames("Modelos//Player//Idle//I12.obj", "Modelos//Player//Player.bmp", 1));
	mEddieIdle.AddFrames(new Frames("Modelos//Player//Idle//I13.obj", "Modelos//Player//Player.bmp", 1));
	mEddieIdle.AddFrames(new Frames("Modelos//Player//Idle//I14.obj", "Modelos//Player//Player.bmp", 1));
	mEddieIdle.AddFrames(new Frames("Modelos//Player//Idle//I15.obj", "Modelos//Player//Player.bmp", 1));
	mEddieIdle.AddFrames(new Frames("Modelos//Player//Idle//I16.obj", "Modelos//Player//Player.bmp", 1));
	mEddieIdle.AddFrames(new Frames("Modelos//Player//Idle//I17.obj", "Modelos//Player//Player.bmp", 1));
	mEddieIdle.AddFrames(new Frames("Modelos//Player//Idle//I18.obj", "Modelos//Player//Player.bmp", 1));
	mEddieIdle.AddFrames(new Frames("Modelos//Player//Idle//I19.obj", "Modelos//Player//Player.bmp", 1));
	mEddieIdle.AddFrames(new Frames("Modelos//Player//Idle//I20.obj", "Modelos//Player//Player.bmp", 1));

	mEddieRun.setFPFLimit(pIndexRun);
	mEddieHit.setFPFLimit(pIndexHit);
	mEddieIdle.setFPFLimit(pIndexIdle);
	mPlayerCoords.x = pColisionPointX;
	mPlayerCoords.y = pColisionPointY;
	mPlayerCoords.z = pColisionPointZ;
}

//void Animate(Animations animation, CoordsXYZ position, CoordsXYZ offset) //diference? offset -> frames 
//{
//	glPushMatrix();
//	glTranslatef(position.x * offset.x, position.y * offset.y, position.z * offset.z);
//	//validar colision
//	if (animation.getTime() == animation.getSpeed())
//	{
//		Player::FPF(animation.getFrames(), animation.getFPFLimit());
//		animation.setSpeed(0);
//	}
//	else
//	{
//		animation.getFrames()[animation.getIndex()]->Draw();
//		animation.setSpeed(animation.getSpeed() + 1);
//	}
//	glPopMatrix();
//}

void Player::Idle()
{
	glPushMatrix();
	glTranslatef(mPlayerCoords.x, mPlayerCoords.y, mPlayerCoords.z); //pasar coords de camara sin modificar -> sin multiplicar por .4
	glRotatef(getRotation(), 0, 1, 0);
	//validar colision
	FPF(mEddieIdle.getFrames(), mEddieIdle.getFPFLimit());
	glPopMatrix();
}

void Player::Run()
{
	glPushMatrix();
	glTranslatef(mPlayerCoords.x, mPlayerCoords.y, mPlayerCoords.z);
	//validar colision
	glRotatef(getRotation(), 0, 1, 0);
	FPF(mEddieRun.getFrames(), mEddieRun.getFPFLimit());
	glPopMatrix();
	//if (!Hitbox(_objCoordsX, _objCoordsY, _objCoordsZ))
	//{
	//	return true;

	//}
}

void Player::Hit()
{
	glPushMatrix();
	glRotatef(getRotation(), 0, 1, 0);
	glTranslatef(mPlayerCoords.x, mPlayerCoords.y, mPlayerCoords.z);
	//validar colision
	FPF(mEddieHit.getFrames(), mEddieHit.getFPFLimit());
	glPopMatrix();
}

void Player::Move(char pMove)
{
	switch (pMove)
	{
	case 'f':
		mPlayerCoords.z -= 1; //cambiar por speed
		//ir sumando o restando en la variable rotate
		setRotation(180);
		break;

	case 'b':
		mPlayerCoords.z += 1; //cambiar por speed
		setRotation(0);
		break;

	case 'l':
		mPlayerCoords.x -= 1; //cambiar por speed
		setRotation(270);
		break;

	case 'r':
		mPlayerCoords.x += 1; //cambiar por speed
		setRotation(90);
		break;

	}

	//cambiar direccion

	//if (pKeys[0])
	//{
	//	mPlayerCoords.z += 1; //cambiar por speed
	//	//mDir = TO_DEG(atan2(mMagnitudZ, mMagnitudX));
	//}
	//if (pKeys[1])
	//{
	//	mPlayerCoords.z -= 1; //cambiar por speed
	//}
	//if (pKeys[2])
	//{
	//	mPlayerCoords.x -= 1; //cambiar por speed
	//}
	//if (pKeys[3])
	//{
	//	mPlayerCoords.x += 1; //cambiar por speed
	//}
	
	//recibir las llaves
	//mover de acuerdo a lo que se reciba
	//función move de cámara

	//cuantas teclas se están presionando a la vez?
}

//GETTERS / SETTERS
void Player::setPositions(CoordsXYZ actCoords)
{
	mPlayerCoords.x = actCoords.x;
	mPlayerCoords.y = actCoords.y;
	mPlayerCoords.z = actCoords.z;
}

CoordsXYZ Player::getPositions()
{ return mPlayerCoords; }

Player::~Player()
{
	mEddieHit.DeleteAnimation();
	mEddieIdle.DeleteAnimation();
	mEddieRun.DeleteAnimation();
}
//
//double Player::getPositionX()
//{ return mPlayerCoords.x; }
//
//double Player::getPositionY()
//{ return mPlayerCoords.y; }