#include "Serpent.h"

Serpent::Serpent(float xP, float yP)
{
	tete.Positionner(xP, yP);
	RepositionnerQueue();
}

void Serpent::Load()
{
	tete.Load();
	for (Segment& segment : queue) {
		segment.Load();
	}
}

void Serpent::Draw()
{
	tete.Draw();
	for (Segment& segment : queue) {
		segment.Draw();
	}
}

void Serpent::Update(float dt)
{
	// Gestion du temps
	horloge += dt;
	if (horloge >= Constants::HORLOGE) {
		Deplacer();
		horloge -= Constants::HORLOGE;

		// Gestion de la défaite
		if (Autocollision()) {
			direction = 0;
			tete.Positionner(Constants::SERPENT_DEPART_X, Constants::SERPENT_DEPART_Y);
			RepositionnerQueue();
		}
	}


	// Gestion de la direction
	if (IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)) {
		if (direction == 0 || direction == 8) { return; }
		direction = 2;
	}
	else if (IsKeyPressed(KEY_Z) || IsKeyPressed(KEY_UP)) {
		if (direction == 2) { return; }
		direction = 8;
	}
	else if (IsKeyPressed(KEY_Q) || IsKeyPressed(KEY_LEFT)) {
		if (direction == 6) { return; }
		direction = 4;
	}
	else if (IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)) {
		if (direction == 4) { return; }
		direction = 6;
	}
}

void Serpent::Unload()
{
	tete.Unload();
	for (Segment& segment : queue) {
		segment.Unload();
	}
}

Rectangle Serpent::GetRectangleTete()
{
	return tete.GetRectangle();
}

void Serpent::AjouterSegment()
{
	float coordX = queue[queue.size() - 1].x;
	float coordY = queue[queue.size() - 1].y + Constants::SEGMENT_TAILLE;
	Segment nouveau{ "assets/segment.png", coordX, coordY };
	nouveau.Load();
	queue.push_back(nouveau);
}

void Serpent::Deplacer()
{
	if (direction != 0) {
		for (int i = queue.size() - 1; i > 0; --i) {
			queue[i].Positionner(queue[i - 1].x, queue[i - 1].y);
		}
		queue[0].Positionner(tete.x, tete.y);
	}
	switch (direction) {
	case 2:
		tete.y += Constants::SEGMENT_TAILLE;
		break;
	case 8:
		tete.y -= Constants::SEGMENT_TAILLE;
		break;
	case 4 :
		tete.x -= Constants::SEGMENT_TAILLE;
		break;
	case 6 :
		tete.x += Constants::SEGMENT_TAILLE;
		break;
	default:
		break;
	}
}

void Serpent::RepositionnerQueue()
{
	
	for (unsigned int i = 1; i < queue.size()+1; ++i) { 
		queue[i - 1].Positionner(tete.x, tete.y + (i * Constants::SEGMENT_TAILLE));
	}

	for (int j = queue.size() - 1; j > 2; --j) {
		queue[j].Unload();
		queue.erase(begin(queue) + j);
	}
}

bool Serpent::Autocollision()
{
	for (Segment& segment : queue) {
		if (abs(tete.x- segment.x) < 0.0001f && abs(tete.y - segment.y) < 0.0001f) {
			return true;
		}
	}
	return false;
}
