#include <iostream>
#include <cstdlib>

class Cat {
public:
    bool is_alive() const {
        return alive;
    }

private:
    bool alive;

    Cat(bool alive) : alive(alive) {}

    friend class Box;
};

class Box {
public:
    Cat open() {
        bool isCatAlive = (rand() % 2) == 1;
        return Cat(isCatAlive);
    }
};
