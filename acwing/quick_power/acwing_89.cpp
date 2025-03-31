// https://www.acwing.com/problem/content/description/91/

#include <iostream>

using namespace std;

using  LL = long long;

LL quick_power(LL a, LL b, LL p) {
    LL res = 1;
    while (b > 0) {
        if (b & 1) {
            res = res * a % p; 
        }
        b = b >> 1;
        a = a * a % p;
    }
    res = res % p;
    return res;
}

int main() {
    LL a, b, p;
    cin >> a >> b >> p;
    LL res = quick_power(a, b, p);
    cout << res << endl;
    
    return 0;
}
