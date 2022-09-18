namespace Convert_BST_to_Greater_Tree {

//*
// * Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    int32_t sum = 0;

public:
    TreeNode* convertBST(TreeNode* root) {
        if (root) {
            convertBST(root->right);
            sum += root->val;
            root->val = sum;
            convertBST(root->left);
        }
        return root;
    }

    void MemoryClearing(TreeNode* root) {
        if (root){
            stack<TreeNode*> parents;
            parents.push(root);
            while (!parents.empty()) {
                if (parents.top()->left) {
                    parents.push(parents.top()->left);
                } else if (parents.top()->right) {
                    parents.push(parents.top()->right);
                } else {
                    TreeNode* tmp = parents.top();
                    parents.pop();
                    if (parents.empty()) {
                        delete tmp;
                    } else if (parents.top()->left && parents.top()->left->val == tmp->val) {
                        parents.top()->left = nullptr;
                        delete tmp;
                    } else {
                        parents.top()->right = nullptr;
                        delete tmp;
                    }

                }
            }
        }
    }

};

void Tests() {
    Solution solution;
    {
        TreeNode* root = new TreeNode{4, new TreeNode{1, new TreeNode{0, nullptr, nullptr}, new TreeNode{2, nullptr, new TreeNode{3, nullptr, nullptr}}},
                new TreeNode{6, new TreeNode{5, nullptr, nullptr}, new TreeNode{7, nullptr, new TreeNode{8, nullptr, nullptr}}}};
        TreeNode* new_root = solution.convertBST(root);
        solution.MemoryClearing(root);
    }
}

}

