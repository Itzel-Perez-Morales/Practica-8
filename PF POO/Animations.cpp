#include "Animations.h"

Animations::Animations() {};

Animations::Animations(short i, short aSpeed, float pos, float pS, float pE, float rot, float actSize, float sizeL, float sizeM, bool sS, bool stUp, bool stDown, bool stBack, bool stFront)
{
	index = i; 
	speed = aSpeed;
	position = pos;
	positionStart = pS;
	positionEnd = pE;
	rotation = rot;
	size = actSize;
	sizeLimit = sizeL;
	sizeMini = sizeM;
	sizeSmall = sS;
	up = stUp;
	down = stDown;
	back = stBack;
	front = stFront;
}

void Animations::Spin(float increment, float limit)
{
	if (rotation < limit)
	{
		rotation += increment;
	}
	else
	{
		rotation = 0;
	}
}

void Animations::MoveUpNDown(float increment)
{
	if (position < up && position >= down && up == false)
	{
		position += increment;
		if (position >= positionStart)
		{
			up = true;
			down = false;
		}
	}
	else
	{
		if (position <= positionEnd)
		{
			up = false;
			down = true;
		}
		if (down == false)
		{
			position -= increment;
		}
	}
}

void Animations::Resizing(float increment)
{
	if (size < sizeLimit && sizeSmall == true)
	{
		size += increment;
		if (size >= sizeLimit)
		{
			sizeSmall = false;
		}
	}
	else
	{
		size -= increment;
		if (size <= sizeMini)
		{
			sizeSmall = true;
		}
	}


}

void Animations::RotateFrontTBack(float increment, float limit)
{
	if (front == false)
	{
		rotation += 5;
		if (rotation >= 45)
		{
			back = false;
			front = true;
		}
	}
	else
	{
		rotation -= 5;
		if (rotation <= -45)
		{
			front = false;
			back = true;
		}
	}
}

template<typename modelType>
void Animations::FPF(short i)
{
	if (i <= index)
	{
		modelType[i] ->Draw();
		i += 1;
	}
	else
	{
		i = 0;
		modelType[i]->Draw();
	}
}

// Getters / Setters
short Animations::getIndex()
{
	return index;
}

short Animations::getSpeed()
{
	return speed;
}

float Animations::getPosition()
{
	return position;
}

float Animations::getPositionStart()
{
	return positionStart;
}

float Animations::getPositionEnd()
{ return positionEnd;}

float Animations::getRotation()
{ return rotation; }

float Animations::getSize()
{ return size; }

float Animations::getSizeLimit()
{ return sizeLimit; }

float Animations::getSizeMini()
{ return sizeMini; }

bool Animations::getSizeSmall()
{ return sizeSmall; }

bool Animations::getUp()
{ return up; }

bool Animations::getDown()
{ return down; }

void Animations::setIndex(short i)
{ index = i; }

void Animations::setSpeed(short aSpeed)
{ speed = aSpeed; }

void Animations::setPosition(float pos)
{ position = pos; }

void Animations::setPositionStart(float pS)
{ positionStart = pS; }

void Animations::setPositionEnd(float pE)
{ positionEnd = pE; }

void Animations::setRotation(float rot )
{ rotation = rot; }

void Animations::setSize(float actSize)
{ size = actSize; }

void Animations::setSizeSmall(bool sS)
{ sizeSmall = sS; }

void Animations::setSizeLimit(float sL)
{ sizeLimit = sL; }

void Animations::setSizeMini(float sM)
{ sizeMini = sM; }

void Animations::setUp(bool stUp)
{ up = stUp; }

void Animations::setDown(bool stDown)
{ down = stDown; }