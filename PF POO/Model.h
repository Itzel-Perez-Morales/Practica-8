#pragma once
//#include <iterator>
//#include <algorithm>
//#include<vector>
#include <string>
#include "glm.h"
#include "BMPLoader.h"
using namespace std;

namespace EDXFramework
{
	class Model
	{
		GLMmodel* mModel;
		BMPClass mTexture;
		unsigned int mTextureId;
		unsigned int mDrawMode;
	public:
		Model();
		Model(string pModelPath, string pTexturePath, bool pMode);
		virtual ~Model();
		void Draw();
	};
}
//std::vector<string> texturePath;
//std::vector<GLuint> textureID;