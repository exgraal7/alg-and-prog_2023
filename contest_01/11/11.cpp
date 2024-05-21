#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a, b, c;
    
    cin >> a >> b >> c;
    
    int distanceB = abs(b - a);
    int distanceC = abs(c - a);
    
    if (distanceB < distanceC) {
        cout << "B " << distanceB << endl;
    } else {
        cout << "C " << distanceC << endl;
    }
    
    return 0;
}
