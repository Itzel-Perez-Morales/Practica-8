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

class Scene : public Camera
{
public:

	HWND hWnd = 0;

	short int skyIndex, lightIndex;
	float skyRotation, bunnyRotation, bunnyPosition = 40;
	bool bunnyUp = false, bunnyEnd = false;

	SkyDome *skyDome = new SkyDome(hWnd, 32, 32, 500, L"Imagenes//sky.png");
	Terrain *terrain;
	//Water *lago; -> checar
	GLfloat AmbMat[4] = { 255, 255, 220, 1 };

	EDXFramework::Model* EddieRun[11];

	EDXFramework::Model* BunnyCatch[15];


	Billboard *billBoard[BILLSIZE];
	
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
		terrain = new Terrain(hWnd, L"Imagenes//heigthmap.bmp", L"Imagenes//grassTexture.jpg", L"Imagenes//grassTexture.jpg", 530, 530);
		/*lake = new Water(hWnd, L"Imagenes//heigthmap.bmp", L"Imagenes//lake.bmp", 1000, 1250);*/
		
		//A N I M A C I O N E S
		/// - Caminar / Correr
		EddieRun[0] = new EDXFramework::Model(false, 0, 0, 0, 0, 0, 0, "Modelos//Player//Run//R0.obj", "Modelos//Player//Player.bmp", 1);
		EddieRun[1] = new EDXFramework::Model(false, 0, 0, 0, 0, 0, 0, "Modelos//Player//Run//R1.obj", "Modelos//Player//Player.bmp", 1);
		EddieRun[2] = new EDXFramework::Model(false, 0, 0, 0, 0, 0, 0, "Modelos//Player//Run//R2.obj", "Modelos//Player//Player.bmp", 1);
		EddieRun[3] = new EDXFramework::Model(false, 0, 0, 0, 0, 0, 0, "Modelos//Player//Run//R3.obj", "Modelos//Player//Player.bmp", 1);
		EddieRun[4] = new EDXFramework::Model(false, 0, 0, 0, 0, 0, 0, "Modelos//Player//Run//R4.obj", "Modelos//Player//Player.bmp", 1);
		EddieRun[5] = new EDXFramework::Model(false, 0, 0, 0, 0, 0, 0, "Modelos//Player//Run//R5.obj", "Modelos//Player//Player.bmp", 1);
		EddieRun[6] = new EDXFramework::Model(false, 0, 0, 0, 0, 0, 0, "Modelos//Player//Run//R6.obj", "Modelos//Player//Player.bmp", 1);
		EddieRun[7] = new EDXFramework::Model(false, 0, 0, 0, 0, 0, 0, "Modelos//Player//Run//R7.obj", "Modelos//Player//Player.bmp", 1);
		EddieRun[8] = new EDXFramework::Model(false, 0, 0, 0, 0, 0, 0, "Modelos//Player//Run//R8.obj", "Modelos//Player//Player.bmp", 1);
		EddieRun[9] = new EDXFramework::Model(false, 0, 0, 0, 0, 0, 0, "Modelos//Player//Run//R9.obj", "Modelos//Player//Player.bmp", 1);
		EddieRun[10] = new EDXFramework::Model(false, 0, 0, 0, 0, 0, 0, "Modelos//Player//Run//R10.obj", "Modelos//Player//Player.bmp", 1);
		/// - Agarrar zanahoria
		//alternar textura sramp, enum -> hacer constructor para recibir enum
		BunnyCatch[0] = new EDXFramework::Model(false, 0, 0, 0, 0, 0, 0, "Modelos//Bunny//Catch//C0.obj", "Modelos//Bunny//Bunny.V.1.bmp", 1);
		BunnyCatch[1] = new EDXFramework::Model(false, 0, 0, 0, 0, 0, 0, "Modelos//Bunny//Catch//C1.obj", "Modelos//Bunny//Bunny.V.1.bmp", 1);
		BunnyCatch[2] = new EDXFramework::Model(false, 0, 0, 0, 0, 0, 0, "Modelos//Bunny//Catch//C2.obj", "Modelos//Bunny//Bunny.V.1.bmp", 1);
		BunnyCatch[3] = new EDXFramework::Model(false, 0, 0, 0, 0, 0, 0, "Modelos//Bunny//Catch//C3.obj", "Modelos//Bunny//Bunny.V.1.bmp", 1);
		BunnyCatch[4] = new EDXFramework::Model(false, 0, 0, 0, 0, 0, 0, "Modelos//Bunny//Catch//C4.obj", "Modelos//Bunny//Bunny.V.1.bmp", 1);
		BunnyCatch[5] = new EDXFramework::Model(false, 0, 0, 0, 0, 0, 0, "Modelos//Bunny//Catch//C5.obj", "Modelos//Bunny//Bunny.V.1.bmp", 1);
		BunnyCatch[6] = new EDXFramework::Model(false, 0, 0, 0, 0, 0, 0, "Modelos//Bunny//Catch//C6.obj", "Modelos//Bunny//Bunny.V.1.bmp", 1);
		BunnyCatch[7] = new EDXFramework::Model(false, 0, 0, 0, 0, 0, 0, "Modelos//Bunny//Catch//C7.obj", "Modelos//Bunny//Bunny.V.1.bmp", 1);
		BunnyCatch[8] = new EDXFramework::Model(false, 0, 0, 0, 0, 0, 0, "Modelos//Bunny//Catch//C8.obj", "Modelos//Bunny//Bunny.V.1.bmp", 1);
		BunnyCatch[9] = new EDXFramework::Model(false, 0, 0, 0, 0, 0, 0, "Modelos//Bunny//Catch//C9.obj", "Modelos//Bunny//Bunny.V.1.bmp", 1);
		BunnyCatch[10] = new EDXFramework::Model(false, 0, 0, 0, 0, 0, 0, "Modelos//Bunny//Catch//C10.obj", "Modelos//Bunny//Bunny.V.1.bmp", 1);
		BunnyCatch[11] = new EDXFramework::Model(false, 0, 0, 0, 0, 0, 0, "Modelos//Bunny//Catch//C11.obj", "Modelos//Bunny//Bunny.V.1.bmp", 1);
		BunnyCatch[12] = new EDXFramework::Model(false, 0, 0, 0, 0, 0, 0, "Modelos//Bunny//Catch//C12.obj", "Modelos//Bunny//Bunny.V.1.bmp", 1);
		BunnyCatch[13] = new EDXFramework::Model(false, 0, 0, 0, 0, 0, 0, "Modelos//Bunny//Catch//C13.obj", "Modelos//Bunny//Bunny.V.1.bmp", 1);
		BunnyCatch[14] = new EDXFramework::Model(false, 0, 0, 0, 0, 0, 0, "Modelos//Bunny//Catch//C14.obj", "Modelos//Bunny//Bunny.V.1.bmp", 1);//si no es obj el proyecto se cerrará automaticamente
		
		//Carrot = new EDXFramework::Model(false, 0, 0, 0, 0, 0, 0, "Modelos//Carrots//Carrot.obj", "Modelos//Carrots//Carrot.bmp", 1);
		//StinkyCarrot = new EDXFramework::Model(false, 0, 0, 0, 0, 0, 0, "Modelos//Carrots//StinkyCarrot.obj", "Modelos//Carrots//StinkyCarrot.bmp", 1);
		//Duck = new EDXFramework::Model(false, 0, 0, 0, 0, 0, 0, "Modelos//Duck//Duck.obj", "Modelos//Duck//Duck.bmp", 1);
		////This work is based on "Wooden rope bridge" (https://sketchfab.com/3d-models/wooden-rope-bridge-54773600fbdb48ef9853e553515f61ca) by DoniTodorov (https://sketchfab.com/DoniTodorov) licensed under CC-BY-4.0 (http://creativecommons.org/licenses/by/4.0/)
		////This work is based on "Wooden Bucket (game ready asset)" (https://sketchfab.com/3d-models/wooden-bucket-game-ready-asset-9c9be436807f4267beaeb394f10ffa16) by Pixel Life (https://sketchfab.com/pixellife) licensed under CC-BY-4.0 (http://creativecommons.org/licenses/by/4.0/)
		//Bridge = new EDXFramework::Model(false, 0, 0, 0, 0, 0, 0, "Modelos//Bridge//Bridge.obj", "Modelos//Bridge//Bridge.bmp", 1);
		//Barn = new EDXFramework::Model(false, 0, 0, 0, 0, 0, 0, "Modelos//Barn//Barn.obj", "Modelos//Barn//Barn.bmp", 1);

		//Bed = new EDXFramework::Model("Modelos//Bed//Bed.obj", "Modelos//Bed//Bed.bmp", 1);
		//Bottle = new EDXFramework::Model("Modelos//Bottle//Bottle.obj", "Modelos//Bottle//Bottle.bmp", 1);
		//Bucket = new EDXFramework::Model("Modelos//Bucket//Bucket.obj", "Modelos//Bucket//Bucket.bmp", 1);
		//Camp = new EDXFramework::Model("Modelos//Camp//Camp.obj", "Modelos//Camp//Camp.bmp", 1);
		//Can = new EDXFramework::Model("Modelos//Can//Can.obj", "Modelos//Can//Can.bmp", 1);
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
		static short iEddieRun = 0;
		static short iBunnyCatch = 0;

		if (skyRotation < 360)
		{
			skyRotation += 0.1f;
		}
		else
		{
			skyRotation = 0;
		}
		//hacer status para que se ejecute mientras no este con la animación
		if (bunnyRotation < 360 && bunnyUp == false)
		{
			bunnyRotation += 50;
		}
		else
		{
			bunnyRotation = 0;
		}

		if (bunnyPosition < 50 && bunnyPosition >= 40 && bunnyUp == false)
		{
			bunnyPosition += 1;
			bunnyUp = false;
		}
		else
		{
			if (bunnyEnd == true)
			{
				bunnyPosition -= 1;
			}
			bunnyUp = false;
		}


		glMaterialfv(GL_FRONT, GL_AMBIENT, AmbMat);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0, 0, 0, 0);
		glLoadIdentity();

		float AmbInt[] = { 0.1, 0.1, 0.1, 1 };
		glLightfv(GL_LIGHT0, GL_AMBIENT, AmbInt);
		//positionY = terrain->Superficie(positionX, positionZ) * 4 + 6;
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
		// Para que Eddie corra
		if (iEddieRun <= 10)
		{
			EddieRun[iEddieRun]->Draw();
			iEddieRun += 1;
			glPopMatrix();
		}
		else
		{
			iEddieRun = 0;
			EddieRun[iEddieRun]->Draw();
			glPopMatrix();
		}


		//Enemy
		glPushMatrix();
		glTranslatef(8.6, bunnyPosition, -98.6);
		glRotatef(bunnyRotation, 0, 1, 0);

		// Para que los conejos agarren cosas
		if (bunnyUp == true && bunnyEnd == false)
		{
			if (iBunnyCatch <= 14)
			{
				BunnyCatch[iBunnyCatch]->Draw();
				iBunnyCatch += 1;
				glPopMatrix();
			}
			else
			{
				iBunnyCatch = 0;
				BunnyCatch[iBunnyCatch]->Draw();
				glPopMatrix();
				bunnyEnd = true;
			}
		}
		glPopMatrix();

		////Carrot
		//glPushMatrix();
		//glTranslatef(8.6, 40, -113.6);
		//Carrot->Draw();
		//glPopMatrix();

		////StinkyCarrot
		//glPushMatrix();
		//glTranslatef(10.6, 40, -113.6);
		//StinkyCarrot->Draw();
		//glPopMatrix();

		////Duck
		//glPushMatrix();
		//glTranslatef(0, 35, 10);
		//Duck->Draw();
		//glPopMatrix();

		////Bridge
		//glPushMatrix();
		//glTranslatef(0, 34, -92);
		//Bridge->Draw();
		//glPopMatrix();

		////Barn
		//glPushMatrix();
		//glTranslatef(0, 38, -86);
		//Barn->Draw();
		//glPopMatrix();

		////Lake
		//glPushMatrix();
		//glScalef(1, 15, 1);
		//lake->Draw();
		//glPopMatrix();

		////Bed
		//glPushMatrix();
		//glTranslatef(0.6, 38.6, -115.6);
		//Bed->Draw();
		//glPopMatrix();

		////Bottle
		//glPushMatrix();
		//glTranslatef(0.6, 38.6, -115.6);
		//Bottle->Draw();
		//glPopMatrix();

		////Bucket
		//glPushMatrix();
		//glTranslatef(0.6, 38.6, -115.6);
		//Bucket->Draw();
		//glPopMatrix();

		////Camp
		//glPushMatrix();
		//glTranslatef(0.6, 38.6, -115.6);
		//Camp->Draw();
		//glPopMatrix();

		////Can
		//glPushMatrix();
		//glTranslatef(0.6, 38.6, -115.6);
		//Can->Draw();
		//glPopMatrix();

		////Chair
		//glPushMatrix();
		//glTranslatef(0.6, 38.6, -115.6);
		//Chair->Draw();
		//glPopMatrix();

		////Fridge
		//glPushMatrix();
		//glTranslatef(0.6, 38.6, -115.6);
		//Fridge->Draw();
		//glPopMatrix();

		////Hammer
		//glPushMatrix();
		//glTranslatef(0.6, 38.6, -115.6);
		//Hammer->Draw();
		//glPopMatrix();

		////Kitchen
		//glPushMatrix();
		//glTranslatef(0.6, 38.6, -115.6);
		//Kitchen->Draw();
		//glPopMatrix();

		////Table
		//glPushMatrix();
		//glTranslatef(0.6, 38.6, -115.6);
		//Table->Draw();
		//glPopMatrix();

		////Toilet
		//glPushMatrix();
		//glTranslatef(0.6, 38.6, -115.6);
		//Toilet->Draw();
		//glPopMatrix();

		////Boxes
		//glPushMatrix();
		//glTranslatef(0, 38, -93);
		//Boxes->Draw();
		//glPopMatrix();

		////Railing
		//glPushMatrix();
		//glTranslatef(0, 38, -93);
		//Railing->Draw();
		//glPopMatrix();

		////Veggies
		//glPushMatrix();
		//glTranslatef(0, 38, -93);
		//Veggies->Draw();
		//glPopMatrix();

		////Sign
		//glPushMatrix();
		//glTranslatef(0, 38, -93);
		//Sign->Draw();
		//glPopMatrix();

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
		//delete Duck;
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