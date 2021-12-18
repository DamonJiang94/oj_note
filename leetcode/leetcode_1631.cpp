/*
1631. 最小体力消耗路径
你准备参加一场远足活动。给你一个二维 rows x columns 的地图 heights ，其中 heights[row][col] 表示格子 (row, col) 的高度。一开始你在最左上角的格子 (0, 0) ，且你希望去最右下角的格子 (rows-1, columns-1) （注意下标从 0 开始编号）。你每次可以往 上，下，左，右 四个方向之一移动，你想要找到耗费 体力 最小的一条路径。

一条路径耗费的 体力值 是路径上相邻格子之间 高度差绝对值 的 最大值 决定的。

请你返回从左上角走到右下角的最小 体力消耗值 。

 

示例 1：



输入：heights = [[1,2,2],[3,8,2],[5,3,5]]
输出：2
解释：路径 [1,3,5,3,5] 连续格子的差值绝对值最大为 2 。
这条路径比路径 [1,2,2,2,5] 更优，因为另一条路径差值最大值为 3 。
示例 2：



输入：heights = [[1,2,3],[3,8,4],[5,3,5]]
输出：1
解释：路径 [1,2,3,4,5] 的相邻格子差值绝对值最大为 1 ，比路径 [1,3,5,3,5] 更优。
示例 3：


输入：heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
输出：0
解释：上图所示路径不需要消耗任何体力。
 

提示：

rows == heights.length
columns == heights[i].length
1 <= rows, columns <= 100
1 <= heights[i][j] <= 106
*/
class Solution {
public:
    bool IsValid(int row, int col, vector<vector<int>> &heights)
    {
        if (row < 0 || row >= heights.size() || col < 0 || col >= heights[0].size()) {
            return false;
        }
        return true;
    }
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
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};
        vector<tuple<int, int, int>> vec;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < 4; k++) {
                    int newX = i + dx[k];
                    int newY = j + dy[k];
                    if (IsValid(newX, newY, heights)) {
                        int n1 = i * m + j;
                        int n2 = newX * m + newY;
                        vec.push_back({abs(heights[i][j] - heights[newX][newY]), n1, n2});
                    }
                }
            }
        }
        sort(vec.begin(), vec.end(), [](const auto &t1, const auto &t2) {
            return get<0>(t1) < get<0>(t2);
        });
        vector<int> p(n * m, 0);
        for (int i = 0; i < p.size(); i++) {
            p[i] = i;
        }
        int start = 0;
        int end = m * n - 1;
        int res = 0;
        for (auto item : vec) {
            int cost = get<0>(item);
            int point1 = get<1>(item);
            int point2 = get<2>(item);
            Union(point1, point2, p);
            if (Find(start, p) == Find(end, p)) {
                res = cost;
                break;
            }
        }
        return res;
    }
};