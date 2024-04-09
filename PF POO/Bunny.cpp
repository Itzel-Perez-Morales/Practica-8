#pragma once
#include "Bunny.h"

Bunny::Bunny(double colisionPointX, double colisionPointY, double colisionPointZ, double colisionRadioX, double colisionRadioY,
	double colisionRadioZ, short index, short currentSpeed, float positionTraslate, float positionStart, float positionEnd, float rotation, float actualSize,
	float sizeLimit, float sizeMini, bool statusSmall, bool statusUp, bool statusDown, bool statusBack, bool statusFront, short indexCatch) :
	Colision(colisionPointX, colisionPointY, colisionPointZ, colisionRadioX, colisionRadioY, colisionRadioZ),
	Animations(index, currentSpeed, positionTraslate, positionStart, positionEnd, rotation, actualSize, sizeLimit, sizeMini, statusSmall, statusUp, statusDown, statusBack, statusFront)
{
	CatchCarrot.AddFrames(new Frames("Modelos//Bunny//Catch//C0.obj", "Modelos//Bunny//Bunny.V.1.bmp", 1));
	CatchCarrot.AddFrames(new Frames("Modelos//Bunny//Catch//C1.obj", "Modelos//Bunny//Bunny.V.1.bmp", 1));
	CatchCarrot.AddFrames(new Frames("Modelos//Bunny//Catch//C2.obj", "Modelos//Bunny//Bunny.V.1.bmp", 1));
	CatchCarrot.AddFrames(new Frames("Modelos//Bunny//Catch//C3.obj", "Modelos//Bunny//Bunny.V.1.bmp", 1));
	CatchCarrot.AddFrames(new Frames("Modelos//Bunny//Catch//C4.obj", "Modelos//Bunny//Bunny.V.1.bmp", 1));
	CatchCarrot.AddFrames(new Frames("Modelos//Bunny//Catch//C5.obj", "Modelos//Bunny//Bunny.V.1.bmp", 1));
	CatchCarrot.AddFrames(new Frames("Modelos//Bunny//Catch//C6.obj", "Modelos//Bunny//Bunny.V.1.bmp", 1));
	CatchCarrot.AddFrames(new Frames("Modelos//Bunny//Catch//C7.obj", "Modelos//Bunny//Bunny.V.1.bmp", 1));
	CatchCarrot.AddFrames(new Frames("Modelos//Bunny//Catch//C8.obj", "Modelos//Bunny//Bunny.V.1.bmp", 1));
	CatchCarrot.AddFrames(new Frames("Modelos//Bunny//Catch//C9.obj", "Modelos//Bunny//Bunny.V.1.bmp", 1));
	CatchCarrot.AddFrames(new Frames("Modelos//Bunny//Catch//C10.obj", "Modelos//Bunny//Bunny.V.1.bmp", 1));
	CatchCarrot.AddFrames(new Frames("Modelos//Bunny//Catch//C11.obj", "Modelos//Bunny//Bunny.V.1.bmp", 1));
	CatchCarrot.AddFrames(new Frames("Modelos//Bunny//Catch//C12.obj", "Modelos//Bunny//Bunny.V.1.bmp", 1));
	CatchCarrot.AddFrames(new Frames("Modelos//Bunny//Catch//C13.obj", "Modelos//Bunny//Bunny.V.1.bmp", 1));
	CatchCarrot.AddFrames(new Frames("Modelos//Bunny//Catch//C14.obj", "Modelos//Bunny//Bunny.V.1.bmp", 1));
	CatchCarrot.setFPFLimit(indexCatch);
	Status = false;
	CarrotTaken = false;
	coords.x = colisionPointX;
	coords.y = colisionPointY;
	coords.z = colisionPointZ;
	//EddieRun[0] = new Frames(11, 20, 0, 0, 0, 0, 0, 0 , 0, 0, 0, 0, 0, 0, false, 0, 0, 0, 0, 0, 0, "Modelos//Player//Run//R0.obj", "Modelos//Player//Player.bmp", 1);
}

void Bunny::Catch()
{
	if (!Status)
	{
		Spin(100, 360);
		MoveUpNDown(0.250);
	}

	if (getUp() && !getDown() && !CarrotTaken)
	{
		Status = true;
	}

	glPushMatrix();
	glTranslatef(coords.x, getPosition(), coords.y);
	glRotatef(getRotation(), 0, 1, 0);

	if (!CarrotTaken && getUp() && !getDown() && Status)
	{
		if (CatchCarrot.getIndex() <= CatchCarrot.getFPFLimit() && Status) //checar
		{
			CatchCarrot.getFrames()[CatchCarrot.getIndex()]->Draw();
			CatchCarrot.setIndex(CatchCarrot.getIndex() + 1);
		}
		else
		{
			CatchCarrot.setIndex(0);
			CatchCarrot.getFrames()[CatchCarrot.getIndex()]->Draw();
			Status = false;
			CarrotTaken = true;
		}
	}
	else
	{
		if (Status)
		{ CatchCarrot.getFrames()[CatchCarrot.getFPFLimit() - 1]->Draw(); }
		else
		{ CatchCarrot.getFrames()[0]->Draw(); }
	}
	//validar colision
	glPopMatrix();
}

bool Bunny::getCarrotTaken()
{ return CarrotTaken; }

void Bunny::setCarrotsX(float posX)
{
	coords.x = posX;
}
void Bunny::setCarrotsY(float posY)
{
	coords.y = posY;
}
void Bunny::setCarrotsZ(float posZ)
{
	coords.z = posZ;
}
double Bunny::getCarrotsX()
{
	return coords.x;
}
double Bunny::getCarrotsY()
{
	return coords.y;
}
double Bunny::getCarrotsZ()
{
	return coords.z;
}


Bunny::~Bunny()
{ CatchCarrot.DeleteAnimation(); }