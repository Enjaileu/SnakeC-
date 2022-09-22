#pragma once
#include "Tile.h"
#include "Constants.h"
#include <string>
#include <vector>

using namespace std;

class Tilemap {
public:
	Tilemap();
	void Load(); 
	void Draw();
	void Unload();
	int tailleX{ Constants::CARTE_TAILLE_X };
	int tailleY{ Constants::CARTE_TAILLE_Y };
	int tailleCase{ (int)Constants::SEGMENT_TAILLE };
	vector<Tile> carte;
};

