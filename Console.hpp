#pragma once
#include "GameController.hpp"
#include "GameObject.hpp"
#include "GameClass.hpp"

namespace Console {

void printGameScreen (const GameData& data, const Level& level);

char getInputChar ();

}
