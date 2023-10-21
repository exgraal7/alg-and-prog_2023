#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <set>
#include <sstream>

int main() {
    std::ifstream file("data.txt");
    std::string text;
    std::getline(file, text);

    std::string target;
    std::cin >> target;

    std::vector<std::string> words;
    std::string word;
    std::istringstream iss(text);
    while (iss >> word) {
        words.push_back(word);
    }

    std::unordered_map<std::string, int> wordCount;

    bool targetFound = false;
    for (size_t i = 0; i < words.size() - 1; i++) {
        if (words[i] == target) {
            targetFound = true;
            wordCount[words[i + 1]]++;
        }
    }

    if (!targetFound) {
        std::cout << "-" << std::endl;
        return 0;
    }

    std::set<std::string> pref;
    while (pref.size() < 3) {
        std::string answ = "";
        int maxCount = 0;
        for (const auto& entry : wordCount) {
            if (pref.count(entry.first) == 0) {
                if (entry.second > maxCount || (entry.second == maxCount && entry.first < answ)) {
                    answ = entry.first;
                    maxCount = entry.second;
                }
            }
        }

        if (answ.empty()) {
            break;
        } else {
            pref.insert(answ);
            std::cout << answ << " ";
        }
    }

    return 0;
}