#include <iostream>

using namespace std;

int main() {
  float vetor[] = {1.5, 0.3, 4.7, 8.8, 0.1};
  
  for (auto n : vetor) {
        n *= 2;
  }

  cout << vetor[0] << endl;
  return 0;
}