/*
n−皇后问题是指将 n 个皇后放在 n×n 的国际象棋棋盘上，使得皇后不能相互攻击到，即任意两个皇后都不能处于同一行、同一列或同一斜线上。

现在给定整数 n，请你输出所有的满足条件的棋子摆法。

输入格式
共一行，包含整数 n。

输出格式
每个解决方案占 n 行，每行输出一个长度为 n 的字符串，用来表示完整的棋盘状态。

其中 . 表示某一个位置的方格状态为空，Q 表示某一个位置的方格上摆着皇后。

每个方案输出完成后，输出一个空行。

注意：行末不能有多余空格。

输出方案的顺序任意，只要不重复且没有遗漏即可。

数据范围
1≤n≤9
输入样例：
4
输出样例：
.Q..
...Q
Q...
..Q.

..Q.
Q...
...Q
.Q..

*/
#include <iostream>
#include <vector>

using namespace std;

void PrintChess(vector<int> &chess)
{
    for (int i = 0; i < chess.size(); ++i) {
        for (int j = 0; j < chess.size(); ++j) {
            if (chess[i] == j) {
                cout << 'Q';
            } else {
                cout << ".";
            }
        }
        cout << endl;
    }
    cout << endl;
}
void DFS(vector<int> &chess, int idx)
{
    if (idx == chess.size()) {
        PrintChess(chess);
        return;
    }
    for (int i = 0; i < chess.size(); ++i) {
        bool flag = true;
        for (int j = 0; j < idx; ++j) {
            if (i == chess[j] || abs(idx - j) == abs(i - chess[j])) {
                flag = false;
                break;
            }
        }
        if (flag) {
            chess[idx] = i;
            DFS(chess, idx + 1);
            chess[idx] = 0;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> chess(n, 0);
    DFS(chess, 0);
    return 0;
}