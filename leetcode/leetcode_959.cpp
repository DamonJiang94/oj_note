/*
959. 由斜杠划分区域
在由 1 x 1 方格组成的 N x N 网格 grid 中，每个 1 x 1 方块由 /、\ 或空格构成。这些字符会将方块划分为一些共边的区域。

（请注意，反斜杠字符是转义的，因此 \ 用 "\\" 表示。）。

返回区域的数目。

 

示例 1：

输入：
[
  " /",
  "/ "
]
输出：2
解释：2x2 网格如下：

示例 2：

输入：
[
  " /",
  "  "
]
输出：1
解释：2x2 网格如下：

示例 3：

输入：
[
  "\\/",
  "/\\"
]
输出：4
解释：（回想一下，因为 \ 字符是转义的，所以 "\\/" 表示 \/，而 "/\\" 表示 /\。）
2x2 网格如下：

示例 4：

输入：
[
  "/\\",
  "\\/"
]
输出：5
解释：（回想一下，因为 \ 字符是转义的，所以 "/\\" 表示 /\，而 "\\/" 表示 \/。）
2x2 网格如下：

示例 5：

输入：
[
  "//",
  "/ "
]
输出：3
解释：2x2 网格如下：

 

提示：

1 <= grid.length == grid[0].length <= 30
grid[i][j] 是 '/'、'\'、或 ' '。
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
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<int> p(4 * n * n, 0);
        for (int i = 0; i < p.size(); i++) {
            p[i] = i;
        }
        for (int i = 0; i < n; i++) {
           string s = grid[i];
           int idx = 0;
           int cnt = 0;
           while (idx < s.length()) {
               int n0 = i * 4 * n + cnt;
               int n1 = i * 4 * n + cnt + 1;
               int n2 = i * 4 * n + cnt + 2;
               int n3 = i * 4 * n + cnt + 3;
               if (s[idx] == '\\') {
                   Union(n1, n2, p);
                   Union(n0, n3, p);
               } else if (s[idx] == ' ') {
                   Union(n0, n1, p);
                   Union(n1, n2, p);
                   Union(n2, n3, p);
               } else {
                    Union(n0, n1, p);
                    Union(n2, n3, p);
                }
                idx++;
                if (idx < s.length()) {
                    int nextN0 = i * 4 * n + cnt + 4;
                    Union(n2, nextN0, p);
                }
                if (i + 1 < n) {
                    int botN1 = (i + 1) * 4 * n + cnt + 1;
                    Union(n3, botN1, p);
                }
               cnt += 4;
           }
        }
        set<int> s;
        for (int i = 0; i < p.size(); i++) {
            s.insert(Find(i, p));
        }
        return s.size();
    }
};