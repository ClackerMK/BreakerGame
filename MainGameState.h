#pragma once

#include "GameState.h"

#include "Map.h"

class MainGameState : public brk::GameState
{
public:
	std::unique_ptr<GameState> update(sf::Time dt) override;
	void draw() override;
	
private:
	brk::CellGrid gamemap_;


};
