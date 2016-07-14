#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <iostream>
#include "Console.hpp"
#include "Level.hpp"
#include "GameObject.hpp"
#include "GameClass.hpp"
#include "GameController.hpp"

static void printLevel (const Level& level) {
    for (int i = 0; i < level.getHeight (); i++) {
        for (int h = 0; h < level.getWidth (); h++) {
            if (!level.isEmpty ({h, i})) {
                auto object = level.getObject ({h, i});
                std::cout << object->getGameClass ().getId ();
            } else {
                std::cout << ' ';
            }
        }
        std::cout << "\n";
    }
}

namespace Console {


void printGameScreen (const GameData& data, const Level& level) {

    printLevel (level);
    std::cout << "\n";

    std::cout << "health: " << data.playerHealth << "\n";
    std::cout << "sword: " << data.playerHasSword  << "\n";
    std::cout << "\n";

    switch (data.state) {
        case GameState::Won:
            std::cout << "You found the treasure, and managed to escape!";
            break;
        case GameState::Died:
            std::cout << "You are killed by a monster!";
            break;
        case GameState::GaveUp:
            std::cout << "You gave up!";
            break;
        case GameState::Running:
            break;
    }

}

char getInputChar () { //UNIX-dependant
  struct termios oldt,
                 newt;
  int            ch;

  tcgetattr (STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);

  tcsetattr (STDIN_FILENO, TCSANOW, &newt);

  ch = getchar ();

  tcsetattr (STDIN_FILENO, TCSANOW, &oldt);

  return ch;
}


}
