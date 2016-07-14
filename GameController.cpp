#include <algorithm>
#include "GameController.hpp"
#include "GameCommands.hpp"
#include "GameObject.hpp"
#include "GameClass.hpp"
#include "Level.hpp"


static ObjectRef getPlayer (const Level& level) {
    for (const auto& object : level) {
        if (object != nullptr && object->getGameClass ().getId () == 'h') {
            return object;
        }
    }

    return nullptr;
}


static Coords operator+ (const Coords& coords, Direction dir) {
    switch (dir) {
        case Direction::Left :
            return {coords.x - 1, coords.y};
        case Direction::Right :
            return {coords.x + 1, coords.y};
        case Direction::Up :
            return {coords.x, coords.y - 1};
        case Direction::Down :
            return {coords.x, coords.y + 1};
        default:
            return {-1, -1};
    }
}


GameController::GameController (const Level& level, const DisplayFunction& displayFunction) :
    level (level),
    player (getPlayer (level)),
    displayFunction (displayFunction) {

    displayFunction (data, level); //displaying the game initially
}


bool GameController::isFinished () const {
    return data.state != GameState::Running;
}


GameState GameController::getState () const {
    return data.state;
}


void GameController::tryPlayerMove (Direction direction) {
    if (isFinished ()) {
        return;
    }

    Coords playerCoords = level.getObjectCoords (player);

    Coords playerDestination = playerCoords + direction;

    if (level.isValidCoord (playerDestination)) {

        if (!level.isEmpty (playerDestination)) {
            ObjectRef targetObject = level.getObject (playerDestination);

            auto interaction = targetObject->getGameClass ().interactionFunction;

            GameCommands commands (*this, targetObject);

            interaction (commands);
        } else {
            level.setObject (playerDestination, player);
            level.clear (playerCoords);
        }
    }

    displayFunction (data, level);
}


void GameController::solve () {
    //todo
}
