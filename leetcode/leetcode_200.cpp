/*
200. 岛屿数量
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。

此外，你可以假设该网格的四条边均被水包围。

 

示例 1：

输入：grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
输出：1
示例 2：

输入：grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
输出：3
 

提示：

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] 的值为 '0' 或 '1'
*/
class Solution {
public:
    int Find(int num, vector<int> &p)
    {
        if (p[num] != num) {
            p[num] = Find(p[num], p);
        }
        return p[num];
    }
    void Merge(int n1, int n2, vector<int> &p)
    {
        int p1 = Find(n1, p);
        int p2 = Find(n2, p);
        // cout << p1 << " " << p2 << endl;
        p[p1] = p2;    
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> p(n * m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                p[i * m + j] = i * m + j; 
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int num = i * m + j;
                if (grid[i][j] == '1') {
                    if (i + 1 < n && grid[i + 1][j] == '1') {
                        Merge(num, (i + 1) * m + j, p);
                    }
                    if (j + 1 < m && grid[i][j + 1] == '1') {
                        Merge(num, i * m + (j + 1), p);
                    }
                }
            }
        }
        set<int> s;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    // cout << Find(i * m + j, p) << endl;
                    s.insert(Find(i * m + j, p));
                }  
            }
        }
        return s.size();
    }
};