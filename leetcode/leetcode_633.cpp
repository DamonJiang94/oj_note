/*
633. 平方数之和
给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a2 + b2 = c 。

 

示例 1：

输入：c = 5
输出：true
解释：1 * 1 + 2 * 2 = 5
示例 2：

输入：c = 3
输出：false
*/
class Solution {
public:
    bool judgeSquareSum(int c) {
        if (c == 1 || c == 2) return true;
        long long l = 0;
        long long r = sqrt(c);
        while (l <= r) {
            if (l * l == c - r * r) {
                return true;
            } else if (l * l < c - r * r) {
                l++;
            } else {
                r--;
            }
        }
        return false;
    }
};