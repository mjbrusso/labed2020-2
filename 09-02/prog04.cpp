#include <iostream>

using namespace std;

int main() {
  double matriz[3][3] = {{1.1, 2.2, 3.3}, {4.4, 5.5, 6.6}, {7.7, 8.8, 9.9}};

  for (auto &linha : matriz) {
    for (auto &f : linha) {
      cout << f << '\t';
    }
    cout << endl;
  }
  return 0;
}
