/*
4083. 最大公约数

给定一个长度为 n 的整数序列 a1,a2,…,an。

请你从中选出尽可能多的数。

要求满足如下两个条件之一：

仅选择一个数；
选择至少两个数，且所选择的数的最大公约数大于 1；
输出选出数的最大可能数量。

输入格式
第一行包含整数 n。

第二行包含 n 个整数 a1,a2,…,an。

输出格式
一个整数，表示选出数的最大可能数量。

数据范围
前 6 个测试点满足 1≤n≤10。
所有测试点满足 1≤n≤105，1≤ai≤105。

输入样例1：
3
2 3 4
输出样例1：
2
输入样例2：
5
2 3 4 6 7
输出样例2：
3

难度：中等
时/空限制：1s / 256MB

*/
#include <iostream>

using namespace std;

const int N = 100010;
int n;
int num[N];
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        num[x]++;
    }
    int res = 1;
    for (int i = 2; i < N; i++) {
        int tmp = 0;
        for (int j = i; j < N; j += i) {
            tmp += num[j];
        }
        res = max(res, tmp);
    }
    cout << res << endl;
    return 0;
}