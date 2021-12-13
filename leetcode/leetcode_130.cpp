/*
130. 被围绕的区域
给你一个 m x n 的矩阵 board ，由若干字符 'X' 和 'O' ，找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。
 

示例 1：


输入：board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
输出：[["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
解释：被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。
示例 2：

输入：board = [["X"]]
输出：[["X"]]
 

提示：

m == board.length
n == board[i].length
1 <= m, n <= 200
board[i][j] 为 'X' 或 'O'
*/
class Solution {
public:
    bool isValid(vector<vector<char>> &board, vector<vector<bool>> &vis, int row, int col)
    {
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() ||
            board[row][col] == 'X' || vis[row][col]) {
            return false;
        }
        return true;
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[i][j]) continue;
                vis[i][j] = true;
                if (board[i][j] == 'X') continue;
                set<pair<int, int>> s;
                queue<pair<int, int>> q;
                bool reverse = true;
                q.push({i, j});
                s.insert({i, j});
                while (!q.empty()) {
                    auto item = q.front();
                    q.pop();
                    if (item.first == 0 || item.first == m - 1 || item.second == 0 || item.second == n - 1) {
                        reverse = false;
                    }       
                    for (int k = 0; k < 4; k++) {
                        int newX = item.first + dx[k];
                        int newY = item.second + dy[k];
                        // cout << newX << " " << newY << endl;
                        if (isValid(board, vis, newX, newY)) {
                            vis[newX][newY] = true;
                            q.push({newX, newY});
                            s.insert({newX, newY});
                           // cout << newX << " " << newY << endl;
                            
                        }
                    }
                }
                if (reverse) {
                    for (auto item : s) {
                        board[item.first][item.second] = 'X';
                    }
                }
            }
        }
    }
};