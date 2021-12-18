/*
399. 除法求值
给你一个变量对数组 equations 和一个实数值数组 values 作为已知条件，其中 equations[i] = [Ai, Bi] 和 values[i] 共同表示等式 Ai / Bi = values[i] 。每个 Ai 或 Bi 是一个表示单个变量的字符串。

另有一些以数组 queries 表示的问题，其中 queries[j] = [Cj, Dj] 表示第 j 个问题，请你根据已知条件找出 Cj / Dj = ? 的结果作为答案。

返回 所有问题的答案 。如果存在某个无法确定的答案，则用 -1.0 替代这个答案。如果问题中出现了给定的已知条件中没有出现的字符串，也需要用 -1.0 替代这个答案。

注意：输入总是有效的。你可以假设除法运算中不会出现除数为 0 的情况，且不存在任何矛盾的结果。

 

示例 1：

输入：equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
输出：[6.00000,0.50000,-1.00000,1.00000,-1.00000]
解释：
条件：a / b = 2.0, b / c = 3.0
问题：a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
结果：[6.0, 0.5, -1.0, 1.0, -1.0 ]
示例 2：

输入：equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
输出：[3.75000,0.40000,5.00000,0.20000]
示例 3：

输入：equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
输出：[0.50000,2.00000,-1.00000,-1.00000]
 

提示：

1 <= equations.length <= 20
equations[i].length == 2
1 <= Ai.length, Bi.length <= 5
values.length == equations.length
0.0 < values[i] <= 20.0
1 <= queries.length <= 20
queries[i].length == 2
1 <= Cj.length, Dj.length <= 5
Ai, Bi, Cj, Dj 由小写英文字母与数字组成
*/
class Solution {
public:
    int Find(int n, vector<int> &p, vector<double> &w)
    {
        if (p[n] != n) {
            int num = Find(p[n], p, w);
            w[n] *= w[p[n]];
            p[n] = num;
        }
        return p[n];
    }
    void Union(int n1, int n2, vector<int> &p, vector<double> &w, double val)
    {
        int p1 = Find(n1, p, w);
        int p2 = Find(n2, p, w);
        if (p1 == p2) return;
        p[p1] = p2;
        w[p1] = w[n2] * val / w[n1];
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        vector<int> p(2 * n, 0);
        vector<double> w(2 * n, 0);
        
        for (int i = 0; i < p.size(); i++) {
            p[i] = i;
            w[i] = 1.0;
        }
        int idx = 0;
        map<string, int> m;
        for (int i = 0; i < n; i++) {
            vector<string> item = equations[i];
            string s1 = item[0];
            string s2 = item[1];
            if (m.find(s1) == m.end()) {
                m[s1] = idx;
                idx++;
            }
            if (m.find(s2) == m.end()) {
                m[s2] = idx;
                idx++;
            }
            Union(m[s1], m[s2], p, w, values[i]);
        }
        vector<double> res;
        for (int i = 0; i < queries.size(); i++) {
            vector<string> item = queries[i];
            string s1 = item[0];
            string s2 = item[1];
            if (m.find(s1) == m.end() || m.find(s2) == m.end()) {
                res.push_back(-1.0);
            } else {
                if (Find(m[s1], p, w) != Find(m[s2], p, w)) {
                    res.push_back(-1.0);
                } else {
                    res.push_back(w[m[s1]] / w[m[s2]]);
                }
            }
        }
        return res;
    }
};