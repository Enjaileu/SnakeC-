#include "raylib.h"
#include "Constants.h"
#include "Serpent.h"
#include "Segment.h"
#include "GestionTexture.h"
#include "Tilemap.h"

//declaration
//------------------------------------------------------------------

void Load();
void Draw();
void Update();
void Unload();

vector<string> nomsTextures{
"assets/case.png",
"assets/mur.png",
"assets/pomme.png",
"assets/segment.png",
"assets/tete.png"
};
GestionTexture gestionTexture{ nomsTextures };


Serpent serpent{ Constants::SERPENT_DEPART_X, Constants::SERPENT_DEPART_Y };
Segment pomme{ "assets/pomme.png", 400, 96};

Tilemap tilemap{};

float horloge{ 0.0f };
void GestionPomme();
void GestionCollisionsCarte();

//Code et définition
//------------------------------------------------------------------

void Load() {
	InitWindow(Constants::SCREEN_WIDTH, Constants::SCREEN_HEIGHT, "Snake");
	SetTargetFPS(60);

	gestionTexture.Load();
	tilemap.Load();
	serpent.Load();
	pomme.Load();
}

void Draw() {

	BeginDrawing();
	ClearBackground(BLACK);

	tilemap.Draw();
	serpent.Draw();
	pomme.Draw();

	EndDrawing();
}
void Update() {
	float dt = GetFrameTime();
	serpent.Update(dt);
	GestionPomme();
	GestionCollisionsCarte();
}

void Unload() {
	gestionTexture.Unload();
	tilemap.Unload();
	serpent.Unload();
	pomme.Unload();

	CloseWindow();
}

void GestionPomme() {
	//Pomme attrapée
	Rectangle rectangleTete = serpent.GetRectangleTete();
	if (CheckCollisionRecs(rectangleTete, pomme.GetRectangle())) {
		serpent.AjouterSegment();
		//Nouvelle position de la pomme
		float nombreEntreZeroEtUn = (float)rand() / (float)RAND_MAX;
		int carteX = floor(nombreEntreZeroEtUn * (Constants::CARTE_TAILLE_X - 2)) + 1;
		float x = Constants::CoordX(carteX);
		nombreEntreZeroEtUn = (float)rand() / (float)RAND_MAX;
		int carteY = floor(nombreEntreZeroEtUn * (Constants::CARTE_TAILLE_Y - 2)) + 1;
		float y = Constants::CoordY(carteY);
		pomme.Positionner(x, y);
	}
}

void GestionCollisionsCarte() {
	int carteX = Constants::CarteX(serpent.GetX());
	int carteY = Constants::CarteY(serpent.GetY());
	if (!tilemap.CasePassable(carteX, carteY)) {
		serpent.Recommencer();
	}
}

int main() {
	Load();

	while (!WindowShouldClose()) {
		Update();
		Draw();
	}

	Unload();
	return 0;
}