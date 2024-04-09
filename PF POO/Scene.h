#include <gl\GLU.h>
#include <gl\GL.h>
#include "SkyDome.h"
#include "Terrain.h"
#include "Model.h"
#include "Water.h"
#include "Billboard.h"
#include "Fog.h"
#include "Camera.h"
#include "Items.h"
#include "Veggies.h"
#include "Duck.h"
#include "Barn.h"
#include "Player.h"
#include "Bunny.h"
#include "VeggiesCamp.h"
#include "Railing.h"
#include "ModelWColision.h"

#define BILLSIZE 50

//BIENVENIDO AL ARCHIVO MAS IMPORTANTE DE TU PROYECTO
using namespace EDXFramework;

template<typename ModelType>
void RenderObjects(ModelType& model, double _x, double _y, double _z)
{
	glPushMatrix();
	glTranslatef(_x, _y, _z);
	model->Draw();
	glPopMatrix();
}

template<typename ModelType>
bool CheckColisions(ModelType& model, CoordsXYZ pCoords)
{
	if (model->CheckHitbox(pCoords))
		return true;
	else
		return false;
}

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
	Terrain* terrain = new Terrain(hWnd, L"Imagenes//heigthmap.bmp", L"Imagenes//grassTexture.jpg", L"Imagenes//grassTexture.jpg", 530, 530);
	Water* lake = new Water(hWnd,L"Imagenes//heightmapLake.bmp",L"Imagenes//lake2.bmp",512,512);
	GLfloat AmbMat[4] = { 255, 255, 220, 1 };
	Fog* fog = new Fog();

	//OBJ ANIMADOS
	Player* Eddie;
	Bunny* Bunnies;
	Veggies* Carrot;
	Veggies* StinkyCarrot;
	Duck* Ducky;
	Items* Bottle;
	Items* Can;
	Items* Hammer;
	//OBJ ESTATICOS CON COLISION
	Barn* BarnHouse;
	ModelWColision* Bridge;
	ModelWColision* Boxes;
	ModelWColision* Bucket;
	Railing* Rail;
	VeggiesCamp* VeggiesCamps;
	ModelWColision* Sign;
	//OBJ ESTATICOS
	Model* Bed;
	Model* Chair;
	Model* Fridge;
	Model* Kitchen;
	Model* Table;
	Model* Toilet;
	Model* Tree;
	Model* TV;
	Model* Shower;
	Model* Sofa;

	Billboard* billBoard[BILLSIZE];

	struct PosCam {
		// TODO: Agregar campos
	};

	Scene(HWND hWnd)
	{
		this->hWnd = hWnd;
		skyIndex = lightIndex, skyRotation = 0;

		GLfloat AmbPos[] = { 0, 400, 400, 1 };

		// posiciones de la camara
		PosCam posCam1;

		glShadeModel(GL_SMOOTH);
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_LIGHTING);
		glMaterialfv(GL_FRONT, GL_AMBIENT, AmbMat);
		glEnable(GL_NORMALIZE);
		glEnable(GL_LIGHT0);
		glLightfv(GL_LIGHT0, GL_POSITION, AmbPos);


		//lago = Pista, busca en sus constructores para poder crear un lago.
		//NOTA: El estado de la colision se maneja en base al jugador, es decir, si choca con algo = true /*lake = new Water(hWnd, L"Imagenes//heigthmap.bmp", L"Imagenes//lake.bmp", 1000, 1250);*
		
		//A N I M A C I O N E S
		Eddie = new Player(-35.8, 37.6, -105.5, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 13, 20);
		Bunnies = new Bunny(-20.1 , 10 , -108.9 , 0, 0, 0, 14, 0, 25, 10, 45, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0);
		Carrot = new Veggies("Modelos//Carrots//Carrot.obj", "Modelos//Carrots//Carrot.bmp", 1, -20.1, 45, -108.9, 5, 3, 5, 0, 0, 45, 45, 50, 0, 1, 2.5, 1, 1, 0, 1, 0, 0, 0); //ARRAY -> INICIA EN TRUE
		StinkyCarrot = new Veggies("Modelos//Carrots//StinkyCarrot.obj", "Modelos//Carrots//StinkyCarrot.bmp", 1, -15.1, 45, -108.9, 3, 3, 3, 0, 0, 45, 45, 50, 0, 1, 2.5, 1, 1, 0, 1, 0, 0, 0);//ARRAY ->INICIA EN FALSE
		Ducky = new Duck("Modelos//Duck//Duck.obj", "Modelos//Duck//Duck.bmp", 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15 , 32.25 , 15); //cambiar de animacion
		Bottle = new Items("Modelos//Bottle//Bottle.obj", "Modelos//Bottle//Bottle.bmp", 1, -0.07,50,-164.95 , 6, 6, 6, 0, 0, 0, 0, 0, 0, 2, 2.5, 0.5, 0, 0, 0, 0, 0, 0, 0);
		Can = new Items("Modelos//Can//Can.obj", "Modelos//Can//Can.bmp", 1, -32.62, 46, -183, 6, 6, 6, 0, 0, 0, 0, 0, 0, 2, 2.5, 0.5, 0, 0, 0, 0, 0, 0, 0);
		Hammer = new Items("Modelos//Hammer//Hammer.obj", "Modelos//Hammer//Hammer.bmp", 1, 37.3, 46, -181.7, 6, 6, 6, 0, 0, 0, 0, 0, 0, 2, 2.5, 0.5, 0, 0, 0, 0, 0, 0, 0);
		
		//OBJ ESTATICOS CON COLISION
		BarnHouse = new Barn("Modelos//Barn//Barn.obj", "Modelos//Barn//Barn.bmp", 1, 0, 0, 0, 0, 0, 0, 0);
		Bridge = new ModelWColision("Modelos//Bridge//Bridge.obj", "Modelos//Bridge//Bridge.bmp", 1,-7.75,0,-34,11,0,54); //Colisiones con el piso del puente
		Bucket = new ModelWColision("Modelos//Bucket//Bucket.obj", "Modelos//Bucket//Bucket.bmp", 1, 0,0,0,0,0,0);
		Boxes = new ModelWColision("Modelos//Boxes//Boxes.obj", "Modelos//Boxes//Boxes.bmp", 1, 0,0,0,0,0,0);
		Rail = new Railing("Modelos//Camps//Railing.obj", "Modelos//Camps//Railing.bmp", 1,0,0,0,0,0,0,0);
		VeggiesCamps = new VeggiesCamp("Modelos//Camps//Veggies.obj", "Modelos//Camps//Veggies.bmp", 1);
		Sign = new ModelWColision("Modelos//Sign//Sign.obj", "Modelos//Sign//Sign.bmp", 1, -62.5,49,-125.7,10,10,10); //poner de acuerdo a la posicion del objeto

		////OBJ ESTATICOS 
		Bed = new Model("Modelos//Bed//Bed.obj", "Modelos//Bed//Bed.bmp", 1);
		Chair = new Model("Modelos//Chair//Chair.obj", "Modelos//Chair//Chair.bmp", 1);
		Fridge = new Model("Modelos//Fridge//Fridge.obj", "Modelos//Fridge//Fridge.bmp", 1);
		Kitchen = new Model("Modelos//Kitchen//Kitchen.obj", "Modelos//Kitchen//Kitchen.bmp", 1);
		Table = new Model("Modelos//Table//Table.obj", "Modelos//Table//Table.bmp", 1);
		Toilet = new Model("Modelos//Toilet//Toilet.obj", "Modelos//Toilet//Toilet.bmp", 1);
		Tree = new Model("Modelos//Tree//Trees.obj", "Modelos//Tree//Trees.bmp", 1);
		TV = new Model("Modelos//Tele//TV.obj", "Modelos//Tele//TV.bmp", 1);
		Shower = new Model("Modelos//Furniture//Furniture.obj", "Modelos//Furniture//Shower.bmp", 1);
		Sofa = new Model("Modelos//Sofa//sofa.obj", "Modelos//Sofa//Sofa.bmp", 1);

		Billboards(billBoard, hWnd);
		cameraInitialize(mGameStarted);
		//cameraInitialize(2, 23, -125, 0, 23, -25);
	}

	void Billboards(Billboard* bills[], HWND hWnd)
	{
		//Aqui puedes crear algo util con un FOR quiza.
	}

	void Render(HDC hDC)
	{
		if (!mGameStarted)
		{
			if (BarnHouse->CheckHitbox(mCoords) == true)
			{
				mCoords.x = mPastCoords.x;
				mCoords.z = mPastCoords.z;
			}

			if (Rail->CheckHitbox(mCoords) == true)
			{
				mCoords.x = mPastCoords.x;
				mCoords.z = mPastCoords.z;
			}

			if (VeggiesCamps->CheckHitbox(mCoords) == true)
			{
				mCoords.x = mPastCoords.x;
				mCoords.z = mPastCoords.z;
			}
		}

		glMaterialfv(GL_FRONT, GL_AMBIENT, AmbMat);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0, 0, 0, 0);
		glLoadIdentity();

		float AmbInt[] = { 0.1, 0.1, 0.1, 1 };
		glLightfv(GL_LIGHT0, GL_AMBIENT, AmbInt);

		if (!mGameStarted && !mGameInitialize)//si el juego aun no inicia, conservar estas coordenadas para la camara, si no, mandar estas al jugador
		{ mCoords.y = terrain->Superficie(mCoords.x, mCoords.z) * 4 + 12;
		}
		else
		{ 
			if (!mGameInitialize)
			{
				cameraInitialize(mGameStarted);
				cameraModeGame(Eddie->getPositions()); //reacomodar camara
				mGameInitialize = true;
				//playerCoords.y = terrain->Superficie(mPlayerCoords.x, mPlayerCoords.z) * 4 + 12;
			}
		}

		cameraUpdate(mGameStarted);

		skyDome->Move();

		//Terreno
		glPushMatrix();
		glScalef(1, 4, 1);
		terrain->Draw();
		glPopMatrix();
		//Lake

		//OBJETOS ESTATICOS CON COLISION
		RenderObjects<ModelWColision*>(Bridge, 0, 33.8, -92);
		RenderObjects<Barn*>(BarnHouse, 0, 38.6, -86);
		RenderObjects<ModelWColision*>(Bucket, 0, 38.6, -115.6);
		RenderObjects<ModelWColision*>(Boxes, 0, 38.6, -93.6);
		RenderObjects<Railing*>(Rail, 0.6, 38, -93.6);
		RenderObjects<VeggiesCamp*>(VeggiesCamps, 0.6, 37.6, -93.6);
		RenderObjects<ModelWColision*>(Sign, 0.6, 38.6, -93.6);

		//OBJETOS ESTATICOS SIN COLISION
		RenderObjects<Model*>(Bed, 0, 38.6, -86);
		RenderObjects<Model*>(Chair, 0, 38.6, -86);
		RenderObjects<Model*>(Fridge, 0, 38.6, -86);
		RenderObjects<Model*>(Kitchen, 0, 38.6, -86);
		RenderObjects<Model*>(Toilet, 0, 38.6, -86);
		RenderObjects<Model*>(Table, 0, 38.6, -86);
		RenderObjects<Model*>(Tree, 0, 38.6, -86);
		RenderObjects<Model*>(TV, 0, 38.6, -86);
		RenderObjects<Model*>(Sofa, 0, 38.6, -86);
		RenderObjects<Model*>(Shower, 0, 38.6, -86);
		
			//OBJETOS ANIMADOS
		//if (gameStarted)
		//{
		//	Eddie->setPositionX(positionX);
		//	Eddie->setPositionY(positionY);
		//	Eddie->setPositionZ(positionZ);
		//}
		if (mGameStarted && mGameInitialize)
		{ 
			MoveOnGame(Eddie->getPositions());

			if(!mKeyMovePressed)
			{ 
				Eddie->Idle();
			}
			else
			{
				Eddie->Run();
			}
		}
		Bunnies->Catch();
		Bottle->MoveObject(5, 360, 0.01);
		Can->MoveObject(4.5, 360, 0.10);
		Hammer->MoveObject(2, 360, 0.15);
		Carrot->Dance();
		StinkyCarrot->Dance();
		Ducky->Swim();

		if (mCoords.y < 34.5 && !mGameStarted)
		{ 
			fog->density = 0.025;
			fog->draw(); 
		}
		else
		{	fog->density = 0;
			fog->draw();
		}

		//Lago
		glPushMatrix();
		glScalef(1, 1, 1);
		lake->Draw();
		glPopMatrix();

		for (int i = 0; i < BILLSIZE; i++)
			//Aqui puede ir algo en especial, en tu carpeta de HEADER_FILES, el primer archivo es la respuesta.
			glPopMatrix();

		SwapBuffers(hDC);
	}

	//plantilla
	int ObjectsColisions()
	{
		if (CheckColisions<Items*>(Bottle, mCoords) == true)
			return 1;
		else
		{
			if (CheckColisions<Items*>(Can, mCoords) == true)
				return 2;
			else
			{
				if (CheckColisions<Items*>(Hammer, mCoords) == true)
					return 3;
				else
					if (CheckColisions<ModelWColision*>(Sign, mCoords) == true)
						return 4;
					else
						return 0;
			}
		}
	}

	void DoColision(short &option) //reiniciar valores cuando se acabe la partida
	{
		if (!Bottle->getTaken() && !Can->getTaken() && !Hammer->getTaken())
		{
			switch (option)
			{
			case 0:
				break;

			case 1:
				Bottle->setTaken(true);
				Can->setAble(false);
				Hammer->setAble(false);
				break;

			case 2:
				Can->setTaken(true);
				Bottle->setAble(false);
				Hammer->setAble(false);
				break;

			case 3:
				Hammer->setTaken(true);
				Bottle->setAble(false);
				Can->setAble(false);
				break;

			case 4:
				mGameStarted = true;
				//thirdPerson.cameraInitialize();
				//pantalla de carga
				//se aleja la camara 
				//se cargan modelos del jugador
				break;
			}

		}
	}


	void SaveCoords()
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
		delete Bottle;
		delete Can;
		delete Ducky;
		delete Carrot;
		delete StinkyCarrot;
		delete Bridge;
		delete Eddie;
		delete Bunnies;
		delete Tree;
		delete lake;
		delete BarnHouse;
		delete TV;
		delete Bed;
		delete Bucket;
		delete Chair;
		delete Fridge;
		delete Hammer;
		delete Kitchen;
		delete Table;
		delete Toilet;
		delete Boxes;
		delete Rail;
		delete VeggiesCamps;
		delete Sign;
		delete Sofa;
		delete Shower;
	}
};

//REFERENCIAS A MODELOS:
////This work is based on "Wooden rope bridge" (https://sketchfab.com/3d-models/wooden-rope-bridge-54773600fbdb48ef9853e553515f61ca) by DoniTodorov (https://sketchfab.com/DoniTodorov) licensed under CC-BY-4.0 (http://creativecommons.org/licenses/by/4.0/)
////This work is based on "Wooden Bucket (game ready asset)" (https://sketchfab.com/3d-models/wooden-bucket-game-ready-asset-9c9be436807f4267beaeb394f10ffa16) by Pixel Life (https://sketchfab.com/pixellife) licensed under CC-BY-4.0 (http://creativecommons.org/licenses/by/4.0/)
