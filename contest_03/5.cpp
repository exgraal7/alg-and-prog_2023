#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();

    string text;
    getline(cin, text);

    map<string, int> wordCount; 

    string word;
    for (size_t i = 0; i < text.length(); ++i) {
        if (isalpha(text[i])) {
            word += text[i];
        } else {
            if (!word.empty()) {
                wordCount[word]++;
                word.clear();
            }
        }
    }
    if (!word.empty()) {
        wordCount[word]++;
    }

    int maxCount = 0;
    for (const auto& pair : wordCount) {
        maxCount = max(maxCount, pair.second);
    }

    vector<string> mostFrequentWords;
    for (const auto& pair : wordCount) {
        if (pair.second == maxCount) {
            mostFrequentWords.push_back(pair.first);
        }
    }

    sort(mostFrequentWords.begin(), mostFrequentWords.end());

    for (size_t i = 0; i < mostFrequentWords.size(); ++i) {
        cout << mostFrequentWords[i];
        if (i < mostFrequentWords.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}