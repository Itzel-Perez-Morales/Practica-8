#pragma once
#include <string>
using namespace std;
#include "glm.h"
#include "BMPLoader.h"

#pragma once
#include <string>
#include "glm.h"
#include "BMPLoader.h"
#include "Colision.h"
using namespace std;

namespace EDXFramework
{
	class Model : public Colision
	{
		GLMmodel* model;
		BMPClass texture;
		unsigned int textureId;
		unsigned int drawMode;
	public:
		Model();
		Model(bool colisionStatus, double cX, double cY, double cZ, double cRX, double cRY, double cRZ, string modelPath, string texturePath, bool mode);
		void Draw();
		virtual ~Model();
	};
}