namespace Sum_Root_to_Leaf_Numbers {

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
    int sumNumbers(TreeNode* root) {
        string curr_sum;
        return sumNumbersDps(root, curr_sum);
    }

    int sumNumbersDps(TreeNode* root, string& curr_sum) {
        if (root == nullptr) {
            return 0;
        }
        curr_sum += to_string(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            return stoi(curr_sum);
        }
        int left_sum = sumNumbersDps(root->left, curr_sum);
        if (left_sum != 0) {
            curr_sum.pop_back();
        }
        int right_sum = sumNumbersDps(root->right, curr_sum);
        if (right_sum != 0) {
            curr_sum.pop_back();
        }
        return left_sum + right_sum;
    }
};

void Tests() {
    Solution solution;
    {
        TreeNode* root = new TreeNode(1, new TreeNode(2), new TreeNode(3));
        assert(solution.sumNumbers(root) == 25);
    }
    {
        TreeNode* root = new TreeNode(4, new TreeNode(9, new TreeNode(5), new TreeNode(1)), new TreeNode(0));
        assert(solution.sumNumbers(root) == 1026);
    }
    {
        TreeNode* root = new TreeNode();
        assert(solution.sumNumbers(root) == 0);
    }
    {
        TreeNode* root = new TreeNode(1, nullptr, new TreeNode(5));
        assert(solution.sumNumbers(root) == 15);
    }
}
