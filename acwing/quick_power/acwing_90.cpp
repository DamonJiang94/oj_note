// https://www.acwing.com/problem/content/description/92/
//
#include <iostream>

using namespace std;

using LL = long long;

LL large_mul(LL a, LL b, LL p) {
    LL res = 0;
    while (b > 0) {
        if (b & 1) {
            res = (res + a) % p;   
        }
        a = a * 2 % p;
        b = b >> 1;
    }
    
    res = res % p;
    return res;
}
int main() {
    LL a, b, p;
    cin >> a >> b >> p;
    LL res = large_mul(a, b, p);
    cout << res << endl;
    return 0;
}
