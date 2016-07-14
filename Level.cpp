#include <algorithm>
#include <memory>
#include "Level.hpp"


Coords operator- (const Coords& left, const Coords& right) {
    return {left.x - right.x, left.y - right.y};
}


Coords operator+ (const Coords& left, const Coords& right) {
    return {left.x + right.x, left.y + right.y};
}


Level::Level (int width, int height) :
    height  (height),
    width   (width),
    objects (width * height) {
}


int Level::getWidth () const {
    return width;
}


int Level::getHeight () const {
    return height;
}


ObjectRef Level::getObject (Coords coords) const {
    return objects.at (coordsToIndex (coords));
}


void Level::setObject (Coords coords, const ObjectRef& object) {
    objects.at (coordsToIndex (coords)) = object;
}


Coords Level::getObjectCoords (const ObjectRef& object) const {
    auto foundObject = std::find (objects.begin (), objects.end (), object);

    if (foundObject == objects.end ()) {
        return {-1, -1};
    } else {
        return indexToCoords (foundObject - objects.begin ());
    }
}


bool Level::isEmpty (Coords coords) const {
    return objects.at (coordsToIndex (coords)) == nullptr;
}


void Level::clear (Coords coords) {
    objects.at (coordsToIndex (coords)) = nullptr;
}


bool Level::isValidCoord (Coords coords) const {
    bool xIsValid = (0 <= coords.x && coords.x < width);
    bool yIsValid = (0 <= coords.y && coords.y < height);
    return xIsValid && yIsValid;
}


Coords Level::indexToCoords (int index) const {
    return {index % width, index / width};
}


int Level::coordsToIndex (const Coords& coords) const {
    return coords.y * width + coords.x;
}


decltype (std::cbegin (Level::objects)) Level::begin () const {
    return objects.begin ();
} 


decltype (std::cend (Level::objects))   Level::end () const {
    return objects.end ();
}
