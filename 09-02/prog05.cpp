#include <iostream>

using namespace std;

int main() {
  auto n = 5;
  auto letra = 'Y';
  auto flag = true;

  float x = 3.5;
  float &y = x;

  cout << x << '\t' << y << endl;
  x *= 2;
  cout << x << '\t' << y << endl;

  return 0;
}
