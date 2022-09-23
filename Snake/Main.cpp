#include "raylib.h"
#include "Constants.h"
#include "GestionTexture.h"
#include "EtatJeu.h"
#include "EtatMenu.h"
#include "EtatGameover.h"

//declaration
//------------------------------------------------------------------

void Load();
void Draw();
void Update();
void Unload();

EtatMenu etatMenu{};
EtatJeu etatJeu{};
EtatGameover etatGameOver{};
Etat& etatCourrant = etatJeu;

vector<string> nomsTextures{
"assets/case.png",
"assets/mur.png",
"assets/pomme.png",
"assets/segment.png",
"assets/tete.png"
};
GestionTexture gestionTexture{ nomsTextures };

float horloge{ 0.0f };

//Code et définition
//------------------------------------------------------------------

void Load() {
	InitWindow(Constants::SCREEN_WIDTH, Constants::SCREEN_HEIGHT, "Snake");
	SetTargetFPS(60);

	gestionTexture.Load();
	etatCourrant.Load();
}

void Draw() {

	BeginDrawing();
	ClearBackground(BLACK);
	etatCourrant.Draw();

	EndDrawing();
}
void Update() {
	float dt = GetFrameTime();
	etatCourrant.Update(dt);
}

void Unload() {
	gestionTexture.Unload();
	etatCourrant.Unload();

	CloseWindow();
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