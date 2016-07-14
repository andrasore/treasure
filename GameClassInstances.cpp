#include <map>

#include "GameClass.hpp"
#include "GameCommands.hpp"


namespace GameClassInstances {

GameClass exit ('j', [] (GameCommands& game) {
    game.replaceObjectWithPlayer ();
    game.playerExited ();
});

GameClass healingPotion ('i', [] (GameCommands& game) {
    if (game.getPlayerHealth () == 1) {
        game.setPlayerHealth (2);
    }
    game.replaceObjectWithPlayer ();
});

GameClass monster ('s', [] (GameCommands& game) {
    if (game.playerHasSword ()) {
        int playerHealth = game.getPlayerHealth ();
        game.setPlayerHealth (playerHealth - 1);
        game.replaceObjectWithPlayer ();
    } else {
        game.setPlayerHealth (0);
    }
});

GameClass sword ('a', [] (GameCommands& game) {
    game.replaceObjectWithPlayer ();
    game.givePlayerSword ();
});

GameClass treasure ('k', [] (GameCommands& game) {
    game.replaceObjectWithPlayer ();
    game.givePlayerTreasure ();
});

GameClass wall ('x', [] (GameCommands& game) {
    //nothing to be done
});

GameClass trap ('c', [] (GameCommands& game) {
    if (game.placePlayerAfterObject ()) {
        game.replaceObject (wall);
    }
});

GameClass player ('h', [] (GameCommands& game) {
    //unused (player doesn't interact with itself)
});



const std::map<char, GameClass*>& get () {
    static std::map<char, GameClass*> classInstances;

    if (classInstances.empty ()) {

        auto addToMap = [&] (GameClass& gameClass) {
            classInstances[gameClass.getId ()] = &gameClass;
        };

        addToMap (exit);
        addToMap (healingPotion);
        addToMap (monster);
        addToMap (sword);
        addToMap (treasure);
        addToMap (wall);
        addToMap (trap);
        addToMap (player);
    }

    return classInstances;
}


}
