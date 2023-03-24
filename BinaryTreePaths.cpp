class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        string curr_path;
        binaryTreePaths(root, paths, curr_path);
        return paths;
    }

    void binaryTreePaths(TreeNode* node, vector<string>& paths, string curr_path) {
        curr_path += to_string(node->val);
        if (node->left == nullptr && node->right == nullptr) {
            paths.push_back(curr_path);
            return;
        }
        if (node->left) {
            binaryTreePaths(node->left, paths, curr_path + "->");
        }
        if (node->right) {
            binaryTreePaths(node->right, paths, curr_path + "->");
        }
    }
};

void Tests() {
    Solution solution;
    {
        TreeNode* root = new TreeNode(1);
        assert(solution.binaryTreePaths(root) == vector<string>{"1"});
    }
    {
        TreeNode* root = new TreeNode(1, new TreeNode(2, nullptr, new TreeNode(5)), new TreeNode(3));
        vector<string> result = {"1->2->5", "1->3"};
        assert(solution.binaryTreePaths(root) == result);
    }
    {
        TreeNode* root = new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(5)), nullptr);
        vector<string> result = {"1->2->3", "1->2->5"};
        assert(solution.binaryTreePaths(root) == result);
    }
    {
        TreeNode* root = new TreeNode(1, nullptr, new TreeNode(2, new TreeNode(3), new TreeNode(5)));
        vector<string> result = {"1->2->3", "1->2->5"};
        assert(solution.binaryTreePaths(root) == result);
    }
    {
        TreeNode* root = new TreeNode(-1, nullptr, new TreeNode(-2, new TreeNode(-3), new TreeNode(-5)));
        vector<string> result = {"-1->-2->-3", "-1->-2->-5"};
        assert(solution.binaryTreePaths(root) == result);
    }
}


