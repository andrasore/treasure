#pragma once

class GameClass;


class GameObject {
public:
    GameObject (const GameClass& gameClass);

    const GameClass& getGameClass () const;

private:
    const GameClass& gameClass; //represents the in-game class of an instance
};


