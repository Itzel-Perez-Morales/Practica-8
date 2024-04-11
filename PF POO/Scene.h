#include <gl\GLU.h>
#include <gl\GL.h>
#include "SkyDome.h"
#include "Terrain.h"
#include "Model.h"
#include "Water.h"
#include "Billboard.h"
#include "Fog.h"
#include "Camera.h"

#define BILLSIZE 50

//BIENVENIDO AL ARCHIVO MAS IMPORTANTE DE TU PROYECTO
using namespace EDXFramework;

//template<typename ModelType>
//void RenderObjects(ModelType& model, double _x, double _y, double _z)
//{
//	glPushMatrix();
//	glTranslatef(_x, _y, _z);
//	model->Draw();
//	glPopMatrix();
//}
//
//template<typename ModelType>
//bool CheckColisions(ModelType& model, CoordsXYZ pCoords)
//{
//	if (model->CheckHitbox(pCoords))
//		return true;
//	else
//		return false;
//}

class Scene : public Camera
{
public:
	HWND hWnd = 0;
	bool mGameStarted = false, mGameInitialize = false, mKeyMovePressed = false;
	bool mKey[4]{ 0 ,0 ,0, 0 }; //[0] = w, [1] = s, [2] = a , [3] = d
	//bool mKeyW = false, mKeyS = false, mKeyA= false, mKeyD = false;
	short int skyIndex, lightIndex;
	float skyRotation;// , bunnyRotation, bunnyPosition = 25;
	//Camera thirdPerson;
	SkyDome* skyDome = new SkyDome(hWnd, 32, 32, 500, L"Imagenes//sky.png", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	Terrain* terrain = new Terrain(hWnd, L"Imagenes//heigthmap.bmp", L"Imagenes//grassTexture.jpg", L"Imagenes//grassTexture.jpg", 530, 530); //terreno con el tamaño de la plantilla
	//Terrain* terrain = new Terrain(hWnd, L"Imagenes//heigthmap.bmp", L"Imagenes//grassTexture.jpg", L"Imagenes//grassTexture.jpg", 1060, 1060); //terreno con el doble de tamaño
	Water* lake = new Water(hWnd,L"Imagenes//heightmapLake.bmp",L"Imagenes//lake2.bmp",550,550); //para el terreno og. 
	//Water* lake = new Water(hWnd, L"Imagenes//heightmapLake.bmp", L"Imagenes//lake2.bmp", 1100, 1100); //para 2x terreno
	GLfloat AmbMat[4] = { 255, 255, 220, 1 };
	Fog* fog = new Fog();

	Billboard* billBoard[BILLSIZE];

	Scene(HWND hWnd)
	{
		this->hWnd = hWnd;
		skyIndex = lightIndex, skyRotation = 0;

		GLfloat AmbPos[] = { 0, 400, 400, 1 };

		glShadeModel(GL_SMOOTH);
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_LIGHTING);
		glMaterialfv(GL_FRONT, GL_AMBIENT, AmbMat);
		glEnable(GL_NORMALIZE);
		glEnable(GL_LIGHT0);
		glLightfv(GL_LIGHT0, GL_POSITION, AmbPos);
		
		Billboards(billBoard, hWnd);
		cameraInitialize();
	}

	void Billboards(Billboard* bills[], HWND hWnd)
	{
		//Aqui puedes crear algo util con un FOR quiza.
	}

	void Render(HDC hDC)
	{
		glMaterialfv(GL_FRONT, GL_AMBIENT, AmbMat);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0, 0, 0, 0);
		glLoadIdentity();

		float AmbInt[] = { 0.1, 0.1, 0.1, 1 };
		glLightfv(GL_LIGHT0, GL_AMBIENT, AmbInt);

		if (!mGameStarted && !mGameInitialize)//si el juego aun no inicia, conservar estas coordenadas para la camara, si no, mandar estas al jugador
		{ mCoords.y = terrain->Superficie(mCoords.x, mCoords.z) * 4 + 12; }

		cameraUpdate();

		skyDome->Move();

		//Terreno
		glPushMatrix();
		glScalef(1, 4, 1);
		terrain->Draw();
		glPopMatrix();

		if (mCoords.y < 34.5 && !mGameStarted)
		{ 
			fog->density = 0.025;
			fog->draw(); 
		}
		else
		{	fog->density = 0;
			fog->draw();
		}

		lake->Move();

		for (int i = 0; i < BILLSIZE; i++)
			//Aqui puede ir algo en especial, en tu carpeta de HEADER_FILES, el primer archivo es la respuesta.
			glPopMatrix();

		SwapBuffers(hDC);
	}

	void SaveCoords() //para colisión
	{
		mPastCoords.x = mCoords.x;
		mPastCoords.y = mCoords.y;
		mPastCoords.z = mCoords.z;
	}

	~Scene()
	{
		//M O D E L O S
		delete skyDome;
		delete terrain;
		delete lake;
	}
};