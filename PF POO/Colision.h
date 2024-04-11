#pragma once
//#include "Scene.h" //cambiar a model 
#include "CoordsXYZ.h"

class Colision
{
	CoordsXYZ coordsColision;
	CoordsXYZ coordsColRadio;

//	double colisionX, colisionY, colisionZ, colCenterX, colCenterY, colCenterZ;

public:
	Colision();
	Colision(double colisionPointX, double colisionPointY, double colisionPointZ, double colisionRadioX, double colisionRadioY, double colisionRadioZ);
	//Para hacer una colision dinamica se tendria que mandar la posicion actual de la instancia en x,y,z
	bool Hitbox(CoordsXYZ objCoords);
	bool HitboxPtP(CoordsXYZ objCoords);

	// Setters / Getters
	CoordsXYZ getColisionCoords();
	CoordsXYZ getRadioCoords();
	double getCoordsColisionX();
	double getCoordsColisionY();
	double getCoordsColisionZ();
	double getCoordsColRadioX();
	double getCoordsColRadioY();
	double getCoordsColRadioZ();
	void setCoordsColision(double x, double y, double z);
	void setCoordsColRadio(double x, double y, double z);
};
