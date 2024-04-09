#include <Windows.h>
#include "glew.h"
#include <gl\GLU.h>
#include <gl\GL.h>
#include "Scene.h"
#include <time.h>
#include "GamePadRR.h"
#include "resource.h"
#pragma comment (lib, "glew32.lib") 
#pragma comment(lib,"opengl32.lib")
#pragma comment(lib,"glu32.lib") 

#define Timer1 100

LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
void DefPixelFormat(HDC hDC);
void AuxCoords(Scene* scene);

HWND hInfo = 0;
HWND hText = 0;
bool ableToCheck = false;
HDC hContextoVentana;
Scene* scene;
GamePadRR* gamPad;
bool renderiza = false;
bool keys[9] = { 0,0,0,0,0,0,0,0,0 };
unsigned int dayTimer = 0;

// TODO: Agregar arreglo de bools para guardar estado de los inputs
//		Si los movimientos se ven muy rapidos/fluidos: Ajustar velocidades / FPS

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	HWND hwndVentana;
	WNDCLASSEX wc;

	ZeroMemory(&wc, sizeof(WNDCLASSEX));
	wc.cbSize = sizeof(WNDCLASSEX); //Tamaño en bytes de la estructura.
	wc.style = CS_HREDRAW | CS_VREDRAW; //Entero de 16 bits que codifica el estilo de la clase de ventana.
	wc.lpfnWndProc = WindowProc;//Apunta al procedimiento de ventana.
	wc.hInstance = hInstance;//Identifica la instancia de la ventana a la que esta clase pertenece.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);//Identificador del curso de la clase. Debe ser un manipulador de un recurso de tipo icono. Si es Null, la aplicación mostrará un icono cuando el usuario minice la ventana de la aplicación.
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW; //Identificador del pincel para la clase.
	wc.lpszClassName = "Game"; //Especifica el nombre de la clase ventana.
	RegisterClassEx(&wc);//Registra una clase de ventana para su uso subsecuente en llamadas a las funciones CreateWindow o CreateWindowEx
	RECT wr = { 0, 0, 1080, 720 };
	AdjustWindowRect(&wr, WS_OVERLAPPEDWINDOW, FALSE);//Calcula el tamaño necesario del rectángulo de la ventana.

	//Se crea la ventana definida previamente.
	hwndVentana = CreateWindowEx(NULL,//estilo extendido de ventana
		"Game",//puntero al nombre de la clase registrada *visto arriba*
		"L a    G r a n j a",//puntero al nombre de la ventana
		WS_OVERLAPPEDWINDOW,//estilo de ventana
		0,//posición horizontal de la ventana
		0,//posición vertical de la ventana
		wr.right - wr.left,//ancho de la ventana
		wr.bottom - wr.top,//alto de la ventana
		NULL,//manejador de la ventana padre o propietaria
		NULL,//manejador del menu o identificador de ventana hija
		hInstance,//manejador de la instancia de la aplicación
		NULL);//puntero a los datos de creación de la ventana

	ShowWindow(hwndVentana, nCmdShow);//Muestra la ventana creada
	ShowWindow(hInfo, SW_SHOW);

	glewInit();//Inicializa glew

	//Instancia de la escena
	scene = new Scene(hwndVentana);

	gamPad = new GamePadRR(1);
	ableToCheck = true;

	//Crear un timer con el valor especificado de time-out
	SetTimer(hwndVentana,//Manejador de ventana que recibirá los mensajes del timer
		Timer1,//identificador del timer
		30,//valor de time-out
		NULL);//dirección del procedimiento de timer

	MSG msg = { 0 };
	while (TRUE)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);

			if (msg.message == WM_QUIT)
				break;
		}
		else
		{
			if (keys[0] || keys[1] || keys[2] || keys[3] || keys[4] || keys[5] || keys[6] || keys[7] || keys[8])
			{
				scene->SaveCoords();
				if (keys[0])
				{
					scene->turnDown(); //flecha hacia abajo
				}

				if (keys[1])
				{
					scene->turnUp(); //flecha hacia arriba
				}

				if (keys[2])
				{
					scene->turnLeft(); //flecha izquierda
				}

				if (keys[3])
				{
					scene->turnRight(); //flecha derecha
				}

				if (keys[4]) //w
				{
					scene->mKeyW = true;
					scene->move('f');
				}

				if (keys[5]) //s
				{
					scene->mKeyS = true;
					scene->move('b');
				}

				if (keys[6]) //a
				{
					scene->mKeyA = true;
					scene->move('l');
				}

				if (keys[7])//d
				{
					scene->mKeyD = true;
					scene->move('r');
				}

				if (keys[8])
				{
					short option = scene->ObjectsColisions();
					scene->DoColision(option);
				}

				scene->mKeyMovePressed = true;
				renderiza = true;
			}
			else
			{
				scene->mKeyMovePressed = false;
			}

			if (renderiza)
			{
				scene->Render(hContextoVentana);
				// Llamar los metodos correspondientes a las banderas activas 
				// FlechaArriba -> true = scene....
				renderiza = false;
				if (gamPad->IsConnected())
				{
					//PISTA: Algo puedes lograr aqui con ayuda del autocompletador

				}
			}
		}
	}
	return msg.wParam;
}

LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static HGLRC hContextoGL;
	static HDC hContextoAux;
	int ancho, alto;
	char epx[6] = "";
	char epz[6] = "";
	char epy[6] = "";
	char edx[6] = "";
	char edz[6] = "";
	char edy[6] = "";
	char ec[80] = "";

	switch (message)
	{
	case WM_CREATE:
		hContextoAux = GetDC(hWnd);
		hContextoVentana = hContextoAux;
		DefPixelFormat(hContextoVentana);
		hContextoGL = wglCreateContext(hContextoVentana);
		wglMakeCurrent(hContextoVentana, hContextoGL);
		srand(time(NULL));
		break;
	case WM_KEYDOWN:
		if (wParam == VK_F1)
		{
			string info = "X: " + to_string(scene->mCoords.x) + " Y: " + to_string(scene->mCoords.y) + " Z: " + to_string(scene->mCoords.z);
			MessageBox(hWnd, info.c_str(), "INFO", MB_OK);
		}
		else
		{
			if (wParam == VK_DOWN)
			{
				keys[0] = true;
			}
			if (wParam == VK_UP)
			{
				keys[1] = true;
			}
			if (wParam == VK_LEFT)
			{
				keys[2] = true;
			}
			if (wParam == VK_RIGHT)
			{
				keys[3] = true;
			}
			if (wParam == 0x57)//w
			{
				keys[4] = true;
			}
			if (wParam == 0x53)//s
			{
				keys[5] = true;
			}
			if (wParam == 0x41)//a
			{
				keys[6] = true;
			}
			if (wParam == 0x44)//d
			{
				keys[7] = true;
			}
			if (wParam == 0x45)//e
			{
				keys[8] = true;
			}
		}
		return 0;
		break;

	case WM_KEYUP:

		if (wParam == VK_DOWN)
		{
			keys[0] = false;
		}
		if (wParam == VK_UP)
		{
			keys[1] = false;
		}
		if (wParam == VK_LEFT)
		{
			keys[2] = false;
		}
		if (wParam == VK_RIGHT)
		{
			keys[3] = false;
		}
		if (wParam == 0x57)//w
		{
			keys[4] = false;
		}
		if (wParam == 0x53)//s
		{
			keys[5] = false;
		}
		if (wParam == 0x41)//a
		{
			keys[6] = false;
		}
		if (wParam == 0x44)//d
		{
			keys[7] = false;
		}
		if (wParam == 0x45)//e
		{
			keys[8] = false;
		}
		return 0;
		break;

	case WM_TIMER:
	{
		renderiza = true;
	}
	break;

	case WM_DESTROY:
	{
		KillTimer(hWnd, Timer1);
		delete scene;
		wglMakeCurrent(hContextoVentana, NULL);
		wglDeleteContext(hContextoGL);
		PostQuitMessage(0);
		return 0;
	} break;

	case WM_SIZE:
	{
		alto = HIWORD(lParam);
		ancho = LOWORD(lParam);
		if (alto == 0)
			alto = 1;
		glViewport(0, 0, ancho, alto);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(45.0f, (float)ancho / (float)alto, 1.0f, 10000.0f);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}
	break;
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}

void DefPixelFormat(HDC hDC)
{
	int bestMatch;

	static PIXELFORMATDESCRIPTOR pfd =
	{
		sizeof(PIXELFORMATDESCRIPTOR), //tamaño de la estructura
		1, //numero de version
		PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER, //soporta la ventana, el opengl y manejara doble buffer
		PFD_TYPE_RGBA, //formato de 32 bits rgba
		32, //tamaño del color en 32 bits
		0, 0, 0, 0, 0, 0, //bits de color, no se usan
		0, //no hay buffer para el alfa
		0, //ignore el bit de corrimiento
		0, //no hay buffer de acumulacion
		0, 0, 0, 0, //no hay bits de acumulacion
		16, //tamaño del flotante para el buffer z
		0, //no hay buffers de stencil
		0, //no hay buffers auxiliares
		PFD_MAIN_PLANE, //plano principal para dibujo
		0, //reservado
		0, 0, 0 //mascaras de capas ignoradas
	};
	bestMatch = ChoosePixelFormat(hDC, &pfd);
	SetPixelFormat(hDC, bestMatch, &pfd);
}