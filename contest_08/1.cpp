#include <iostream>

class Keeper{
    int trash;
    int secret;
    
public:
    Keeper(){
        std::cin >> secret;
    }
};

// Начало вставленного кода
#include <cstring>

struct Hack {
    int trash;
    int secret;
};

int hack_it(const Keeper& keeper) {
    Hack h;
    std::memcpy(&h, &keeper, sizeof(Hack));
    return h.secret;
}
// Конец вставленного кода

int main(){
    Keeper keeper;
    int secret= hack_it(keeper);
    std::cout << secret;
}
