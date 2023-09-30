#include <iostream>
using namespace std;

int main() {
    double m, h;
    
    cin >> m >> h;
    
    double bmi = m / (h * h);
    
    cout << bmi << endl;
    
    return 0;
}