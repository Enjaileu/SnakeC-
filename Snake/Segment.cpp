#include "Segment.h"

Segment::Segment(string cheminTextureP, float xP, float yP) :
	Sprite(cheminTextureP, xP, yP, 0, false)
{
}

void Segment::Positionner(float xP, float yP)
{
	x = xP;
	y = yP;
}
