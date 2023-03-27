namespace Binary_Tree_Inorder_Traversal {

struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        vector<int> result;
        inorderTraversalDfs(root, result);
        return result;
    }

    void inorderTraversalDfs(TreeNode* node, vector<int>& result) {
        if (node == nullptr) {
            return;
        }
        inorderTraversalDfs(node->left, result);
        result.push_back(node->val);
        inorderTraversalDfs(node->right, result);
    }
};

void Tests() {
    Solution solution;
    {
        TreeNode* root = new TreeNode(1, nullptr, new TreeNode(2, new TreeNode(3), nullptr));
        vector<int> ans = {1, 3, 2};
        assert(solution.inorderTraversal(root) == ans);
    }
    {
        TreeNode* root = nullptr;
        vector<int> ans = {};
        assert(solution.inorderTraversal(root) == ans);
    }
    {
        TreeNode* root = new TreeNode(1);
        vector<int> ans = {1};
        assert(solution.inorderTraversal(root) == ans);
    }

}

}
