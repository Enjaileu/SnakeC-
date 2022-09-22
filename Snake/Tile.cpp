#include "Tile.h"
#include "Constants.h"


Tile::Tile(string cheminTextureP,
	int xCarteP, int yCarteP, bool passableP) :
	Sprite{ cheminTextureP, Constants::coordX(xCarteP), Constants::coordY(yCarteP), 0, false },
	xCarte{ xCarteP }, 
	yCarte{ yCarteP },
	passable{ passableP }
{
}