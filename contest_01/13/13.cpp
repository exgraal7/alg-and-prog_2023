#include <iostream>

int main() {
  int counter1; 
  int counter2 = 1;
  
  std::cin >> counter1;
  
  for (int n = 2; true; n++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < i; j++) {
        std::cout << counter2 << " ";
        counter2++;
        if (counter1 < counter2) {
          return 0;
        }
      }
      std::cout << '\n';
    }

    for (int i = n - 1; i > 1; i--) {
      for (int j = 0; j < i; j++) {
        std::cout << counter2 << " ";
        counter2++;
        if (counter1 < counter2) {
          return 0;
        }
      }
      std::cout << '\n';
    }
  }

  return 0;
}
