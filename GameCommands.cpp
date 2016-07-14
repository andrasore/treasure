#include <algorithm>
#include "GameCommands.hpp"
#include "GameController.hpp"
#include "GameObject.hpp"
#include "Level.hpp"


GameCommands::GameCommands (GameController& controller, const ObjectRef& targetObject) :
    controller (controller),
    targetObject (targetObject) {
}


void GameCommands::setPlayerHealth (int newHealth) {
    controller.data.playerHealth = newHealth;

    if (controller.data.playerHealth <= 0) {
        controller.data.state = GameState::Died;
    }
}


int  GameCommands::getPlayerHealth () const {
    return controller.data.playerHealth;
}


void GameCommands::givePlayerSword () {
    controller.data.playerHasSword = true;
}


bool GameCommands::playerHasSword () const {
    return controller.data.playerHasSword;
}


void GameCommands::givePlayerTreasure () {
    controller.data.playerHasTreasure = true;
}


bool GameCommands::playerHasTreasure () const {
    return controller.data.playerHasTreasure;
}


void GameCommands::replaceObjectWithPlayer () {
    Coords targetObjectCoords = controller.level.getObjectCoords (targetObject);
    Coords playerCoords = controller.level.getObjectCoords (controller.player);

    controller.level.clear (playerCoords);
    controller.level.setObject (targetObjectCoords, controller.player);
}


void GameCommands::replaceObject (const GameClass& objectClass) {
    Coords targetObjectCoords = controller.level.getObjectCoords (targetObject);

    ObjectRef newObject = std::make_shared<GameObject> (GameObject (objectClass));
    controller.level.setObject (targetObjectCoords, newObject);
}


bool GameCommands::placePlayerAfterObject () {
    Coords targetObjectCoords = controller.level.getObjectCoords (targetObject);
    Coords playerCoords = controller.level.getObjectCoords (controller.player);

    Coords difference = targetObjectCoords - playerCoords;  //difference has length of 1
    Coords destinationCoords = targetObjectCoords + difference;

    if (controller.level.isValidCoord (destinationCoords)
            && controller.level.isEmpty (destinationCoords)) {
        controller.level.clear (playerCoords);
        controller.level.setObject (destinationCoords, controller.player);
        return true;
    }

    return false;
}


void  GameCommands::playerExited () const {
    if (playerHasTreasure ()) {
        controller.data.state = GameState::Won;
    } else {
        controller.data.state = GameState::GaveUp;
    }
}

