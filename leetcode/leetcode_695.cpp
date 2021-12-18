/*
695. 岛屿的最大面积
给你一个大小为 m x n 的二进制矩阵 grid 。

岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在 水平或者竖直的四个方向上 相邻。你可以假设 grid 的四个边缘都被 0（代表水）包围着。

岛屿的面积是岛上值为 1 的单元格的数目。

计算并返回 grid 中最大的岛屿面积。如果没有岛屿，则返回面积为 0 。

 

示例 1：


输入：grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
输出：6
解释：答案不应该是 11 ，因为岛屿只能包含水平或垂直这四个方向上的 1 。
示例 2：

输入：grid = [[0,0,0,0,0,0,0,0]]
输出：0
 

提示：

m == grid.length
n == grid[i].length
1 <= m, n <= 50
grid[i][j] 为 0 或 1
*/
class Solution {
public:
    int Find(int n, vector<int> &p)
    {
        if (p[n] != n) {
            p[n] = Find(p[n], p);
        }
        return p[n];
    }
    void Union(int n1, int n2, vector<int> &p)
    {
        int p1 = Find(n1, p);
        int p2 = Find(n2, p);
        p[p1] = p2;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> p(m * n, 0);
        for (int i = 0; i < p.size(); i++) {
            p[i] = i;
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    if (i + 1 < m && grid[i + 1][j] == 1) {
                        Union(i * n + j, (i + 1) * n + j, p);
                    }
                    if (j + 1 < n && grid[i][j + 1] == 1) {
                        Union(i * n + j, i * n + (j + 1), p);
                    }
                }
            }
        }
        map<int, int> tmp;
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 1) continue;
                int num = Find(i * n + j, p);
                tmp[num]++;
                res = max(res, tmp[num]); 
            }
        }
        return res;
    }
};