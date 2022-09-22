#pragma once

#include "Sprite.h"
#include <string>

using namespace std;

class Tile : public Sprite
{
public:
	Tile(string cheminTextureP, int xCartP, int yCarteP, bool passableP);
	int xCarte{ 0 };
	int yCarte{ 0 };
	bool passable{ true };
};

