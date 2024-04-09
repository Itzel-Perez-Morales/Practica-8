#include "Model.h"
using namespace EDXFramework;

Model::Model()
{
}

Model::Model(string pModelPath, string pTexturePath, bool mMode) : mTextureId(0)
{
	if (mMode == 0)
		mDrawMode = GLM_FLAT | GLM_MATERIAL;
	else if (mMode == 1)
		mDrawMode = GLM_SMOOTH | GLM_MATERIAL;
	mModel = glmReadOBJ((char*)pModelPath.c_str());
	glmFacetNormals(mModel);
	glmVertexNormals(mModel, 90.0);
	//Load Texture
	BMPError e = BMPLoad(pTexturePath, mTexture);;
	if (e == BMPNOERROR) {
		mDrawMode |= GLM_TEXTURE;
		glGenTextures(1, &mTextureId);
		glBindTexture(GL_TEXTURE_2D, mTextureId);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, mTexture.width, mTexture.height, 0, GL_RGB, GL_UNSIGNED_BYTE, mTexture.bytes);
	}
}

void Model::Draw()
{
	if (mDrawMode & GLM_TEXTURE)
	{
		glBindTexture(GL_TEXTURE_2D, mTextureId);
	}
	glmDraw(mModel, mDrawMode);
	glBindTexture(GL_TEXTURE_2D, NULL);
}


//GLuint Model::LoadTexture(const string& _texturePath)
//{
//	auto path = std::find(texturePath.begin(), texturePath.end(), _texturePath); //auto es para tomar el tipo que resulte de la función
//	if (path != texturePath.end())
//	{
//		int pathIndex = std::distance(texturePath.begin(), path);
//		return textureID.at(pathIndex);
//	}
//	else
//	{
//		BMPError loadStatus = BMPLoad(_texturePath, mTexture); //carga la textura y le asigna el estado
//		if (loadStatus == BMPNOERROR)
//		{
//			mDrawMode |= GLM_TEXTURE;
//			GLuint _textureID;
//			glGenTextures(1, &_textureID); //genera ID
//			glBindTexture(GL_TEXTURE_2D, _textureID);
//			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
//			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
//			glTexImage2D(GL_TEXTURE_2D, 0, 3, mTexture.width, mTexture.height, 0, GL_RGB, GL_UNSIGNED_BYTE, mTexture.bytes);
//			textureID.push_back(_textureID);
//			texturePath.push_back(_texturePath);
//			mTextureID = _textureID;
//			mTexturePath = _texturePath;
//			return _textureID;
//		}
//	}
//	return 0;
//}
//
//void Model::Draw(GLuint actualTexture) //especificar la textura actual
//{
//	if (mDrawMode & GLM_TEXTURE)
//	{
//		glBindTexture(GL_TEXTURE_2D, textureID.at(actualTexture));
//	}
//	glmDraw(mModel, mDrawMode);
//	glBindTexture(GL_TEXTURE_2D, NULL);
//}
//GLuint Model::getTextureID()
//{ return mTextureID; }

Model::~Model()
{ glmDelete(mModel);}