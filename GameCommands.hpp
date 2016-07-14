#pragma once

#include <memory>

class GameController;
class GameObject;
class GameClass;


typedef std::shared_ptr<GameObject> ObjectRef;


class GameCommands { //interface for GameClass instances
public:
    GameCommands (GameController& controller, const ObjectRef& targetObject);

    void setPlayerHealth (int newHealth);
    int  getPlayerHealth () const;

    void givePlayerSword    ();
    bool playerHasSword     () const;

    void givePlayerTreasure ();
    bool playerHasTreasure  () const;

    void replaceObjectWithPlayer ();
    void replaceObject           (const GameClass& objectClass);
    bool placePlayerAfterObject  ();

    void playerExited () const;

private:
    GameController& controller;
    ObjectRef targetObject;
};
