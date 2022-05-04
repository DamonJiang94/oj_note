/*
给定一个 n 个点 m 条边的有向图，图中可能存在重边和自环。

所有边的长度都是 1，点的编号为 1∼n。

请你求出 1 号点到 n 号点的最短距离，如果从 1 号点无法走到 n 号点，输出 −1。

输入格式
第一行包含两个整数 n 和 m。

接下来 m 行，每行包含两个整数 a 和 b，表示存在一条从 a 走到 b 的长度为 1 的边。

输出格式
输出一个整数，表示 1 号点到 n 号点的最短距离。

数据范围
1≤n,m≤105
输入样例：
4 5
1 2
2 3
3 4
1 3
1 4
输出样例：
1
*/

#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector< vector<int> > linked_queue(n + 1, vector<int>());
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        linked_queue[a].push_back(b);
    }
    vector<bool> vis(n + 1, false);
    queue<int> q;
    q.push(1);
    vis[1] = true;
    int dis = -1;
    while (!q.empty()) {
        dis++;
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            int node = q.front();
            q.pop();
            if (node == n) {
                cout << dis << endl;
                return 0;
            }
            for (int j = 0; j < linked_queue[node].size(); ++j) {
                int next_node = linked_queue[node][j];
                if (!vis[next_node]) {
                    vis[next_node] = true;
                    q.push(next_node);
                }
            }
        }
    }
    cout << -1 << endl;
    return 0;
}