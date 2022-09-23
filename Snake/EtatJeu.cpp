#include "EtatJeu.h"

void EtatJeu::Load() {
	tilemap.Load();
	serpent.Load();
	pomme.Load();
}
void EtatJeu::Update(float dt) {
	serpent.Update(dt);
	GestionPomme();
	GestionCollisionsCarte();
	if (serpent.GetDefaite()) {
		transition = ProchainEtat::Gameover;
	}
}
void EtatJeu::Draw() {
	tilemap.Draw();
	serpent.Draw();
	pomme.Draw();
}
void EtatJeu::Unload() {
	tilemap.Unload();
	serpent.Unload();
	pomme.Unload();
}

void EtatJeu::GestionPomme() {
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

void EtatJeu::GestionCollisionsCarte() {
	int carteX = Constants::CarteX(serpent.GetX());
	int carteY = Constants::CarteY(serpent.GetY());
	if (!tilemap.CasePassable(carteX, carteY)) {
		transition = ProchainEtat::Gameover;
	}
}

ProchainEtat EtatJeu::prochainEtat()
{
	ProchainEtat nouvelEtat = transition;
	transition = ProchainEtat::None;
	return nouvelEtat;
}
