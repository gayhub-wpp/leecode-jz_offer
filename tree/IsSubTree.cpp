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
// 输入两棵二叉树1，2，判断2是不是1的子结构。（ps：我们约定空树不是任意一个树的子结构）
	bool recur(TreeNode* pRoot1, TreeNode* pRoot2){     //判断2是不是和1有相同的结构，（同一个根节点，但是子节点不一定相同）
		if (!pRoot2)                                    //2递归完了则说明相同
			return true;
		if (!pRoot1)                                    //1递归完了2还没递归完说明不相同
			return false;
		//递归1的左右子树与2是否有相同的结构
		return ((pRoot1->val == pRoot2->val)  && recur(pRoot1->right, pRoot2->right)) && recur(pRoot1->left, pRoot2->left);  
	}
	//遍历树1的每个节点，判断2与当前节点是否具有相同结构
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
		if (!pRoot1 || !pRoot2)    //有一个为空肯定不相同
			return false;
		if (recur(pRoot1, pRoot2))   
			return true;
		return HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);     //返回bool类型的题目善用||和&&会更加精简
		//上面三行可以写为
		//return recur(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2); 
    }
};

int main(int argc, char const *argv[])
{
    TreeNode* a = new TreeNode(1); //      1
    TreeNode* b = new TreeNode(2); /*     / \      */
    TreeNode* c = new TreeNode(3); //    2   3    
    a->left = b;
    a->right = c;
	TreeNode* d = new TreeNode(1); //     1
    TreeNode* e = new TreeNode(2); //    / 
	d->left = e;                   //   2
    Solution solu;
    
    cout << solu.HasSubtree(a, d) << endl;
    
    return 0;
}