#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
double p;
p = sqrt(12) * (1 - 1.0 / (3 * 3) + 1.0 / (5 * pow(3, 2)) - 1.0 / (7 * pow(3, 3)) + 1.0 / (9 * pow(3, 4)) - 1.0 / (11 * pow(3, 5)));
cout << setprecision(10) << p;
return 0;
}
