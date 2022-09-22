#include "Tile.h"
#include "Constants.h"


Tile::Tile(string cheminTextureP,
	int xCarteP, int yCarteP, bool passableP) :
	Sprite{ cheminTextureP, Constants::CoordX(xCarteP), Constants::CoordY(yCarteP), 0, false },
	xCarte{ xCarteP }, 
	yCarte{ yCarteP },
	passable{ passableP }
{
}