#pragma once

#include "Segment.h"
#include <vector>
#include "Constants.h"
#include <cmath>

using namespace std;

class Serpent
{
public:
	Serpent(float xP, float yP);
	void Load();
	void Draw();
	void Update(float dt);
	void Unload();
	Rectangle GetRectangleTete();
	void AjouterSegment();
	void Recommencer();
	float GetX();
	float GetY();

private:
	void Deplacer();
	void RepositionnerQueue();
	bool Autocollision();

	float horloge{ 0.0f };
	Segment tete{ "assets/tete.png", 0, 0 };
	vector<Segment> queue{
		{"assets/segment.png", 0, 0 + (float)Constants::SEGMENT_TAILLE},
		{"assets/segment.png", 0, 0 + (float)Constants::SEGMENT_TAILLE * 2},
		{"assets/segment.png", 0, 0 + (float)Constants::SEGMENT_TAILLE * 3}
	};

	int direction{ 0 };
};

