#include <iostream>
#include <memory>
#include "LevelCreator.hpp"
#include "Level.hpp"
#include "GameClassInstances.hpp"
#include "GameObject.hpp"


static bool checkEqualLineLengths (const std::vector<std::string>& lines) {
    int length = lines.at (0).length ();

    for (const std::string& line : lines) {
        if (length != line.length ()) {
            return false;
        }
    }

    return true;
}


namespace LevelCreator {


Level createLevelFromText (const std::vector<std::string>& lines) {

    if (lines.empty ()) {
        std::cerr << "error: map file is empty!";
        std::exit (2);
    }

    if (!checkEqualLineLengths (lines)) {
        std::cerr << "error: text lines are not the same length!";
        std::exit (3);
    }

    Level level (lines.at (1).length (), lines.size ());

    try {

        for (int i = 0; i < level.getHeight (); i++) {
            for (int h = 0; h < level.getWidth (); h++) {
                char classId = lines.at (i).at (h);
                if (classId != ' ') {
                    auto gameClass = GameClassInstances::get ().at (classId);
                    auto gameObject = std::make_shared<GameObject> (GameObject (*gameClass));
                    level.setObject ({h, i}, gameObject);
                }
            }
        }

    } catch (const std::out_of_range& ex) {
        std::cerr << "error: invalid level content!";
        std::exit (4);
    }

    return level;
}

}
