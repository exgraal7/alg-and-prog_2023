#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool arePermutations(string num1, string num2) {
    sort(num1.begin(), num1.end());
    sort(num2.begin(), num2.end());

    return num1 == num2;
}

int main() {
    string num1, num2;
    cin >> num1 >> num2;

    if (arePermutations(num1, num2)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}