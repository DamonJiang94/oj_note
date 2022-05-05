/*
给定一个 n 个点 m 条边的有向图，点的编号是 1 到 n，图中可能存在重边和自环。

请输出任意一个该有向图的拓扑序列，如果拓扑序列不存在，则输出 −1。

若一个由图中所有点构成的序列 A 满足：对于图中的每条边 (x,y)，x 在 A 中都出现在 y 之前，则称 A 是该图的一个拓扑序列。

输入格式
第一行包含两个整数 n 和 m。

接下来 m 行，每行包含两个整数 x 和 y，表示存在一条从点 x 到点 y 的有向边 (x,y)。

输出格式
共一行，如果存在拓扑序列，则输出任意一个合法的拓扑序列即可。

否则输出 −1。

数据范围
1≤n,m≤105
输入样例：
3 3
1 2
2 3
1 3
输出样例：
1 2 3
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector< vector<int> > linked_queue(n + 1, vector<int>());
    vector<int> in_degree(n + 1, 0);
    vector<int> ans;

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        in_degree[b]++;
        linked_queue[a].push_back(b);
    }
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for (int i = 0; i < linked_queue[node].size(); ++i) {
            int next_node = linked_queue[node][i];
            in_degree[next_node]--;
            if (in_degree[next_node] == 0) {
                q.push(next_node);
            }
        }
    }
    if (ans.size() == n) {
        for (int i = 0; i < ans.size(); ++i) {
            cout << ans[i] << " ";
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}