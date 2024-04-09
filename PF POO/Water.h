#ifndef _wata
#define _wata
#include "Geometrias.h"
#include "Imagenes.h"
//#include "ShaderDemo.h"

class Water : public Primitivos, public Imagenes
{

private:
	float mWide;
	float mDeep;
	float mDeltaX, mDeltaZ;
	//ShaderDemo *gpuDemo;

public:

	Maya mWater;
	int mVerX, mVerZ;
	//el nombre numerico de la textura en cuestion, por lo pronto una
	unsigned int mTextureMap;

	Water(HWND hWnd, WCHAR pHeightMap[], WCHAR pTexture[], float pWide, float pDeep)
	{
		mWide = pWide;
		mDeep = pDeep;
		//cargamos la textura de la figura
		Carga(pHeightMap);
		//en caso del puntero de la imagen sea nulo se brica esta opcion
		mWater = Plano(Ancho(), Alto(), pWide, pDeep, Dir_Imagen(), 30);
		mDeltaX= mWide / Ancho();
		mDeltaZ = mDeep / Alto();
		mVerX = Ancho();
		mVerZ = Alto();
		//disponemos la textura del gdi.
		Descarga();

		Carga(pTexture);
		glGenTextures(1, &mTextureMap);
		glBindTexture(GL_TEXTURE_2D, mTextureMap);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
		gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, Ancho(), Alto(), GL_RGBA, GL_UNSIGNED_BYTE, Dir_Imagen());
		Descarga();

		//gpuDemo = new ShaderDemo("basic.vert", "basic.frag");
		//gpuDemo->ligador(gpuDemo->vertShader, gpuDemo->fragShader);
	}

	~Water()
	{
		//nos aseguramos de disponer de los recursos previamente reservados
		delete mWater.maya;
		delete mWater.indices;
		glDeleteTextures(1, &mTextureMap);
	}


	void Draw()
	{
		static float moveWater = 0; //cuanto se moverá el agua?
		float posYMin = 32;
		moveWater += 0.15; //entre más alto el valor, más rápido se moverá
		float waterAnimationY = posYMin + sin(moveWater); //posicion y del agua
		glPushAttrib(GL_CURRENT_BIT | GL_TEXTURE_BIT);
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_BLEND);
		static float water_factor_min = 40.0f; 
		static float water_factor_max = 60.0f;
		static float water_size = 200;
		water_factor_min += .003f;
		water_factor_max += .003f;
		if (water_factor_min > 1200)
		{
			water_factor_min = 40.0f;
			water_factor_max = 60.0f;
		}
		glBindTexture(GL_TEXTURE_2D, mTextureMap);
		glBegin(GL_QUADS);
		glTexCoord2f(water_factor_min, water_factor_min);
		glColor4f(0.1f, 0.3f, 0.6f, 0.1f);
		glVertex3f(-water_size, waterAnimationY, water_size);

		glTexCoord2f(water_factor_max, water_factor_min);
		glColor4f(0.1f, 0.3f, 0.6f, 0.1f);
		glVertex3f(water_size, waterAnimationY, water_size);

		glTexCoord2f(water_factor_max, water_factor_max);
		glColor4f(0.1f, 0.3f, 0.6f, 0.1f);
		glVertex3f(water_size, waterAnimationY, -water_size);

		glTexCoord2f(water_factor_min, water_factor_max);
		glColor4f(0.1f, 0.3f, 0.6f, 0.1f);
		glVertex3f(-water_size, waterAnimationY, -water_size);
		glEnd();
		glPopAttrib();
		glDisable(GL_DEPTH_TEST);
		//-------------

	}
};

#endif 