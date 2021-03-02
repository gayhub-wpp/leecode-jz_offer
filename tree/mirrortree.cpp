#include <iostream>
#include <vector>
#include <queue>
using namespace std;

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
//  操作给定的二叉树，将其变换为源二叉树的镜像。
    TreeNode* Mirror(TreeNode* pRoot) {
            if (pRoot == nullptr)
            {
                return nullptr;
            }
            TreeNode* tmp = Mirror(pRoot->left);   //递归
            pRoot->left = Mirror(pRoot->right);
            pRoot->right = tmp;
            return pRoot;
        }

    // 层序遍历
    vector<int> levelOrder(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        queue<TreeNode*> qu;
        qu.push(root);
        while(!qu.empty())
        {
            // vector<int> tmp;
            int len=qu.size();
            for(int i=0;i<len;i++){
                TreeNode* node=qu.front();
                qu.pop();
                res.push_back(node->val);
                if(node->left) qu.push(node->left);
                if(node->right) qu.push(node->right);
            }
        // res.push_back(tmp);
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
    vector<int> vec = solu.levelOrder(solu.Mirror(a)); 
    for (int i = 0; i < vec.size(); i++)
    {
        cout<< vec[i] << " ";
    }
    cout << endl;
    
    return 0;
}
