#include "GameClass.hpp"
#include "GameController.hpp"

GameClass::GameClass (char id, const std::function<void (GameCommands&)>& interactionFunction):
    id (id),
    interactionFunction (interactionFunction) {
}


char GameClass::getId () const {
    return id;
}
