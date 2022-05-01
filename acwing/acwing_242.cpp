/*
给定长度为 N 的数列 A，然后输入 M 行操作指令。

第一类指令形如 C l r d，表示把数列中第 l∼r 个数都加 d。

第二类指令形如 Q x，表示询问数列中第 x 个数的值。

对于每个询问，输出一个整数表示答案。

输入格式
第一行包含两个整数 N 和 M。

第二行包含 N 个整数 A[i]。

接下来 M 行表示 M 条指令，每条指令的格式如题目描述所示。

输出格式
对于每个询问，输出一个整数表示答案。

每个答案占一行。

数据范围
1≤N,M≤105,
|d|≤10000,
|A[i]|≤109
输入样例：
10 5
1 2 3 4 5 6 7 8 9 10
Q 4
Q 1
Q 2
C 1 6 3
Q 2
输出样例：
4
1
2
5
*/
#include <iostream>
#include <vector>

using namespace std;

const int N = 110;

int a[N];
int b[N];
int arr_tree[N];

int LowerBit(int x)
{
    return x & -x;
}

int Sum(int x)
{
    int sum = 0;
    while (x >= 1) {
        sum += arr_tree[x];
        x -= LowerBit(x);
    }
    return sum;
}

void Add(int x, int y)
{
    while (x < N) {
        arr_tree[x] += y;
        x += LowerBit(x);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        b[i] = a[i] - a[i - 1];
    }
    for (int i = 1; i <= n; ++i) {
        Add(i, b[i]);
    }

    for (int i = 0; i < m; ++i) {
        char ch;
        cin >> ch;
        if (ch == 'Q') {
            int x;
            cin >> x;
            int res = Sum(x);
            cout << res << endl;
        } else {
            int l, r, d;
            cin >> l >> r >> d;
            Add(l, d);
            Add(r + 1, -d);
        }
    }
    return 0;
}