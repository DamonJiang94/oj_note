/*
给定一颗树，树中包含 n 个结点（编号 1∼n）和 n−1 条无向边。

请你找到树的重心，并输出将重心删除后，剩余各个连通块中点数的最大值。

重心定义：重心是指树中的一个结点，如果将这个点删除后，剩余各个连通块中点数的最大值最小，那么这个节点被称为树的重心。

输入格式
第一行包含整数 n，表示树的结点数。

接下来 n−1 行，每行包含两个整数 a 和 b，表示点 a 和点 b 之间存在一条边。

输出格式
输出一个整数 m，表示将重心删除后，剩余各个连通块中点数的最大值。

数据范围
1≤n≤105
输入样例
9
1 2
1 7
1 4
2 8
2 5
4 3
3 9
4 6
输出样例：
4
*/
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int N = 100010;
int cnt[N]; // 记录以i为root节点时，子数的节点总数
bool vis[N]; 
int min_value = INT_MAX;

void Dfs(int idx, vector< vector<int> > &linked_queue)
{
    vis[idx] = true;
    int sum = 1;
    int max_value = INT_MIN;
    for (int i = 0; i < linked_queue[idx].size(); ++i) {
        int num = linked_queue[idx][i];
        if (!vis[num]) {
            Dfs(num, linked_queue);
            sum += cnt[num];
            max_value = max(max_value, cnt[num]);
        }
    }
    max_value = max(max_value, (int)linked_queue.size() - 1 - sum);
    min_value = min(min_value, max_value);
    cnt[idx] = sum;
}

int main()
{
    int n;
    cin >> n;
    vector< vector<int> > linked_queue(n + 1, vector<int>());
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        linked_queue[a].push_back(b);
        linked_queue[b].push_back(a);
    }
    Dfs(1, linked_queue);
    cout << min_value << endl;
    return 0;
}