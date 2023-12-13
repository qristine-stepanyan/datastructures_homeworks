#include <iostream>
#include <vector>
#include <queue>

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
};

std::vector<std::vector<int>> zigzag(TreeNode* root){
    std::vector<std::vector<int>> result;
    if(root == nullptr){
    return result;
    }
    std::queue<TreeNode*> nodesQueue;
    nodesQueue.push(root);
    bool leftToRight = true;
    while(!nodesQueue.empty()){
        int levelSize = nodesQueue.size();
        std::vector<int> currentLevel(levelSize);
        for(int i = 0; i < levelSize; ++i){
            int index = leftToRight ? i : levelSize - 1 - i;
            TreeNode* node = nodesQueue.front();
            nodesQueue.pop();
            currentLevel[index] = node->val;
            if(node->left) nodesQueue.push(node->left);
            if(node->right) nodesQueue.push(node->right);
        }
        result.push_back(currentLevel);
        leftToRight = !leftToRight;
    }
return result;
}

TreeNode* createTree(const std::vector<int>& nodes, int index){
    TreeNode* root = nullptr;
    if(index < nodes.size() && nodes[index] != -1){
        root = new TreeNode(nodes[index]);
        root->left = createTree(nodes, 2 * index + 1);
        root->right = createTree(nodes, 2 * index + 2);
    }
    return root;
}

int main(){
    std::vector<int> nodes1 = {3, 9, 20, -1, -1, 15, 7};
    TreeNode* root1 = createTree(nodes1, 0);
    std::vector<std::vector<int>> result1 = zigzag(root1);
    std::cout << "Output 1 " << std::endl;
    for(const auto& level : result1){
        std::cout << "[";
        for(int val : level){
            std::cout << val << " ";
        }
        std::cout << "]" << std::endl;
    }
    std::vector<int> nodes2 = {1};
    TreeNode* root2 = createTree(nodes2, 0);
    std::vector<std::vector<int>> result2 = zigzag(root2);
    std::cout << "Output 2 " << std::endl;
    for(const auto& level : result2){
        std::cout << "[";
        for(int val : level){
            std::cout << val << " ";
        }
        std::cout << "]" << std::endl;
    }
    std::vector<int> nodes3 = {};
    TreeNode* root3 = createTree(nodes3, 0);
    std::vector<std::vector<int>> result3 = zigzag(root3);
    std::cout << "Output 3 " << std::endl;
    for(const auto& level : result3){
        std::cout << "[";
        for(int val : level){
            std::cout << val << " ";
        }
        std::cout << "]" << std::endl;
    }
    std::cout<< std::endl;
return 0;
}
