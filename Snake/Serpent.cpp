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
}
