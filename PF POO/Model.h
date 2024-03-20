#pragma once
#include <string>
#include "glm.h"
#include "BMPLoader.h"
#include "Colision.h"
#include "Animations.h"
using namespace std;

namespace EDXFramework
{
	class Model : virtual public Colision, virtual public Animations
	{
		GLMmodel* model;
		BMPClass texture;
		unsigned int textureId;
		unsigned int drawMode;
	public:
		Model();
		Model(bool colisionStatus, double cX, double cY, double cZ, double cRX, double cRY, double cRZ, short i, short aSpeed, float pos, float pS, float pE, float rot, float actSize, float sizeL, float sizeM, bool sS, bool stUp, bool stDown, bool stBack, bool stFront, string modelPath, string texturePath, bool mode);
		void Draw();
		virtual ~Model();
	};
}