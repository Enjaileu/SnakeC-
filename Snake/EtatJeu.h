#pragma once
#include "Etat.h"
#include "Constants.h"
#include "Serpent.h"
#include "Tilemap.h"

class EtatJeu :
    public Etat
{
public:
    void Load() override;
    void Update(float dt) override;
    void Draw() override;
    void Unload() override;

private:
    void GestionPomme();
    void GestionCollisionsCarte();

    Serpent serpent{ Constants::SERPENT_DEPART_X, Constants::SERPENT_DEPART_Y };
    Segment pomme{ "assets/pomme.png", Constants::CoordX(16), Constants::CoordY(3) };

    Tilemap tilemap{};

    ProchainEtat prochainEtat() override;
    ProchainEtat transition{ ProchainEtat::None };
};


