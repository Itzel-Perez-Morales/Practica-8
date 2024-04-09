#include "Animations.h"

Animations::Animations() {};

Animations::Animations(short index, short currentSpeed, float positionTraslate, float positionStart, float positionEnd, float rotation, float actualSize, float sizeLimit, float sizeMini, bool statusSmall, bool statusUp, bool statusDown, bool statusBack, bool statusFront)
{
	Animations::index = index;
	speed = currentSpeed;
	position = positionTraslate;
	Animations::positionStart = positionStart;
	Animations::positionEnd = positionEnd;
	Animations::rotation = rotation;
	size = actualSize;
	Animations::sizeLimit = sizeLimit;
	Animations::sizeMini = sizeMini;
	sizeSmall = statusSmall;
	up = statusUp;
	down = statusDown;
	back = statusBack;
	front = statusFront;
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
	if (position <= positionEnd && position >= positionStart && up == false)
	{
		position += increment;
		if (position >= positionEnd)
		{
			up = true;
			down = false;
		}
	}
	else
	{
		if (position <= positionStart)
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
		rotation += increment;
		if (rotation >= limit)
		{
			back = false;
			front = true;
		}
	}
	else
	{
		rotation -= increment;
		if (rotation <= -1 * limit)
		{
			front = false;
			back = true;
		}
	}
}

void Animations::GoAcross(double &posiStart, double posiEnd, double &angleStart, double angleEnd, bool& _status)
{
	if (posiStart >= posiEnd)
		posiStart -= 1;

	else
	{
		if (angleStart > angleEnd)
			angleStart -= 1;
		else
			_status = true;
	}
}

void Animations::AddFrames(Frames* frame)
{
	animFrames.push_back(frame);
}


void Animations::FPF(vector<Frames*>& _model, short limit)
{
	if (index < limit)
	{
		_model[index]->Draw(); // Usar index en lugar de i
		index += 1;
	}
	else
	{
		index = 0;
		_model[index]->Draw(); // Usar index en lugar de i
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

vector<Frames*> Animations::getFrames()
{ return animFrames; }

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

short Animations::getFPFLimit()
{ return limit; }

short Animations::getTime()
{ return time; }

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

void Animations::setFPFLimit(short fpf)
{ limit = fpf; }


void Animations::setTime(short _time)
{ time = _time; }


void Animations::DeleteAnimation()
{
	for (int i = 0; i < limit; i++)
	{ delete animFrames[i]; }
}

Animations::~Animations()
{ animFrames.clear(); }