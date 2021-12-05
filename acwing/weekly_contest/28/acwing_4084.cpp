#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 110;
int n;
int a[N];
int d[N];
int f[N];
vector<int> A[N];
vector<int> B[N];

int Find(int x)
{
    if (f[x] != x) f[x] = Find(f[x]);
    return f[x];
}
void merge(int x, int y)
{
    if (x < 1 || x > n) {
        return;
    }
    f[Find(x)] = Find(y);
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        f[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }
    
    for (int i = 1; i <= n; i++) {
        merge(i - d[i], i);
        merge(i + d[i], i);
    }
    
    for (int i = 1; i <= n; i++) {
        A[Find(i)].push_back(i);
        B[Find(i)].push_back(a[i]);
        cout << "i = " << i << " Find(i) = "  << Find(i) << endl;
    }
    for (int i = 1; i <= n; i++) {
        sort(B[i].begin(), B[i].end());
        if (A[i] != B[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}