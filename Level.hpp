#pragma once

#include <vector> 

namespace std {
    template <class Type> class shared_ptr;
}

class GameObject;


struct Coords {
    int x;
    int y;
};


Coords operator- (const Coords& left, const Coords& right);

Coords operator+ (const Coords& left, const Coords& right);



typedef std::shared_ptr<GameObject> ObjectRef;


class Level {
public:
    Level (int width, int heigth);

    int  getWidth  () const;
    int  getHeight () const;

    ObjectRef getObject (Coords coords) const;
    void      setObject (Coords coords, const ObjectRef& object);

    Coords getObjectCoords (const ObjectRef& object) const;

    bool isEmpty (Coords coords) const;
    void clear   (Coords coords);

    bool isValidCoord (Coords coords) const;

private:
    std::vector<ObjectRef> objects;
    int height;
    int width;

    Coords indexToCoords (int index) const;
    int    coordsToIndex (const Coords& coords) const;

public:
    decltype (std::cbegin (objects)) begin () const;
    decltype (std::cend (objects))   end   () const;
};
