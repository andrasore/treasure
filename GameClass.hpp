#pragma once

#include <functional>

class GameCommands;


class GameClass { //each instance represents a GameObject type
public:
    GameClass (char id, const std::function<void (GameCommands&)>& interactionFunction);

    char  getId () const;

    const std::function<void (GameCommands&)> interactionFunction; //for interacting with player

private:
    char id;
};
