#pragma once
#include <vector>
#include "Frames.h"
using namespace EDXFramework;

class Animations
{
	short index, animationSpeed, limit; //index recorrera el array, limit establece hasta que numero se recorre
	float position, positionStart, positionEnd, rotation, size, sizeLimit, sizeMini;
	bool sizeSmall, up, down, front, back;
	vector<Frames*> animFrames; 
public:
	Animations();
	Animations(short index, short currentSpeed, float positionTraslate, float positionStart, float positionEnd, float rotation, float actualSize, float sizeLimit, float sizeMini, bool statusSmall, bool statusUp, bool statusDown, bool statusBack, bool statusFront);
	
	void Spin(float increment, float limit);
	void MoveUpNDown(float increment);
	void Resizing(float increment);
	void RotateFrontTBack(float increment, float limit);
	void GoAcross(double &posiStart, double posiEnd, double &angleStart, double angleEnd, bool& _status);
	//FPF
	void AddFrames(Frames* frames);
	void FPF(vector<Frames*>& _frames, short limit);

	//Setters / Getters
	bool getDown();
	bool getSizeSmall();
	bool getUp();
	float getPosition();
	float getPositionStart();
	float getPositionEnd();
	float getRotation();
	float getSize();
	float getSizeLimit();
	float getSizeMini();
	short getFPFLimit();
	short getIndex();
	float getAnimationSpeed();
	float getTime();
	vector<Frames*> Animations::getFrames();

	void setTime(float _time);
	void setIndex(short i);
	void setAnimationSpeed(float aSpeed);
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
	void setFPFLimit(short fpf);
	void DeleteAnimation();
	~Animations();
};
