#include <iostream>

using namespace std;

int main() {
  const int nlin = 3, ncol = 4;
  double mat[nlin][ncol], aux;

  for (int i = 0; i < nlin; ++i) {
    for (int j = 0; j < ncol; ++j) {
      cout << "mat[" << i << "][" << j << "]: ";
      cin >> mat[i][j];
    }
  }

  return 0;
}
