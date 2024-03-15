#include "Colision.h"

Colision::Colision() {};

Colision::Colision(bool colisionStatus, double cX, double cY, double cZ, double cRX, double cRY, double cRZ)
{
	colliding = colisionStatus;
	colisionX = cX;
	colisionY = cY;
	colisionZ = cZ;
	colCenterX = cRX;
	colCenterY = cRY;
	colCenterZ = cRZ;
}

bool Colision::Hitbox(double objCoordX, double objCoordY, double objCoordZ)
{
	if (objCoordX >= colisionX && objCoordX <= colCenterX + colisionX)
	{
		if (objCoordZ <= colisionZ + colCenterZ && objCoordZ >= colisionZ)
		{
			//scene->positionX = scene->antPosX;
			//scene->positionZ = scene->antPosZ;
			return true;
		}
	}
}

// Getters / Setters
double Colision::getColisionX()
{
	return colisionX;
}

double Colision::getColisionY()
{
	return colisionY;
}

double Colision::getColisionZ()
{
	return colisionZ;
}

double Colision::getColCenterX()
{
	return colCenterX;
}

double Colision::getColCenterY()
{
	return colCenterY;
}

double Colision::getColCenterZ()
{
	return colCenterZ;
}

bool Colision::getColliding()
{
	return colliding;
}

void Colision::setColisionX(double cX)
{
	colisionX = cX;
}

void Colision::setColisionY(double cY)
{
	colisionY = cY;
}

void Colision::setColisionZ(double cZ)
{
	colisionZ = cZ;
}

void Colision::setColCenterX(double cRX)
{
	colCenterX = cRX;
}

void Colision::setColCenterY(double cRY)
{
	colCenterY = cRY;
}

void Colision::setColCenterZ(double cRZ)
{
	colCenterZ = cRZ;
}

void Colision::setColliding(bool col)
{
	colliding = col;
}