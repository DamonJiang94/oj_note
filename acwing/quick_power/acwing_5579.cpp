// https://www.acwing.com/problem/content/description/5582/
//
//

#include <iostream>

using namespace std;


int qpower(int a, int b, int m) {
  int res = 1;
  a = a % m;
  while (b) {
    if (b & 1) {
      res = res * a % m;
    }
    b = b >> 1;
    a = a * a % m;
  }
  res = res % m;
  return res;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    int m;
    cin >> m;
    int h;
    cin >> h;
    int res = 0;
    for (int j = 0; j < h; j++) {
      int a, b;
      cin >> a >> b;
      res = (res + qpower(a, b, m)) % m;
    }
    res = res % m;
    cout << res << endl;
  }

  return 0;
  
}

