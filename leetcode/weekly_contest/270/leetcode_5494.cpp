/*
5944. 从二叉树一个节点到另一个节点每一步的方向
给你一棵 二叉树 的根节点 root ，这棵二叉树总共有 n 个节点。每个节点的值为 1 到 n 中的一个整数，且互不相同。给你一个整数 startValue ，表示起点节点 s 的值，和另一个不同的整数 destValue ，表示终点节点 t 的值。

请找到从节点 s 到节点 t 的 最短路径 ，并以字符串的形式返回每一步的方向。每一步用 大写 字母 'L' ，'R' 和 'U' 分别表示一种方向：

'L' 表示从一个节点前往它的 左孩子 节点。
'R' 表示从一个节点前往它的 右孩子 节点。
'U' 表示从一个节点前往它的 父 节点。
请你返回从 s 到 t 最短路径 每一步的方向。

 

示例 1：



输入：root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
输出："UURL"
解释：最短路径为：3 → 1 → 5 → 2 → 6 。
示例 2：



输入：root = [2,1], startValue = 2, destValue = 1
输出："L"
解释：最短路径为：2 → 1 。
 

提示：

树中节点数目为 n 。
2 <= n <= 105
1 <= Node.val <= n
树中所有节点的值 互不相同 。
1 <= startValue, destValue <= n
startValue != destValue

*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    string res;
    bool Find(TreeNode *node, int value, string &path)
    {
        if (node->val == value) {
            return true;
        }
        if (node->left != nullptr) {
            path += "L";
            if (Find(node->left, value, path)) {
                return true;
            }
            path.resize(path.length() - 1);
        }
        if (node->right != nullptr) {
            path += "R";
            if (Find(node->right, value, path)) {
                return true;
            }
            path.resize(path.length() - 1);
        }
        return false;
    }
    void Dfs(TreeNode* node, int startValue, int destValue)
    {
        
        string start = "";
        string dest = "";
        bool b1 = Find(node, startValue, start);
        bool b2 = Find(node, destValue, dest);
        if (b1 && b2) {
            string newStart = "";
            for (int i = 0; i < start.length(); i++) {
                newStart += "U";
            }
            res = newStart + dest;
        }
    }
    TreeNode* FindMinRoot(TreeNode *node, int startValue, int destValue)
    {
        if (node == nullptr) {
            return nullptr;
        }
        if (node->val == startValue || node->val == destValue) {
            return node;
        }
        TreeNode *left = FindMinRoot(node->left, startValue, destValue);
        TreeNode *right = FindMinRoot(node->right, startValue, destValue);
        if (left != nullptr && right != nullptr) {
            return node;
        }
        if (left == nullptr) {
            return right;
        }
        return left;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* minRoot = FindMinRoot(root, startValue, destValue);
        Dfs(minRoot, startValue, destValue);
        return res;
    }
};