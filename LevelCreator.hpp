#pragma once

#include <vector>
#include <string>


class Level;


namespace LevelCreator {

Level createLevelFromText (const std::vector<std::string>& lines);

}
