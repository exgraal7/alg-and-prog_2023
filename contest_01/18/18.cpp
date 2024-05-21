#include <iostream>
using namespace std;

string excelColumnName(int n) {
    string result = "";
    while (n > 0) {
        int remainder = (n - 1) % 26;
        result = char('A' + remainder) + result;
        n = (n - 1) / 26;
    }
    return result;
}

int main() {
    int n;
    cin >> n;

    string columnName = excelColumnName(n);
    cout << columnName << endl;

    return 0;
}
