#include <iostream>
#include <deque>

class Water {
public:
    Water(int initial_temperature) : temperature(initial_temperature) {}

    bool is_boiling() const {
        return temperature >= 100;
    }

    void heat_up(int degrees) {
        temperature += degrees;
    }

private:
    int temperature;
};

class Teapot {
public:
    Teapot(Water& water_ref) : water(water_ref) {}

    bool is_boiling() const {
        return water.is_boiling();
    }

    void heat_up(int degrees) {
        water.heat_up(degrees);
    }

private:
    Water& water;
};
int main()
{
    int temperature, count;
    std::cin >> temperature >> count;
    std::deque<int> heat(count);
    for(auto& t : heat) std::cin >> t;
    
    Water water(temperature);
    Teapot teapot(water);
    
    while(not teapot.is_boiling()){
        teapot.heat_up(heat.front());
        heat.pop_front();
    }
    
    for(auto t : heat) std::cout << t << ' ';
}
