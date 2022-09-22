#pragma once

class Etat {
public:
	virtual void Load() = 0;
	virtual void Update(float dt) = 0;
	virtual void Draw() = 0;
	virtual void Unload() = 0;
};
