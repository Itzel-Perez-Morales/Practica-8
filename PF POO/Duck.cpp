#include "Duck.h"

Duck::Duck(string pModelPath, string pTexturePath, bool pMode, 
	short pIndex, short pCurrentSpeed, float pPositionTraslate, float pPositionStart, float pPositionEnd, float pRotation, float pActualSize,
	float pSizeLimit, float pSizeMini, bool pStatusSmall, bool pStatusUp, bool pStatusDown, bool pStatusBack, bool pStatusFront, float pDuckRotation, short pPositionX, short pPositionY, short pPositionZ) :
	Model(pModelPath, pTexturePath, pMode),
	Animations(pIndex, pCurrentSpeed, pPositionTraslate, pPositionStart, pPositionEnd, pRotation, pActualSize, pSizeLimit, pSizeMini, pStatusSmall, pStatusUp, pStatusDown, pStatusBack, pStatusFront)

{
	mDuckCoords.x = pPositionX;
	mDuckCoords.y = pPositionY;
	mDuckCoords.z = pPositionZ;
	mDuckRotation = pDuckRotation;
	mSwimRotation = 180;
	mMoveFront = true;
	mMoveBack = false;
	mMoveRight = false;
	mMoveLeft = false;
}

void Duck::Swim()
{
	RotateFrontTBack(5, 45);

	if (mMoveFront && mDuckCoords.x > -65)
	{
		mDuckCoords.x -= 0.1;
		if (mDuckCoords.x <= -65)
		{
			mMoveFront = false;
			mMoveLeft = true;
			mSwimRotation = 270;
		}
	}
	else
	{
		if (mMoveLeft && mDuckCoords.z < 45)
		{
			mDuckCoords.z += 0.1;
			if (mDuckCoords.z >= 45)
			{
				mMoveLeft = false;
				mMoveBack = true;
				mSwimRotation = 0;
			}
		}
		else
		{
			if (mMoveBack && mDuckCoords.x < 40)
			{
				mDuckCoords.x += 0.1;
				if (mDuckCoords.x >= 40)
				{
					mMoveBack = false;
					mMoveRight = true;
					mSwimRotation = 90;
				}
			}
			else
			{
				if (mMoveRight && mDuckCoords.z > -10)
				{
					mDuckCoords.z -= 0.1;
					if (mDuckCoords.z <= -10)
					{
						mMoveRight = false;
						mMoveFront = true;
						mSwimRotation = 180;
					}
				}
			}
		}
	}

	glPushMatrix();
	glTranslatef(mDuckCoords.x, mDuckCoords.y, mDuckCoords.z);
	glRotatef(mSwimRotation, 0, 1, 0);
	glRotatef(getRotation(), 1, 0, 1);
	Draw();
	glPopMatrix();
}