namespace Sum_Leaf {

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
    int SumLeaf(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        if (root->left == nullptr && root->right == nullptr) {
            return root->val;
        }
        return SumLeaf(root->left) + SumLeaf(root->right);
    }

};

void Tests() {
    Solution solution;
    {
        TreeNode* root = new TreeNode(1, new TreeNode(2), new TreeNode(3));
        assert(solution.SumLeaf(root) == 5);
    }
    {
        TreeNode* root = new TreeNode(4, new TreeNode(9, new TreeNode(5), new TreeNode(1)), new TreeNode(0));
        assert(solution.SumLeaf(root) == 6);
    }
    {
        TreeNode* root = new TreeNode();
        assert(solution.SumLeaf(root) == 0);
    }
    {
        TreeNode* root = new TreeNode(5, nullptr, new TreeNode(10));
        assert(solution.SumLeaf(root) == 10);
    }
    {
        TreeNode* root = new TreeNode(5, new TreeNode(10), nullptr);
        assert(solution.SumLeaf(root) == 10);
    }
}

}
