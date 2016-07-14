#include "GameObject.hpp"


GameObject::GameObject (const GameClass& gameClass):
    gameClass (gameClass) {
}


const GameClass& GameObject::getGameClass () const {
    return gameClass;
}


