#include <iostream>
#include <string>
#include <sstream>
#include <set>

using namespace std;

int main()
{
    string text;
    getline(cin, text);
    int len = text.length();
    int posend = text.find("end");
    int g = len - posend;
    text.erase(posend, g);
    stringstream ss(text);
    string word;
    set<string> res;

    while (ss >> word) {
        int d = 0;
        size_t pos = text.find(word);
        while (pos != string::npos) {
            d++;
            pos = text.find(word, pos + 1);
        }
        if (word != "end") {
            if (d > 1)
                res.insert(word);
        }
    }

    for (const string& s : res) {
        cout << s << " ";
    }

    return 0;
}