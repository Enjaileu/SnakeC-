#pragma once
class Constants
{
public:
	//SCREEN
	static const int SCREEN_WIDTH;
	static const int SCREEN_HEIGHT;

	//UI
	static const int VERTICAL_SEPARATION;

	// Serpent
	static const int SEGMENT_TAILLE;
	static const float HORLOGE;
	static const float SERPENT_DEPART_X;
	static const float SERPENT_DEPART_Y;

	// Carte
	static const int CARTE_TAILLE_X;
	static const int CARTE_TAILLE_Y;
	static float coordX(int xCarte);
	static float coordY(int yCarte);
};

