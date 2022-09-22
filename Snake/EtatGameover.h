#pragma once
#include "Etat.h"
class EtatGameover :
    public Etat
{
    void Load() override;
    void Update(float dt) override;
    void Draw() override;
    void Unload() override;
};

