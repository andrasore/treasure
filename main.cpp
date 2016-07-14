#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <string>

#include "GameController.hpp"
#include "LevelCreator.hpp"
#include "GameObject.hpp"
#include "GameClass.hpp"
#include "Console.hpp"


static void checkArgumentNumber (int argc) {
    if (argc != 2) {
        std::cout << "usage: szerezdmeg <path to level file>";
        std::exit (1);
    }
}


static std::vector<std::string> readTextFromFile (const char* fileName) {
    std::vector<std::string> lines;

    std::ifstream file (fileName);

    if (file.is_open ()) {
        std::string line;

        while (std::getline (file, line)) {
            lines.push_back (line);
        }

        file.close ();

    } else {
        std::cerr << "error: cannot open file!";
    }

    return lines;
}


static void handleInput (GameController& gameController, char input) {
        switch (input) {
            case 'w':
                gameController.tryPlayerMove (Direction::Up);
                break;
            case 'a':
                gameController.tryPlayerMove (Direction::Left);
                break;
            case 's':
                gameController.tryPlayerMove (Direction::Down);
                break;
            case 'd':
                gameController.tryPlayerMove (Direction::Right);
                break;
            case 'c':
                gameController.solve ();
                break;
        }
}



int main (int argc, char** argv) {
    checkArgumentNumber (argc);

    auto levelTextLines = readTextFromFile (argv[1]);

    Level level = LevelCreator::createLevelFromText (levelTextLines);

    GameController gameController (level, Console::printGameScreen);

    while (!gameController.isFinished ()) {
        char input = Console::getInputChar ();
        handleInput (gameController, input);
    }

    return 0;
}
