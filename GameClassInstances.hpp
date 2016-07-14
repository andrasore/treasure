#pragma once

#include <map>

class GameClass;


namespace GameClassInstances {


const std::map<char, GameClass*>& get ();


}
