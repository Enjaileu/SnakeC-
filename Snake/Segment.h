#pragma once
#include "Sprite.h"
#include <string>

using namespace std;

class Segment :
    public Sprite
{
public:
    Segment(string cheminTextureP, float xP, float yP);
    void Positionner(float xP, float yP);
};

