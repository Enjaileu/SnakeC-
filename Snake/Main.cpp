#include "raylib.h"
#include "Constants.h"
#include "Serpent.h"
#include "Segment.h"
#include "GestionTexture.h"

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

float horloge{ 0.0f };
void GestionPomme();

//Code et définition
//------------------------------------------------------------------

void Load() {
	InitWindow(Constants::SCREEN_WIDTH, Constants::SCREEN_HEIGHT, "Snake");
	SetTargetFPS(60);

	gestionTexture.Load();
	serpent.Load();
	pomme.Load();
}

void Draw() {

	BeginDrawing();
	ClearBackground(BLACK);

	serpent.Draw();
	pomme.Draw();

	EndDrawing();
}
void Update() {
	float dt = GetFrameTime();
	serpent.Update(dt);
	GestionPomme();
}

void Unload() {
	gestionTexture.Unload();
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
		float nombreZeroUn = (float)rand() / (float)RAND_MAX;
		float x = nombreZeroUn * Constants::SCREEN_WIDTH;
		nombreZeroUn = (float)rand() / (float)RAND_MAX;
		float y = nombreZeroUn * Constants::SCREEN_HEIGHT;
		x = x - ((int)x % (int)Constants::SEGMENT_TAILLE);
		y = y - ((int)y % (int)Constants::SEGMENT_TAILLE);
		pomme.Positionner(x, y);
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