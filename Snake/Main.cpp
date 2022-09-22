#include "raylib.h"
#include "Constants.h"
#include "Serpent.h"

//declaration
//------------------------------------------------------------------

void Load();
void Draw();
void Update();
void Unload();

Serpent serpent{ Constants::SERPENT_DEPART_X, Constants::SERPENT_DEPART_Y };

float horloge{ 0.0f };
void DeplacerSerpent();

//Code et définition
//------------------------------------------------------------------

void Load() {
	InitWindow(Constants::SCREEN_WIDTH, Constants::SCREEN_HEIGHT, "Snake");
	SetTargetFPS(60);

	serpent.Load();
}

void Draw() {

	BeginDrawing();
	ClearBackground(BLACK);

	serpent.Draw();

	EndDrawing();
}
void Update() {
	float dt = GetFrameTime();
	serpent.Update(dt);
}

void Unload() {
	serpent.Unload();

	CloseWindow();
}

void DeplacerSerpent() {
	
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