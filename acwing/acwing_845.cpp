/*
在一个 3×3 的网格中，1∼8 这 8 个数字和一个 x 恰好不重不漏地分布在这 3×3 的网格中。

例如：

1 2 3
x 4 6
7 5 8
在游戏过程中，可以把 x 与其上、下、左、右四个方向之一的数字交换（如果存在）。

我们的目的是通过交换，使得网格变为如下排列（称为正确排列）：

1 2 3
4 5 6
7 8 x
例如，示例中图形就可以通过让 x 先后与右、下、右三个方向的数字交换成功得到正确排列。

交换过程如下：

1 2 3   1 2 3   1 2 3   1 2 3
x 4 6   4 x 6   4 5 6   4 5 6
7 5 8   7 5 8   7 x 8   7 8 x
现在，给你一个初始网格，请你求出得到正确排列至少需要进行多少次交换。

输入格式
输入占一行，将 3×3 的初始网格描绘出来。

例如，如果初始网格如下所示：

1 2 3 
x 4 6 
7 5 8 
则输入为：1 2 3 x 4 6 7 5 8

输出格式
输出占一行，包含一个整数，表示最少交换次数。

如果不存在解决方案，则输出 −1。

输入样例：
2  3  4  1  5  x  7  6  8
输出样例
19
*/

#include <iostream>
#include <queue>
#include <set>

using namespace std;

int main()
{
    string str;
    for (int i = 0; i < 9; ++i) {
        char ch;
        cin >> ch;
        str += ch;
    }
    queue<string> q;
    set<string> vis;
    int dis = -1;
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    
    q.push(str);
    vis.insert(str);
    string target = "12345678x";
    while (!q.empty()) {
        dis++;
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            string s = q.front();
            q.pop();
            if (s == target) {
                cout << dis << endl;
                return 0;
            }
            int idx = s.find("x");
            int x = idx / 3;
            int y = idx % 3;
            for (int j = 0; j < 4; ++j) {
                int newX = x + dx[j];
                int newY = y + dy[j];
                if (newX >= 0 && newX < 3 && newY >= 0 && newY < 3) {
                    swap(s[idx], s[newX * 3 + newY]);
                    if (vis.count(s) == 0) {
                        vis.insert(s);
                        q.push(s);
                    }
                    swap(s[idx], s[newX * 3 + newY]);
                }
            }
        }
    }
    cout << -1 << endl;
    return 0;
}