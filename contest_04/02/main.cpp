#include <iostream>
#include <fstream>

#include "json.hpp"
using json = nlohmann::json;

int main() {
    int target;
    std::cin >> target;

    std::ifstream f("data.json");
    json data = json::parse(f);

    int answer = 0;
    for (auto prj : data) {
        for (auto tsk : prj["tasks"]) {
            if (tsk["user_id"] == target && tsk["completed"]) {
                answer++;
            }
        }
    }

    std::cout << answer << "\n";
    return 0;
}
