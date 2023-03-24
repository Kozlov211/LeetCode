namespace Smallest_String_Starting_From_Leaf {

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
    string smallestFromLeaf(TreeNode* root) {
        string curr_str;
        string smallest;
        smallestFromLeaf(root, curr_str, smallest);
        return smallest;
    }

    void smallestFromLeaf(TreeNode* node, string& curr_str, string& smallest) {
        curr_str.insert(curr_str.begin(), node->val + 97);
        if (node->left == nullptr && node->right == nullptr) {
            if (smallest.empty() || curr_str < smallest) {
                smallest = curr_str;
            }
            return;
        }
        if (node->left) {
            smallestFromLeaf(node->left, curr_str, smallest);
            curr_str.erase(curr_str.begin());
        }
        if (node->right) {
            smallestFromLeaf(node->right, curr_str, smallest);
            curr_str.erase(curr_str.begin());
        }
    }
};

void Tests() {
    Solution solution;
    {
        TreeNode* root = new TreeNode(0, new TreeNode(1, new TreeNode(3), new TreeNode(4)), new TreeNode(2, new TreeNode(3), new TreeNode(4)));
        assert(solution.smallestFromLeaf(root) == "dba");
    }
    {
        TreeNode* root = new TreeNode(0, new TreeNode(1, new TreeNode(3), new TreeNode(4)), nullptr);
        assert(solution.smallestFromLeaf(root) == "dba");
    }
    {
        TreeNode* root = new TreeNode(0, nullptr, new TreeNode(1, new TreeNode(3), new TreeNode(4)));
        assert(solution.smallestFromLeaf(root) == "dba");
    }
    {
        TreeNode* root = new TreeNode(25, new TreeNode(1, new TreeNode(1), new TreeNode(3)), new TreeNode(3, new TreeNode(0), new TreeNode(2)));
        assert(solution.smallestFromLeaf(root) == "adz");
    }

}
}
