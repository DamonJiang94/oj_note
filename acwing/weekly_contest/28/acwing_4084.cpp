/*
4084. 号码牌

有 n 个小朋友，编号 1∼n。

每个小朋友都拿着一个号码牌，初始时，每个小朋友拿的号码牌上的号码都等于其编号。

每个小朋友都有一个幸运数字，第 i 个小朋友的幸运数字为 di。

对于第 i 个小朋友，他可以向第 j 个小朋友发起交换号码牌的请求，当且仅当 |i−j|=di 成立。

注意，请求一旦发出，对方无法拒绝，只能立刻进行交换。

每个小朋友都可以在任意时刻发起任意多次交换请求。

给定一个 1∼n 的排列 a1,a2,…,an。

请问，通过小朋友相互之间交换号码牌，能否使得第 i 个小朋友拿的号码牌上的号码恰好为 ai，对 i∈[1,n] 均成立。

输入格式
第一行包含整数 n。

第二行包含 n 个整数 a1,a2,…,an。

第三行包含 n 个整数 d1,d2,…,dn。

输出格式
共一行，如果能做到，则输出 YES，否则输出 NO。

数据范围
前 6 个测试点满足 1≤n≤10。
所有测试点满足 1≤n≤100，1≤di≤n，保证 a1∼an 是一个 1∼n 的排列。

输入样例1：
5
5 4 3 2 1
1 1 1 1 1
输出样例1：
YES
输入样例2：
7
4 3 5 1 2 7 6
4 6 6 1 6 6 1
输出样例2：
NO
输入样例3：
7
4 2 5 1 3 7 6
4 6 6 1 6 6 1
输出样例3：
YES

难度：困难
时/空限制：1s / 256MB

*/

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
    // 路径压缩
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
        // cout << "i = " << i << " Find(i) = "  << Find(i) << endl;
    }
    for (int i = 1; i <= n; i++) {
        sort(B[i].begin(), B[i].end());
        // for (int j = 0; j < A[i].size(); j++) {
        //     cout << "A[" << i << "][" << j << "] = " << A[i][j] << " "; 
        // }
        // cout << endl;
        // for (int j = 0; j < B[i].size(); j++) {
        //     cout << "B[" << i << "][" << j << "] = " << B[i][j] << " "; 
        // }
        // cout << endl;
        if (A[i] != B[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}