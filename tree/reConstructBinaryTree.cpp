#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
// 给出前序中序，构建二叉树
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        int vlen = vin.size();
        if(vlen == 0) 
            return NULL;
        vector<int> vin_left, vin_right, pre_left, pre_right;   //分别存放前序遍历和中序遍历的左右子树
        TreeNode* head = new TreeNode(pre[0]);       //创建根节点，为根节点分配空间
        int gen = 0;
        for(int i = 0; i < vlen; i++){
            if(pre[0] == vin[i]){
                gen = i;           //找到中序遍历中的根节点（前序遍历的第一个）
                break;
            }
        }
        
        for (int i = 0; i < gen; i++)           //用于递归的左子树
        {
            pre_left.push_back(pre[i+1]);       //前序遍历的[1,gen]  (第一个是根节点)
            vin_left.push_back(vin[i]);         //中序遍历的[0,gen-1]
        }
        for (int i = gen+1; i < vlen; i++)      //用于递归的右子树
        {
            pre_right.push_back(pre[i]);        //前序遍历的[gen+1,len-1]  
            vin_right.push_back(vin[i]);        //中序遍历的[gen+1,len-1]
        }
        head->left = reConstructBinaryTree(pre_left,vin_left);     //递归
        head->right = reConstructBinaryTree(pre_right,vin_right);
        head->val = pre[0];
        return head;
    }
};

int main(int argc, char const *argv[])
{
    class Solution solu;
    vector<int> pre = {1,2,4,7,3,5,6,8};
    vector<int> vin = {4,7,2,1,5,3,8,6};
    TreeNode* t =  solu.reConstructBinaryTree(pre, vin);
    return 0;
}

