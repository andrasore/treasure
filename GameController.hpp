#pragma once

#include <memory>
#include "Level.hpp"

class GameObject;
class GameClass;

enum class GameState {
    Running,
    Won,
    Died,
    GaveUp
};

enum class Direction {
    Up,
    Down,
    Left,
    Right
};


struct GameData {
    int  playerHealth      = 2;
    bool playerHasSword    = false;
    bool playerHasTreasure = false;

    GameState state = GameState::Running;
};


typedef std::function<void (const GameData&, const Level&)> DisplayFunction;


class GameController {
    friend class GameCommands;

public:
    GameController (const Level& level, const DisplayFunction& displayFunction);

    bool      isFinished () const;
    GameState getState   () const;

    void tryPlayerMove (Direction direction);
    void solve ();

private:
    GameData data;
    std::shared_ptr<GameObject> player;
    Level level;

    DisplayFunction displayFunction; //called after processing input
};

