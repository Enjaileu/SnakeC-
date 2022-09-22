#include "Tilemap.h"

Tilemap::Tilemap()
{
	carte.reserve(tailleX * tailleY);
	for (int x = 0; x < tailleX; ++x) {
		for (int y = 0; y < tailleY; ++y) {
			if (x == 0 || y == 0
				|| x == tailleX - 1 || y == tailleY - 1) {
				Tile nouveau{ "assets/mur.png", x, y, false };
				carte.push_back(nouveau);
			}
			else {
				Tile nouveau{ "assets/case.png", x, y, true };
				carte.push_back(nouveau);
			}
		}
	}
}

void Tilemap::Load() {
	for (int x = 0; x < tailleX; ++x) {
		for (int y = 0; y < tailleY; ++y) {
			carte[x * tailleY + y].Load();
		}
	}
}
void Tilemap::Draw() {
	for (int x = 0; x < tailleX; ++x) {
		for (int y = 0; y < tailleY; ++y) {
			carte[x * tailleY + y].Draw();
		}
	}
}
void Tilemap::Unload() {
	for (int x = 0; x < tailleX; ++x) {
		for (int y = 0; y < tailleY; ++y) {
			carte[x * tailleY + y].Unload();
		}
	}
}
