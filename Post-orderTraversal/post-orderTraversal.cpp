#include <iostream>
#include <stack>
#include <vector>

struct Node{
    int value;
    Node* left;
    Node* right;
    Node(int val) : value(val), left(nullptr), right(nullptr){}
    Node() : value(0), left(nullptr), right(nullptr) {}
    Node(int val, Node *left, Node *right) : value(val), left(left), right(right) {}
};

std::vector<int> postorder(Node* root){
    std::vector<int> result;
    if(root == nullptr){
       return result;
    }
    std::stack<Node*> stack1, stack2;
    stack1.push(root);
    while(!stack1.empty()){
        Node* cur = stack1.top();
        stack1.pop();
        stack2.push(cur);
        if(cur->left != nullptr){
            stack1.push(cur->left);
        }
        if(cur->right != nullptr){
            stack1.push(cur->right);
        }
    }
    while(!stack2.empty()){
        result.push_back(stack2.top()->value);
        stack2.pop();
    }
return result;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(6);
    std::vector<int> order = postorder(root);
    for(int val : order){
        std::cout<< val << " ";
    }
    std::cout<< std::endl;
return 0;
}
