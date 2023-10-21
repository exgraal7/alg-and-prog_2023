#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n;
    std::vector<int> sequence1(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> sequence1[i];
    }

    std::cin >> m;
    std::vector<int> sequence2(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> sequence2[i];
    }

    std::vector<int> mergedSequence;
    int i = 0, j = 0;

    while (i < n && j < m) {
        if (sequence1[i] < sequence2[j]) {
            mergedSequence.push_back(sequence1[i]);
            ++i;
        } else {
            mergedSequence.push_back(sequence2[j]);
            ++j;
        }
    }

    while (i < n) {
        mergedSequence.push_back(sequence1[i]);
        ++i;
    }
    while (j < m) {
        mergedSequence.push_back(sequence2[j]);
        ++j;
    }

    for (int k = 0; k < mergedSequence.size(); ++k) {
        std::cout << mergedSequence[k];
        if (k < mergedSequence.size() - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}
