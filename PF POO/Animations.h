#pragma once

class Animations
{
	short index, speed;
	float position, positionStart, positionEnd, rotation, size, sizeLimit, sizeMini;
	bool sizeSmall, up, down, front, back;

public:
	Animations();
	Animations(short i, short aSpeed, float pos, float pS, float pE, float rot, float actSize, float sizeL, float sizeM, bool sS, bool stUp, bool stDown, bool stBack, bool stFront);
	
	void Spin(float increment, float limit);
	void MoveUpNDown(float increment);
	void Resizing(float increment);
	void RotateFrontTBack(float increment, float limit);
	template<typename modelType>
	void FPF(short i);

	// Setters / Getters
	short getIndex();
	short getSpeed();
	float getPosition();
	float getPositionStart();
	float getPositionEnd();
	float getRotation();
	float getSize();
	float getSizeLimit();
	float getSizeMini();
	bool getSizeSmall();
	bool getUp();
	bool getDown();
	void setIndex(short i);
	void setSpeed(short aSpeed);
	void setPosition(float pos);
	void setPositionStart(float pS);
	void setPositionEnd(float pE);
	void setRotation(float rot);
	void setSize(float actSize);
	void setSizeLimit(float sL);
	void setSizeMini(float sM);
	void setSizeSmall(bool sS);
	void setUp(bool stUp);
	void setDown(bool stDown);
};
