#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

int main() {
    int n, m;
    std::cin >> n;
    std::set<std::string> set1, set2;
    
    for (int i = 0; i < n; ++i) {
        std::string word;
        std::cin >> word;
        set1.insert(word);
    }

    std::cin >> m;

    for (int i = 0; i < m; ++i) {
        std::string word;
        std::cin >> word;
        if (set1.find(word) != set1.end()) {
            set2.insert(word);
        }
    }

    if (!set2.empty()) {
        std::vector<std::string> common_words(set2.begin(), set2.end());
        std::sort(common_words.begin(), common_words.end());
        for (const std::string& word : common_words) {
            std::cout << word << " ";
        }
    } else {
        std::cout << "-1";
    }

    return 0;
}