#include <iostream>
#include <string>
#include <map>

std::map<std::string, double> bonuses;

//Начало вставленного кода
class Employee {
protected:
    std::string name, position;
    int base_money;

public:
    Employee(std::string name, std::string position, int base_money)
        : name(name), position(position), base_money(base_money) {}

    virtual int bonus(double percent) const {
        return static_cast<int>(base_money * percent + 0.5);
    }

    friend std::ostream& operator<<(std::ostream& os, const Employee& e) {
        os << e.name << " (" << e.position << "): " << e.base_money + e.bonus(bonuses[e.position]);
        return os;
    }
};

class Manager : public Employee {
public:
    Manager(std::string name, int base_money = 16242)
        : Employee(name, "manager", base_money) {}

    int bonus(double percent) const override {
        if (percent < 0.1) {
            percent = 0.1;
        }
        return static_cast<int>(base_money * percent + 0.5);
    }
};
// Конец вставленного кода

class Boss: public Employee{
public:
    Boss(std::string name, int money = 16242)
    :Employee(name, "boss", money){
    }
};

int main(){
    double boss_bonus, manager_bonus;
    std::cin >> boss_bonus >> manager_bonus;
    bonuses["manager"] = manager_bonus;
    bonuses["boss"] = boss_bonus;

    int john_money, bob_money, alice_money;
    std::cin >> john_money >> bob_money >> alice_money;
    Boss john("John", john_money);
    Manager bob("Bob", bob_money);
    Manager alice("Alice", alice_money);

    std::cout << john << '\n' << bob << '\n' << alice << std::endl;
}
