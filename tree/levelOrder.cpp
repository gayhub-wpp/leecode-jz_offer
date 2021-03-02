/*
 * 给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。
 * 示例：
 * 二叉树：[3,9,20,null,null,15,7],
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 返回其层序遍历结果：
 * 
 * [
 * ⁠ [3],
 * ⁠ [9,20],
 * ⁠ [15,7]
 * ]
 * 
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// @lc code=start
/**
 * Definition for a binary tree node.*/
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
//  层序遍历
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;     //每层为一个vector
        if (!root)
            return res;
        queue<TreeNode*> tmp;         //记录每层的节点
        tmp.push(root);
        while (tmp.size())            //每层循环
        {
            vector<int> vec;          //记录每层节点的val
            int len = tmp.size();
            for (int  i = 0; i < len; i++)
            {
                TreeNode* node = tmp.front();   //当前层的第一个节点的数值放入当前层记录val的vector，然后删除
                vec.push_back(node->val);       
                tmp.pop(); 
                if (node->left)                 //把其子节点按顺序加入tmp，以供下一层的循环
                {
                    tmp.push(node->left);
                }
                if (node->right)
                {
                    tmp.push(node->right);
                }
            }
            res.push_back(vec);
        }
        return res;
        
    }
};

int main(int argc, char const *argv[])
{
    TreeNode* a = new TreeNode(1); //      a
    TreeNode* b = new TreeNode(2); /*     / \      */
    TreeNode* c = new TreeNode(3); //    b   c    
    a->left = b;
    a->right = c;
    Solution solu;
    vector<vector<int>> vec = solu.levelOrder(a); 
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            cout<< vec[i][j] << " ";
        }
    }
    cout << endl;
    
    return 0;
}