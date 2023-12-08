#include <iostream>

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool hasPathSum(TreeNode* root, int targetSum){
    if(root == nullptr){
        return false;
    }
    targetSum -= root->val;
    if(root->left == nullptr && root->right == nullptr){ 
        return targetSum == 0;
    }
    return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
}

int main() {
    TreeNode* root = new TreeNode(5);
    root -> left = new TreeNode(4);
    root -> right = new TreeNode(8);
    root -> left -> left = new TreeNode(11);
    root -> left -> left ->left = new TreeNode(7);
    root -> left -> left -> right = new TreeNode(2);
    root -> right -> left = new TreeNode(13);
    root -> right -> right = new TreeNode(4);
    root -> right -> right -> right = new TreeNode(1);
    int targetSum = 22;
    std::cout<< hasPathSum(root, targetSum) << std::endl; 
    
return 0;
}
