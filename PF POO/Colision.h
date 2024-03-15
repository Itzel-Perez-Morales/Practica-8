#pragma once

class Colision
{
	double colisionX, colisionY, colisionZ, colCenterX, colCenterY, colCenterZ;
	bool colliding;

public:
	Colision();
	Colision(bool colisionStatus, double cX, double cY, double cZ, double cRX, double cRY, double cRZ);
	bool Hitbox(double objCoordX, double objCoordY, double objCoordZ);

	// Setters / Getters
	double getColisionX();
	double getColisionY();
	double getColisionZ();
	double getColCenterX();
	double getColCenterY();
	double getColCenterZ();
	bool getColliding();
	void setColisionX(double cX);
	void setColisionY(double cY);
	void setColisionZ(double cZ);
	void setColCenterX(double cRX);
	void setColCenterY(double cRY);
	void setColCenterZ(double cRZ);
	void setColliding(bool col);
};
