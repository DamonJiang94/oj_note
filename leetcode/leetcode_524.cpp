/*
524. 通过删除字母匹配到字典里最长单词
给你一个字符串 s 和一个字符串数组 dictionary ，找出并返回 dictionary 中最长的字符串，该字符串可以通过删除 s 中的某些字符得到。

如果答案不止一个，返回长度最长且字母序最小的字符串。如果答案不存在，则返回空字符串。

 

示例 1：

输入：s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
输出："apple"
示例 2：

输入：s = "abpcplea", dictionary = ["a","b","c"]
输出："a"
 
*/
class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string res = "";
        for (string str : dictionary) {
            if (IsSub(s, str)) {
                if (res == "" || res.length() < str.length() || (res.length() == str.length() && res > str)) {
                    res = str;
                }
            }
        }
        return res;
    }
    bool IsSub(const string &s1, const string &s2)
    {
        int p1 = 0;
        int p2 = 0;
        while (p1 < s1.length() && p2 < s2.length()) {
            if (s1[p1] == s2[p2]) {
                p1++;
                p2++;
            } else {
                p1++;
            }
        }
        if (p2 == s2.length()) {
            return true;
        } else {
            return false;
        }
    }
};