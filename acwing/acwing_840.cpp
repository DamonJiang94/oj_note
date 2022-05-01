/*
维护一个集合，支持如下几种操作：

I x，插入一个数 x；
Q x，询问数 x 是否在集合中出现过；
现在要进行 N 次操作，对于每个询问操作输出对应的结果。

输入格式
第一行包含整数 N，表示操作数量。

接下来 N 行，每行包含一个操作指令，操作指令为 I x，Q x 中的一种。

输出格式
对于每个询问指令 Q x，输出一个询问结果，如果 x 在集合中出现过，则输出 Yes，否则输出 No。

每个结果占一行。

数据范围
1≤N≤105
−109≤x≤109
输入样例：
5
I 1
I 2
I 3
Q 2
Q 5
输出样例：
Yes
No
*/

#include <iostream>
#include <cstring>

using namespace std;

const int N = 2e5 + 10;
const int null = 0x3f3f3f3f;
int map[N];

int Find(int x)
{
    int k = (x % N + N) % N;
    while (map[k] != x && map[k] != null) {
        k++;
        if (k == N) {
            k = 0;
        }
    }
    return k;
}

void Insert(int x)
{
    int k = Find(x);
    map[k] = x;
}
int main()
{
    int n;
    char q;
    int x;
    cin >> n;
    memset(map, 0x3f, sizeof map);
    for (int i = 0; i < n; ++i) {
        cin >> q >> x;
        if (q == 'I') {
            Insert(x);
        } else {
            int k = Find(x);
            string ans = map[k] == x ? "Yes" : "No";
            cout << ans << endl;
        }
    }
    return 0;
}