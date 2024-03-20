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

#define BILLSIZE 50

//BIENVENIDO AL ARCHIVO MAS IMPORTANTE DE TU PROYECTO

class Scene : public Camera
{
public:

	HWND hWnd = 0;

	short int skyIndex, lightIndex;
	float skyRotation, bunnyRotation, bunnyPosition = 25;

	//float carrotPosition = 40, carrotRotation = 0;
	//float carrotSize = 2;

	//bool bunnyUp = false, bunnyDown = true, bunnyCatchStatus = false;
	//bool carrotUp = false, carrotDown = true, carrotSmall = true;

	//float duckPosition = -50, duckRotation = 0, swimRotation= 0, itemRotation = 0; //añadir las variables de swim en DUCK CLASS
	//float itemSize = 0;
	//bool duckFront = 1, duckBack = 0; //personalizarlo
	//bool itemSmall = 1;

	SkyDome* skyDome = new SkyDome(hWnd, 32, 32, 500, L"Imagenes//sky.png");
	Terrain* terrain = new Terrain(hWnd, L"Imagenes//heigthmap.bmp", L"Imagenes//grassTexture.jpg", L"Imagenes//grassTexture.jpg", 530, 530);
	//Water *lago; -> checar
	GLfloat AmbMat[4] = { 255, 255, 220, 1 };

	EDXFramework::Model* EddieRun[11];
	EDXFramework::Model* BunnyCatch[15];

	EDXFramework::Model* Carrot;
	EDXFramework::Model* Duck;
	Items* Bottle;
	Items* Can;

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

		//lago = Pista, busca en sus constructores para poder crear un lago.

		//NOTA: El estado de la colision se maneja en base al jugador, es decir, si choca con algo = true
		/*lake = new Water(hWnd, L"Imagenes//heigthmap.bmp", L"Imagenes//lake.bmp", 1000, 1250);*/

		//A N I M A C I O N E S
		/// - Caminar / Correr
		//EddieRun[0] = new EDXFramework::Model(11, 20, 0, 0, 0, 0, 0, 0 , 0, 0, 0, 0, 0, 0, false, 0, 0, 0, 0, 0, 0, "Modelos//Player//Run//R0.obj", "Modelos//Player//Player.bmp", 1);
		//EddieRun[1] = new EDXFramework::Model(11, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, false, 0, 0, 0, 0, 0, 0, "Modelos//Player//Run//R1.obj", "Modelos//Player//Player.bmp", 1);
		//EddieRun[2] = new EDXFramework::Model(11, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, false, 0, 0, 0, 0, 0, 0, "Modelos//Player//Run//R2.obj", "Modelos//Player//Player.bmp", 1);
		//EddieRun[3] = new EDXFramework::Model(11, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, false, 0, 0, 0, 0, 0, 0, "Modelos//Player//Run//R3.obj", "Modelos//Player//Player.bmp", 1);
		//EddieRun[4] = new EDXFramework::Model(11, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, false, 0, 0, 0, 0, 0, 0, "Modelos//Player//Run//R4.obj", "Modelos//Player//Player.bmp", 1);
		//EddieRun[5] = new EDXFramework::Model(11, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, false, 0, 0, 0, 0, 0, 0, "Modelos//Player//Run//R5.obj", "Modelos//Player//Player.bmp", 1);
		//EddieRun[6] = new EDXFramework::Model(11, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, false, 0, 0, 0, 0, 0, 0, "Modelos//Player//Run//R6.obj", "Modelos//Player//Player.bmp", 1);
		//EddieRun[7] = new EDXFramework::Model(11, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, false, 0, 0, 0, 0, 0, 0, "Modelos//Player//Run//R7.obj", "Modelos//Player//Player.bmp", 1);
		//EddieRun[8] = new EDXFramework::Model(11, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, false, 0, 0, 0, 0, 0, 0, "Modelos//Player//Run//R8.obj", "Modelos//Player//Player.bmp", 1);
		//EddieRun[9] = new EDXFramework::Model(11, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, false, 0, 0, 0, 0, 0, 0, "Modelos//Player//Run//R9.obj", "Modelos//Player//Player.bmp", 1);
		//EddieRun[10] = new EDXFramework::Model(11, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, false, 0, 0, 0, 0, 0, 0, "Modelos//Player//Run//R10.obj", "Modelos//Player//Player.bmp", 1);
		///// - Agarrar zanahoria
		////alternar textura sramp, enum -> hacer constructor para recibir enum
		//BunnyCatch[0] = new EDXFramework::Model(11, 20, 25, 0, 0, 25, 0, 0 , 0, 0, 0,1, 0, 0, false, 0, 0, 0, 0, 0, 0, "Modelos//Bunny//Catch//C0.obj", "Modelos//Bunny//Bunny.V.1.bmp", 1);
		//BunnyCatch[1] = new EDXFramework::Model(11, 20, 25, 0, 0, 25, 0, 0, 0, 0, 0, 1, 0, 0, false, 0, 0, 0, 0, 0, 0, "Modelos//Bunny//Catch//C1.obj", "Modelos//Bunny//Bunny.V.1.bmp", 1);
		//BunnyCatch[2] = new EDXFramework::Model(11, 20, 25, 0, 0, 25, 0, 0, 0, 0, 0, 1, 0, 0, false, 0, 0, 0, 0, 0, 0, "Modelos//Bunny//Catch//C2.obj", "Modelos//Bunny//Bunny.V.1.bmp", 1);
		//BunnyCatch[3] = new EDXFramework::Model(11, 20, 25, 0, 0, 25, 0, 0, 0, 0, 0, 1, 0, 0, false, 0, 0, 0, 0, 0, 0, "Modelos//Bunny//Catch//C3.obj", "Modelos//Bunny//Bunny.V.1.bmp", 1);
		//BunnyCatch[4] = new EDXFramework::Model(11, 20, 25, 0, 0, 25, 0, 0, 0, 0, 0, 1, 0, 0, false, 0, 0, 0, 0, 0, 0, "Modelos//Bunny//Catch//C4.obj", "Modelos//Bunny//Bunny.V.1.bmp", 1);
		//BunnyCatch[5] = new EDXFramework::Model(11, 20, 25, 0, 0, 25, 0, 0, 0, 0, 0, 1, 0, 0, false, 0, 0, 0, 0, 0, 0, "Modelos//Bunny//Catch//C5.obj", "Modelos//Bunny//Bunny.V.1.bmp", 1);
		//BunnyCatch[6] = new EDXFramework::Model(11, 20, 25, 0, 0, 25, 0, 0, 0, 0, 0, 1, 0, 0, false, 0, 0, 0, 0, 0, 0, "Modelos//Bunny//Catch//C6.obj", "Modelos//Bunny//Bunny.V.1.bmp", 1);
		//BunnyCatch[7] = new EDXFramework::Model(11, 20, 25, 0, 0, 25, 0, 0, 0, 0, 0, 1, 0, 0, false, 0, 0, 0, 0, 0, 0, "Modelos//Bunny//Catch//C7.obj", "Modelos//Bunny//Bunny.V.1.bmp", 1);
		//BunnyCatch[8] = new EDXFramework::Model(11, 20, 25, 0, 0, 25, 0, 0, 0, 0, 0, 1, 0, 0, false, 0, 0, 0, 0, 0, 0, "Modelos//Bunny//Catch//C8.obj", "Modelos//Bunny//Bunny.V.1.bmp", 1);
		//BunnyCatch[9] = new EDXFramework::Model(11, 20, 25, 0, 0, 25, 0, 0, 0, 0, 0, 1, 0, 0, false, 0, 0, 0, 0, 0, 0, "Modelos//Bunny//Catch//C9.obj", "Modelos//Bunny//Bunny.V.1.bmp", 1);
		//BunnyCatch[10] = new EDXFramework::Model(11, 20, 25, 0, 0, 25, 0, 0, 0, 0, 0, 1, 0, 0, false, 0, 0, 0, 0, 0, 0, "Modelos//Bunny//Catch//C10.obj", "Modelos//Bunny//Bunny.V.1.bmp", 1);
		//BunnyCatch[11] = new EDXFramework::Model(11, 20, 25, 0, 0, 25, 0, 0, 0, 0, 0, 1, 0, 0, false, 0, 0, 0, 0, 0, 0, "Modelos//Bunny//Catch//C11.obj", "Modelos//Bunny//Bunny.V.1.bmp", 1);
		//BunnyCatch[12] = new EDXFramework::Model(11, 20, 25, 0, 0, 25, 0, 0, 0, 0, 0, 1, 0, 0, false, 0, 0, 0, 0, 0, 0, "Modelos//Bunny//Catch//C12.obj", "Modelos//Bunny//Bunny.V.1.bmp", 1);
		//BunnyCatch[13] = new EDXFramework::Model(11, 20, 25, 0, 0, 25, 0, 0, 0, 0, 0, 1, 0, 0, false, 0, 0, 0, 0, 0, 0, "Modelos//Bunny//Catch//C13.obj", "Modelos//Bunny//Bunny.V.1.bmp", 1);
		//BunnyCatch[14] = new EDXFramework::Model(11, 20, 25, 0, 0, 25, 0, 0, 0, 0, 0, 1, 0, 0, false, 0, 0, 0, 0, 0, 0, "Modelos//Bunny//Catch//C14.obj", "Modelos//Bunny//Bunny.V.1.bmp", 1);//si no es obj el proyecto se cerrará automaticamente

		//Carrot = new EDXFramework::Model("Modelos//Carrots//Carrot.obj", "Modelos//Carrots//Carrot.bmp", 1);

		//StinkyCarrot = new EDXFramework::Model(false, 0, 0, 0, 0, 0, 0, "Modelos//Carrots//StinkyCarrot.obj", "Modelos//Carrots//StinkyCarrot.bmp", 1);
		
		//Duck = new EDXFramework::Model(0, 0, -50, 0, 0, 360, 0, 0, 0, 0, 0, 0, 0, 1, false, 0, 0, 0, 0, 0, 0, "Modelos//Duck//Duck.obj", "Modelos//Duck//Duck.bmp", 1);
		
		////This work is based on "Wooden rope bridge" (https://sketchfab.com/3d-models/wooden-rope-bridge-54773600fbdb48ef9853e553515f61ca) by DoniTodorov (https://sketchfab.com/DoniTodorov) licensed under CC-BY-4.0 (http://creativecommons.org/licenses/by/4.0/)
		////This work is based on "Wooden Bucket (game ready asset)" (https://sketchfab.com/3d-models/wooden-bucket-game-ready-asset-9c9be436807f4267beaeb394f10ffa16) by Pixel Life (https://sketchfab.com/pixellife) licensed under CC-BY-4.0 (http://creativecommons.org/licenses/by/4.0/)
		//Bridge = new EDXFramework::Model(false, 0, 0, 0, 0, 0, 0, "Modelos//Bridge//Bridge.obj", "Modelos//Bridge//Bridge.bmp", 1);
		//Barn = new EDXFramework::Model(false, 0, 0, 0, 0, 0, 0, "Modelos//Barn//Barn.obj", "Modelos//Barn//Barn.bmp", 1);

		//Bed = new EDXFramework::Model("Modelos//Bed//Bed.obj", "Modelos//Bed//Bed.bmp", 1);
		
		Bottle = new Items("Modelos//Bottle//Bottle.mtl.obj", "Modelos//Bottle//Bottle.bmp",1, 0,0,0,0,0,0,0,0,0,0,0,0,0,2,2.5,0.5,0,0,0,0,0,0);
		Can = new Items("Modelos//Can//Can.obj", "Modelos//Can//Can.bmp", 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2.5, 0.5, 0, 0, 0, 0, 0, 0);
		
		//Bucket = new EDXFramework::Model("Modelos//Bucket//Bucket.obj", "Modelos//Bucket//Bucket.bmp", 1);
		//Camp = new EDXFramework::Model("Modelos//Camp//Camp.obj", "Modelos//Camp//Camp.bmp", 1);
		//Chair = new EDXFramework::Model("Modelos//Chair//Chair.obj", "Modelos//Chair//Chair.bmp", 1);
		//Fridge = new EDXFramework::Model("Modelos//Fridge//Fridge.obj", "Modelos//Fridge//Fridge.bmp", 1);
		//Hammer = new EDXFramework::Model("Modelos//Hammer//Hammer.obj", "Modelos//Hammer//Hammer.bmp", 1);
		//Kitchen = new EDXFramework::Model("Modelos//Kitchen//Kitchen.obj", "Modelos//Kitchen//Kitchen.bmp", 1);
		//Table = new EDXFramework::Model("Modelos//Table//Table.obj", "Modelos//Table//Table.bmp", 1);
		//Toilet = new EDXFramework::Model("Modelos//Toilet//Toilet.obj", "Modelos//Toilet//Toilet.bmp", 1);

		/*Boxes = new EDXFramework::Model(false, 0, 0, 0, 0, 0, 0, "Modelos//Boxes//Boxes.obj", "Modelos//Boxes//Boxes.bmp", 1);
		Railing = new EDXFramework::Model(false, 0, 0, 0, 0, 0, 0, "Modelos//Camps//Railing.obj", "Modelos//Camps//Railing.bmp", 1);
		Veggies = new EDXFramework::Model(false, 0, 0, 0, 0, 0, 0, "Modelos//Camps//Veggies.obj", "Modelos//Camps//Veggies.bmp", 1);
		Sign = new EDXFramework::Model(false, 0, 0, 0, 0, 0, 0, "Modelos//Sign//Sign.obj", "Modelos//Sign//Sign.bmp", 1);*/

		Billboards(billBoard, hWnd);

		cameraInitialize();
	}

	void Billboards(Billboard* bills[], HWND hWnd)
	{
		//Aqui puedes crear algo util con un FOR quiza.
	}

	void Render(HDC hDC)
	{
	/*	static short iEddieRun = 0;
		static short iBunnyCatch = 0;*/

		/*if (skyRotation < 360)
		{
			skyRotation += 0.1f;
		}
		else
		{
			skyRotation = 0;
		}*/

		//hacer status para que se ejecute mientras no este con la animación

		//verificar el bunnyCatchStatus  y luego ejecutar rotacion
		//if (bunnyCatchStatus == false)
		//{
		//	rotacion
		//}
		////if (bunnyRotation < 360 && bunnyCatchStatus == false)
		////{
		////	bunnyRotation += 100;
		////}
		////else
		////{
		////	bunnyRotation = 0;
		////}

		//if (carrotRotation < 360)
		//{
		//	carrotRotation += 10;
		//}
		//else
		//{
		//	carrotRotation = 0;
		//}

		//Carrot->Spin(10, 360);

		//Para hacer que el conejo suba y baje
		//if (bunnyPosition < 50 && bunnyPosition >= 10 && bunnyUp == false)
		//{
		//	bunnyPosition += 0.250;
		//	if (bunnyPosition >= 50)
		//	{
		//		// si devuelve true, asignar estos valores
		//		bunnyUp = true;
		//		bunnyDown = false;
		//		bunnyCatchStatus = true;
		//	}
		//}
		//else
		//{
		//	if (bunnyPosition <= 25)
		//	{
		//		//si devuelve false, asignar estos valores
		//		bunnyUp = false;
		//		bunnyDown = true;
		//	}
		//	if (bunnyCatchStatus == false && bunnyDown == false)
		//	{
		//		bunnyPosition -= 0.250;
		//	}
		//}

		//Carrot->MoveUpNDown(0.25);

		////Para hacer que el conejo suba y baje
		//if (carrotPosition < 43 && carrotPosition >= 39 && carrotUp == false)
		//{
		//	carrotPosition += 0.25;
		//	if (carrotPosition >= 43)
		//	{
		//		// si devuelve true, asignar estos valores
		//		carrotUp = true;
		//		carrotDown = false;
		//	}
		//}
		//else
		//{
		//	if (carrotPosition <= 40)
		//	{
		//		//si devuelve false, asignar estos valores
		//		carrotUp = false;
		//		carrotDown = true;
		//	}
		//	if (carrotDown == false)
		//	{
		//		carrotPosition -= 0.025;
		//	}
		//}

		//Carrot->Resizing(0.05);

		//if (carrotSize < 2.5 && carrotSmall == true)
		//{
		//	carrotSize += 0.05;
		//	if (carrotSize >= 2.5)
		//	{
		//		carrotSmall = false;
		//	}
		//}
		//else
		//{
		//	carrotSize -= 0.05;
		//	if (carrotSize <= 2)
		//	{
		//		carrotSmall = true;
		//	}
		//}

		//Duck->RotateFrontTBack(5, 45);

		//if (duckFront == false)
		//{
		//	duckRotation += 5;
		//	if (duckRotation >= 45)
		//	{
		//		duckBack = false;
		//		duckFront = true;
		//	}
		//}
		//else
		//{
		//	duckRotation -= 5;
		//	if (duckRotation <= -45)
		//	{
		//		duckFront = false;
		//		duckBack = true;
		//	}
		//}

		//PONER EN SU DERIVADA

		//if (swimRotation < 360)
		//{
		//	swimRotation += 1;
		//}
		//else
		//{
		//	swimRotation = 0;
		//}
		//if (itemRotation < 360)
		//{
		//	itemRotation += 5;
		//}
		//else
		//{
		//	itemRotation = 0;
		//}

		//if (itemSize < 2.5 && itemSmall == true)
		//{
		//	itemSize += 0.01;
		//	if (itemSize >= 2.5)
		//	{
		//		itemSmall = false;
		//	}
		//}
		//else
		//{
		//	itemSize -= 0.01;
		//	if (itemSize <= 0.5)
		//	{
		//		itemSmall = true;
		//	}
		//}


		glMaterialfv(GL_FRONT, GL_AMBIENT, AmbMat);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0, 0, 0, 0);
		glLoadIdentity();

		float AmbInt[] = { 0.1, 0.1, 0.1, 1 };
		glLightfv(GL_LIGHT0, GL_AMBIENT, AmbInt);
		positionY = terrain->Superficie(positionX, positionZ) * 4 + 8;

		cameraUpdate();

		//Skydome
		glPushMatrix();
		glTranslatef(0, 8, 0);
		glRotatef(skyRotation, 0, 1, 0);
		skyDome->Draw();
		glPopMatrix();

		//Terreno
		glPushMatrix();
		glScalef(1, 4, 1);
		terrain->Draw();
		glPopMatrix();

		////Player
		glPushMatrix();
		glTranslatef(3.6, 37.6, -115.6);

		//Reducir velocidad de las animaciones
	   // Para que Eddie corra
		//if (iEddieRun <= 10)
		//{
		//	EddieRun[iEddieRun]->Draw();
		//	iEddieRun += 1;
		//	glPopMatrix();
		//}
		//else
		//{
		//	iEddieRun = 0;
		//	EddieRun[iEddieRun]->Draw();
		//	glPopMatrix();
		//}


		//Enemy
		//glPushMatrix();
		//glTranslatef(8.6, bunnyPosition, -98.6);
		//glRotatef(bunnyRotation, 0, 1, 0);

		// Para que los conejos agarren cosas -> poner en la clase conejos
		//if (bunnyUp == true)
		//{
		//	if (iBunnyCatch <= 14 && bunnyCatchStatus == true)
		//	{
		//		BunnyCatch[iBunnyCatch]->Draw();
		//		iBunnyCatch += 1;
		//	}
		//	else
		//	{
		//		iBunnyCatch = 0;
		//		BunnyCatch[iBunnyCatch]->Draw();
		//		bunnyCatchStatus = false;
		//	}
		//}
		//else
		//{
		//	if (bunnyCatchStatus == true)
		//	{
		//		BunnyCatch[14]->Draw();
		//	}
		//	else
		//	{
		//		BunnyCatch[0]->Draw();
		//	}
		//}
		glPopMatrix();

		////Carrot
		//glPushMatrix();
		//glTranslatef(8.6, 45, - 113.6);
		//glRotatef(45, 0, 1, 0);
		//glScalef(Carrot->getSize(),Carrot->getSize(), Carrot->getSize());
		//Carrot->Draw();
		//glPopMatrix();

		////StinkyCarrot
		//glPushMatrix();
		//glTranslatef(10.6, 40, -113.6);
		//StinkyCarrot->Draw();
		//glPopMatrix();

		////Duck
		//glPushMatrix();
		//glRotatef(swimRotation, 0, 1, 0);
		//glTranslatef(0, 45, 10);
		//glRotatef(duckRotation, 1, 0, 1);
		//Duck->Draw();
		//glPopMatrix();

		//////Bridge
		////glPushMatrix();
		////glTranslatef(0, 34, -92);
		////Bridge->Draw();
		////glPopMatrix();
		//
		//////Barn
		////glPushMatrix();
		////glTranslatef(0, 38, -86);
		////Barn->Draw();
		////glPopMatrix();
		//
		//////Lake
		////glPushMatrix();
		////glScalef(1, 15, 1);
		////lake->Draw();
		////glPopMatrix();
		//
		//////Bed
		////glPushMatrix();
		////glTranslatef(0.6, 38.6, -115.6);
		////Bed->Draw();
		////glPopMatrix();
		
		//Bottle
		//Bottle->Spin(5, 360);
		//Bottle->Resizing(0.01);
		//glPushMatrix();
		//glTranslatef(-1, 50, -115.6);
		//glRotatef(Bottle->getRotation(), 1, 1, 1);
		//glScalef(Bottle->getSize(), Bottle->getSize(), Bottle->getSize());
		//Bottle->Draw();
		//glPopMatrix();


		Bottle->MoveObject(5, 360, 0.01, -1, 50, -115.6);
		Can->MoveObject(4.5, 360, 0.10, -2, 45, -110.6);

		//////Bucket
		////glPushMatrix();
		////glTranslatef(0.6, 38.6, -115.6);
		////Bucket->Draw();
		////glPopMatrix();
		//////Camp
		////glPushMatrix();
		////glTranslatef(0.6, 38.6, -115.6);
		////Camp->Draw();
		////glPopMatrix();
		//////Can
		////glPushMatrix();
		////glTranslatef(0.6, 38.6, -115.6);
		////Can->Draw();
		////glPopMatrix();
		//////Chair
		////glPushMatrix();
		////glTranslatef(0.6, 38.6, -115.6);
		////Chair->Draw();
		////glPopMatrix();
		//////Fridge
		////glPushMatrix();
		////glTranslatef(0.6, 38.6, -115.6);
		////Fridge->Draw();
		////glPopMatrix();
		//////Hammer
		////glPushMatrix();
		////glTranslatef(0.6, 38.6, -115.6);
		////Hammer->Draw();
		////glPopMatrix();
		//////Kitchen
		////glPushMatrix();
		////glTranslatef(0.6, 38.6, -115.6);
		////Kitchen->Draw();
		////glPopMatrix();
		//////Table
		////glPushMatrix();
		////glTranslatef(0.6, 38.6, -115.6);
		////Table->Draw();
		////glPopMatrix();
		//////Toilet
		////glPushMatrix();
		////glTranslatef(0.6, 38.6, -115.6);
		////Toilet->Draw();
		////glPopMatrix();
		//////Boxes
		////glPushMatrix();
		////glTranslatef(0, 38, -93);
		////Boxes->Draw();
		////glPopMatrix();
		//////Railing
		////glPushMatrix();
		////glTranslatef(0, 38, -93);
		////Railing->Draw();
		////glPopMatrix();
		//////Veggies
		////glPushMatrix();
		////glTranslatef(0, 38, -93);
		////Veggies->Draw();
		////glPopM
		//////Sign
		////glPushMatrix();
		////glTranslatef(0, 38, -93);
		////Sign->Draw();
		////glPopMatrix();

		for (int i = 0; i < BILLSIZE; i++)
			//Aqui puede ir algo en especial, en tu carpeta de HEADER_FILES, el primer archivo es la respuesta.
			glPopMatrix();

		SwapBuffers(hDC);
	}

	~Scene()
	{
		//M O D E L O S
		delete skyDome;
		delete terrain;
		//delete Carrot;
		//delete Duck;
		delete Bottle;
		delete Can;
		//A N I M A C I O N E S
		for (int i = 0; i < 11; i++)
		{
			delete EddieRun[i];
		}
		for (int i = 0; i < 15; i++)
		{
			delete BunnyCatch[i];
		}
		////delete lake;
		//delete Carrot;
		//delete StinkyCarrot;
		//delete Bridge;
		//delete Barn;
		////delete Bed;
		////delete Bottle;
		////delete Bucket;
		////delete Camp;
		////delete Can;
		////delete Chair;
		////delete Fridge;
		////delete Hammer;
		////delete Kitchen;
		////delete Table;
		////delete Toilet;
		//delete Boxes;
		//delete Railing;
		//delete Veggies;
		//delete Sign;
	}
};