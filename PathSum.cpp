namespace Path_Sum {

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
    bool hasPathSum(TreeNode* root, int target_sum) {
        int curr = 0;
        return hasPathSumDps(root, target_sum, curr);
    }

    bool hasPathSumDps(TreeNode* root, int target_sum, int& curr) {
        if (root == nullptr) {
            return false;
        }
        curr += root->val;
        if (target_sum == curr && root->left == nullptr && root->right == nullptr) {
            return true;
        }
        bool left = hasPathSumDps(root->left, target_sum, curr);
        bool right = hasPathSumDps(root->right, target_sum, curr);
        curr -= root->val;
        return left || right;
    }

    void DeleteMemory(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        if (root->left) {
            DeleteMemory(root->left);
        }
        if (root->right) {
            DeleteMemory(root->right);
        }
        delete root;
    }
};

void Tests() {
    Solution solution;
    {
        TreeNode* root = new TreeNode(5,
                         new TreeNode(4,
                         new TreeNode(11,
                         new TreeNode(7, nullptr, nullptr),
                         new TreeNode(2, nullptr, nullptr)), nullptr),
                         new TreeNode(8,
                         new TreeNode(13, nullptr, nullptr),
                         new TreeNode(4, nullptr,
                         new TreeNode(1, nullptr, nullptr))));
        int target = 22;
        assert(solution.hasPathSum(root, target) == true);
        solution.DeleteMemory(root);
    }
    {
        TreeNode* root = new TreeNode(1, new TreeNode(2), new TreeNode(3));
        int target = 5;
        assert(solution.hasPathSum(root, target) == false);
        solution.DeleteMemory(root);
    }
    {
        TreeNode* root = new TreeNode();
        int target = 5;
        assert(solution.hasPathSum(root, target) == false);
        solution.DeleteMemory(root);
    }
    {
        TreeNode* root = new TreeNode(5,
                         new TreeNode(4,
                         new TreeNode(11,
                         new TreeNode(7, nullptr, nullptr),
                         new TreeNode(2, nullptr, nullptr)), nullptr),
                         new TreeNode(8,
                         new TreeNode(13, nullptr, nullptr),
                         new TreeNode(4, nullptr,
                         new TreeNode(1, nullptr, nullptr))));
        int target = 18;
        assert(solution.hasPathSum(root, target) == true);
        solution.DeleteMemory(root);
    }
}
