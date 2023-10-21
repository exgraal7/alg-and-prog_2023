#include <iostream>
#include <map>
#include <string>

int main() {
    int n, m;

    std::cin >> n;

    std::map<std::string, std::string> user_balance;
    std::cin.ignore(); 
    for (int i = 0; i < n; i++) { 
        std::string line;
        std::getline(std::cin, line);
        size_t pos = line.find(';');
        if (pos != std::string::npos) {
            std::string login = line.substr(0, pos);
            std::string balance = line.substr(pos + 1);
            user_balance[login] = balance;
        }
    }

    std::cin >> m;
    std::cin.ignore(); 

    for (int i = 0; i < m; i++) {
        std::string login;
        std::cin >> login;
        std::cout << user_balance[login] << " ";
    }

    return 0;
}