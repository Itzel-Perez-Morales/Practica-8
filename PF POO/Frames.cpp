#include "Frames.h"

//manejo de frames cuando hay animaciones de fpf
Frames::Frames() {};

Frames :: Frames(string modelPath, string texturePath, bool mode) :
	Model (modelPath, texturePath, mode)
{
}