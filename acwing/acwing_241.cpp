/*
在完成了分配任务之后，西部 314 来到了楼兰古城的西部。

相传很久以前这片土地上(比楼兰古城还早)生活着两个部落，一个部落崇拜尖刀(V)，一个部落崇拜铁锹(∧)，他们分别用 V 和 ∧ 的形状来代表各自部落的图腾。

西部 314 在楼兰古城的下面发现了一幅巨大的壁画，壁画上被标记出了 n 个点，经测量发现这 n 个点的水平位置和竖直位置是两两不同的。

西部 314 认为这幅壁画所包含的信息与这 n 个点的相对位置有关，因此不妨设坐标分别为 (1,y1),(2,y2),…,(n,yn)，其中 y1∼yn 是 1 到 n 的一个排列。

西部 314 打算研究这幅壁画中包含着多少个图腾。

如果三个点 (i,yi),(j,yj),(k,yk) 满足 1≤i<j<k≤n 且 yi>yj,yj<yk，则称这三个点构成 V 图腾;

如果三个点 (i,yi),(j,yj),(k,yk) 满足 1≤i<j<k≤n 且 yi<yj,yj>yk，则称这三个点构成 ∧ 图腾;

西部 314 想知道，这 n 个点中两个部落图腾的数目。

因此，你需要编写一个程序来求出 V 的个数和 ∧ 的个数。

输入格式
第一行一个数 n。

第二行是 n 个数，分别代表 y1，y2,…,yn。

输出格式
两个数，中间用空格隔开，依次为 V 的个数和 ∧ 的个数。

数据范围
对于所有数据，n≤200000，且输出答案不会超过 int64。
y1∼yn 是 1 到 n 的一个排列。

输入样例：
5
1 5 3 2 4
输出样例：
3 4
*/
#include <iostream>
#include <vector>

using namespace std;

const int N = 200010;

long long tree_arr_left[N];
long long left_lower_cnt[N];
long long left_higher_cnt[N];
long long tree_arr_right[N];
long long right_lower_cnt[N];
long long right_higher_cnt[N];

int LowBit(int x)
{
    return x & -x;
}

long long Sum(int x, long long arr[])
{
    long long sum = 0;
    while (x >= 1) {
        sum += arr[x];
        x -= LowBit(x);
    }
    return sum;
}

void Add(int x, int y, int n, long long arr[])
{
    while (x <= n) {
        arr[x] += y;
        x += LowBit(x);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> vec;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        vec.push_back(num);
    }
    for (int i = 0; i < n; ++i) {
        int lower = Sum(vec[i] - 1, tree_arr_left);
        int higher = Sum(N, tree_arr_left) - Sum(vec[i], tree_arr_left);
        left_lower_cnt[vec[i]] = lower;
        left_higher_cnt[vec[i]] = higher;
        Add(vec[i], 1, N, tree_arr_left);
    }
    for (int i = n - 1; i >= 0; --i) {
        int lower = Sum(vec[i] - 1, tree_arr_right);
        int higher = Sum(N, tree_arr_right) - Sum(vec[i], tree_arr_right);
        right_lower_cnt[vec[i]] = lower;
        right_higher_cnt[vec[i]] = higher;
        Add(vec[i], 1, N, tree_arr_right);
    }
    
    long long cnt1 = 0;
    long long cnt2 = 0;
    for (int i = 0; i < n; ++i) {
        int num = vec[i];
        if (left_higher_cnt[num] * right_higher_cnt[num] != 0) {
            cnt1 += left_higher_cnt[num] * right_higher_cnt[num];
        }
        if (left_lower_cnt[num] * right_lower_cnt[num] != 0) {
            cnt2 += left_lower_cnt[num] * right_lower_cnt[num];
        }
    }
    cout << cnt1 << " " << cnt2 << endl;
    return 0;
}