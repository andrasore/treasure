# treasure
## An extremely simple roguelike RPG for UNIX
In this game the player must find the treasure, and exit the dungeon.
There can be monsters, and traps on a map.

The player can kill the monster, but only if a sword is found first,
or else the monster will kill the player. The traps can be only crossed once.
The potion increases the HP a little.

If you exit the dungeon before the treasure is found you also lose.

###Compile and run

The build is performed with CMake. The game will probably compile on all UNIX-like OSes with a C++14 capable compiler.

Just create a directory, and:

    cmake ../path-to-source-dir
    make

###Maps
Maps are stored in plaintext files. The rows of the map should have equal lengths.

The game doesn't really check whether the provided map is valid or not.

Example map:

    xxxxxxxxxxxxxxxxxxxx
    xk s    xxxxxx i   x
    xxxxxxx xxxxxxxxxx x
    x                  x
    xxxxxxx xxxxxxxxxxxx
    x  c               x
    x xxxxx xxxxxxxxxxxx
    xax                x
    x xxxxxxxxxxxx xxxxx
    x   s             hj
    xxxxxxxxxxxxxxxxxxxx


###Map legend
* h: hero
* x: wall
* s: monster
* c: trap
* a: sword
* i: health potion
* k: treasure
* j: exit
