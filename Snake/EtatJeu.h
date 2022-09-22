#pragma once
#include "Etat.h"

class EtatJeu :
    public Etat
{
    void Load() override;
    void Update(float dt) override;
    void Draw() override;
    void Unload() override;
};


