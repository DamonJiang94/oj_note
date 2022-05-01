/*
给定一个 n×m 的二维整数数组，用来表示一个迷宫，数组中只包含 0 或 1，其中 0 表示可以走的路，1 表示不可通过的墙壁。

最初，有一个人位于左上角 (1,1) 处，已知该人每次可以向上、下、左、右任意一个方向移动一个位置。

请问，该人从左上角移动至右下角 (n,m) 处，至少需要移动多少次。

数据保证 (1,1) 处和 (n,m) 处的数字为 0，且一定至少存在一条通路。

输入格式
第一行包含两个整数 n 和 m。

接下来 n 行，每行包含 m 个整数（0 或 1），表示完整的二维数组迷宫。

输出格式
输出一个整数，表示从左上角移动至右下角的最少移动次数。

数据范围
1≤n,m≤100
输入样例：
5 5
0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0
输出样例：
8
*/

#include <iostream>
#include <queue>

using namespace std;

const int N = 110;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int grid[N][N];
int vis[N][N];

int main()
{
    int n;
    int m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int tmp;
            cin >> tmp;
            grid[i][j] = tmp;
            vis[i][j] = 0;
        }
    }
    queue< pair<int, int> > q;
    q.push(make_pair(1, 1));
    vis[1][1] = 1;
    int dis = -1;
    while (!q.empty()) {
        dis++;
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            auto node = q.front();
            q.pop();
            int x = node.first;
            int y = node.second;
            if (x == n && y == m) {
                cout << dis << endl;
                return 0;
            }
            for (int j = 0; j < 4; ++j) {
                int newX = x + dx[j];
                int newY = y + dy[j];
                if (newX > 0 && newX <= n && newY > 0 && newY <= m && grid[newX][newY] == 0
                    && vis[newX][newY] == 0) {
                        vis[newX][newY] = 1;
                        q.push(make_pair(newX, newY));
                    }
            }
        }
    }
    return 0;
}
