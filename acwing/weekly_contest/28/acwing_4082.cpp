/*
4082. 子序列

给定一个由大写字母构成的字符串 s，请计算其中有多少个子序列 QAQ。

注意，子序列不需要连续。

提示：本题数据范围较小，可以直接三重循环枚举三个字母的位置。

输入格式
一行，一个由大写字母构成的字符串 s。

输出格式
一个整数，表示 s 中子序列 QAQ 的个数。

数据范围
所有测试点满足 1≤|s|≤100。

输入样例1：
QAQAQYSYIOIWIN
输出样例1：
4
输入样例2：
QAQQQZZYNOIWIN
输出样例2：
3
难度：简单
时/空限制：1s / 256MB
*/
#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'Q') {
            for (int j = i + 1; j < s.length(); j++) {
                if (s[j] == 'A') {
                    for (int k = j + 1; k < s.length(); k++) {
                        if (s[k] == 'Q') {
                            cnt++;
                        }
                    }
                }
            }
        }
    }
    cout << cnt << endl;
    return 0;
}