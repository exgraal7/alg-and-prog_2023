#include <iostream>
using namespace std;

string compressRLE(string input) {
    int n = input.length();
    string result = "";

    for (int i = 0; i < n; i++) {
        int count = 1;
        while (i < n - 1 && input[i] == input[i + 1]) {
            count++;
            i++;
        }

        result += input[i];
        if (count > 1) {
            result += to_string(count);
        }
    }

    return result;
}

int main() {
    string input;
    getline(cin, input);

    string compressed = compressRLE(input);
    cout << compressed << endl;

    return 0;
}
