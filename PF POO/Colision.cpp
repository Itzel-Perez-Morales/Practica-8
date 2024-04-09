#include "Colision.h"

Colision::Colision() {};

Colision::Colision(double colisionPointX, double colisionPointY, double colisionPointZ, double colisionRadioX, double colisionRadioY, double colisionRadioZ)
{
	coordsColision.x = colisionPointX;
	coordsColision.y = colisionPointY;
	coordsColision.z = colisionPointZ;
	coordsColRadio.x = colisionRadioX;
	coordsColRadio.y = colisionRadioY;
	coordsColRadio.z = colisionRadioZ;
}

bool Colision::Hitbox(CoordsXYZ objCoords)
{
	if (objCoords.x >= coordsColision.x - coordsColRadio.x && objCoords.x <= coordsColRadio.x + coordsColision.x)
		//objCoordX >= colisionX - colCenterX && objCoordX <= colCenterX + colisionX)
	{
		if (objCoords.z <= coordsColision.z + coordsColRadio.z && objCoords.z >= coordsColision.z - coordsColRadio.z)
			//objCoordZ <= colisionZ + colCenterZ && objCoordZ >= colisionZ - colCenterZ)
		{
			return true;
		}
		return false;
	}
	else
	{
		return false;
	}
}

bool Colision::HitboxPtP(CoordsXYZ objCoords)
{
	if (objCoords.x <= coordsColision.x + coordsColRadio.x && objCoords.x >= coordsColision.x)
		//objCoordX <= colisionX + colCenterX && objCoordX >= colisionX)
	{
		if (objCoords.z <= coordsColision.z + coordsColRadio.z && objCoords.z >= coordsColision.z)
			//objCoordZ <= colisionZ + colCenterZ && objCoordZ >= colisionZ)
		{
			return true;
		}
		return false;
	}
	else
	{
		return false;
	}
};


// Getters / Setters
double Colision::getCoordsColisionX()
{
	return coordsColision.x;
}

double Colision::getCoordsColRadioX()
{
	return coordsColRadio.x;
}

double Colision::getCoordsColisionY()
{
	return coordsColision.y;
}

double Colision::getCoordsColRadioY()
{
	return coordsColRadio.y;
}

double Colision::getCoordsColisionZ()
{
	return coordsColision.z;
}

double Colision::getCoordsColRadioZ()
{
	return coordsColRadio.z;
}

void Colision::setCoordsColision(double x, double y, double z)
{
	coordsColision.x = x;
	coordsColision.y = y;
	coordsColision.z = z;
}

void Colision::setCoordsColRadio(double x, double y, double z)
{
	coordsColRadio.x = x;
	coordsColRadio.y = y;
	coordsColRadio.z = z;
}
