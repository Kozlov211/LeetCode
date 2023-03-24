#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <stack>
#include <set>
#include <unordered_set>

using namespace std;


///Solution26. Remove Duplicates from Sorted Array
class Solution26 {
public:
    int removeDuplicates(vector<int>& nums) {
        int result = 1;
        int tmp = nums[0];
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] != tmp) {
                tmp = nums[i];
                nums[result++] = tmp;

            }
        }
        return result;
    }
};

///Solution80. Remove Duplicates from Sorted Array II
class Solution80 {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 2;
        for (size_t i = 2; i < nums.size(); ++i) {
            if (nums[i] != nums[index - 1] || nums[i] != nums[index - 2]) {
                nums[index++] = nums[i];
            }
        }
        return nums.size() == 1 ? 1 : index;
    }
};

///4. Median of Two Sorted Arrays
class Solution4 {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result (nums1.size() + nums2.size());
        size_t point1 = 0;
        size_t point2 = 0;
        size_t point = 0;
        while (point1 != nums1.size() && point2 != nums2.size()) {
            if (nums1[point1] > nums2[point2]) {
                result[point++] = nums2[point2++];
            } else {
                result[point++] = nums1[point1++];
            }
        }
        while (point1 != nums1.size()) {
            result[point++] = nums1[point1++];
        }
        while (point2 != nums2.size()) {
            result[point++] = nums2[point2++];
        }
        return result.size() % 2 == 0 ? (result[point / 2] + result[(point - 1) / 2]) / 2. : result[point / 2];
    }
};


///11. Container With Most Water
class Solution11 {
public:
    int maxArea(vector<int>& height) {
        int range_begin = 0;
        int range_end = height.size() - 1;
        int ans = 0;
        int tmp = 0;
        while (range_begin < range_end) {
           if (height[range_begin] <= height[range_end]) {
               tmp = height[range_begin] * (range_end - range_begin);
               ++range_begin;
           } else {
               tmp = height[range_end] * (range_end - range_begin);
               --range_end;
           }
           ans = tmp > ans ? tmp : ans;
        }
        return ans;
    }
};

namespace Largest_Number_At_Least_Twice_of_Others {

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int first_max = *nums.begin();
        int second_max = *(nums.begin() + 1);
        size_t first_max_index = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] > first_max) {
                second_max = first_max;
                first_max = nums[i];
                first_max_index = i;
            } else if (nums[i] > second_max && nums[i] != first_max) {
                second_max = nums[i];
            }
        }
        return first_max >= second_max * 2 ? first_max_index : -1;

    }
};

void Tests() {
    Solution solution;
    {
        vector<int> nums = {3,6,1,0};
        assert(solution.dominantIndex(nums) == 1);
    }
    {
        vector<int> nums = {1,2,3,4};
        assert(solution.dominantIndex(nums) == -1);
    }
    {
        vector<int> nums = {1,4};
        assert(solution.dominantIndex(nums) == 1);
    }
    {
        vector<int> nums = {4,1};
        assert(solution.dominantIndex(nums) == 0);
    }
    {
        vector<int> nums = {4,4};
        assert(solution.dominantIndex(nums) == -1);
    }
}

}


namespace Largest_Number_After_Digit_Swaps_by_Parity {

class Solution {
public:
    int largestInteger(int num) {
        string num_as_string = to_string(num);
        string odd, even;
        for (auto num : num_as_string) {
            if ((int)(num) % 2 == 0) {
                even += num;
            } else {
                odd += num;
            }
        }
        sort(odd.begin(), odd.end(), [](auto lhs, auto rhs) {
            return lhs > rhs;
        });
        sort(even.begin(), even.end(), [](auto lhs, auto rhs) {
            return lhs > rhs;
        });
        for (size_t i = 0, even_i = 0, odd_i = 0; i < num_as_string.size(); ++i) {
            num_as_string[i] = (int)(num_as_string[i]) % 2 == 0 ? even[even_i++] : odd[odd_i++];
        }
        return stoi(num_as_string);
    }
};


void Tests() {
    Solution solution;
    {
        int num = 1234;
        assert(solution.largestInteger(num) == 3412);
    }
    {
        int num = 1;
        assert(solution.largestInteger(num) == 1);
    }
    {
        int num = 65875;
        assert(solution.largestInteger(num) == 87655);
    }
    {
        int num = 23;
        assert(solution.largestInteger(num) == 23);
    }
    {
        int num = 247;
        assert(solution.largestInteger(num) == 427);
    }
}

}

namespace Jump_Game {

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int min_jump = 0;
        for (int i = nums.size() - 2; i >= 0; --i) {
            ++min_jump;
            if (nums[i] >= min_jump) {
                min_jump = 0;
            }
        }
        return min_jump == 0 ? true : false;
    }
};

void Tests() {
    Solution solution;
    {
        vector<int> nums {2};
        assert(solution.canJump(nums) == true);
    }
    {
        vector<int> nums {0};
        assert(solution.canJump(nums) == true);
    }
    {
        vector<int> nums {2,3,1,1,4};
        assert(solution.canJump(nums) == true);
    }
    {
        vector<int> nums {3,2,1,0,4};
        assert(solution.canJump(nums) == false);
    }
    {
        vector<int> nums {3,2,2,0,4};
        assert(solution.canJump(nums) == true);
    }
    {
        vector<int> nums {2,0,2,0,4};
        assert(solution.canJump(nums) == true);
    }

}
}



namespace Sort_Array_By_Parity {

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> result;
        vector<int> odd;
        for (auto num : nums) {
            if (num % 2 == 0) {
                result.push_back(num);
            } else {
                odd.push_back(num);
            }
        }
        for (auto num : odd) {
            result.push_back(num);
        }
        return result;
    }
};

void Tests() {
    Solution solution;
    {
        vector<int> nums {3,1,2,4};
        vector<int> ans {2,4,3,1};
        assert(solution.sortArrayByParity(nums) == ans);
    }
    {
        vector<int> nums {0};
        vector<int> ans {0};
        assert(solution.sortArrayByParity(nums) == ans);
    }
    {
        vector<int> nums {1,1,1,1,1};
        vector<int> ans {1,1,1,1,1};
        assert(solution.sortArrayByParity(nums) == ans);
    }
    {
        vector<int> nums {4222,3790,2103,1294,2556,2025,3919,1516,2383,2917};
        vector<int> ans {4222,3790,1294,2556,1516,2103,2025,3919,2383,2917};
        assert(solution.sortArrayByParity(nums) == ans);
    }
}

}

namespace Climbing_Stairs {

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        vector<int> count (n + 1);
        count[0] = 1;
        count[1] = 1;
        for (size_t i = 2; i < count.size(); ++i) {
            count[i] = count[i - 1] +  count[i - 2];
        }
        return count[n];
    }
};

void Tests() {
    Solution solution;
    assert(solution.climbStairs(1) == 1);
    assert(solution.climbStairs(2) == 2);
    assert(solution.climbStairs(3) == 3);
    assert(solution.climbStairs(4) == 5);
    assert(solution.climbStairs(5) == 8);

}

}

namespace Ugly_Number_II {

class Solution {
public:
    int nthUglyNumber(int n) {
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        vector<int> result(n);
        result[0] = 1;
        result[1] = 2;
        result[2] = 3;
        for (int i = 3; i < n; ++i) {
            result[i] = min(result[i - 3] * 5, min(result[i - 2] * 3, result[i - 1] * 2));
        }
        return result[n - 1];
    }
};

void Tests() {
    Solution solution;
    assert(solution.nthUglyNumber(1) == 1);
    assert(solution.nthUglyNumber(10) == 12);
}

}


namespace Pascal_Triangle {

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result(numRows);
        for (int i = 0; i < numRows; ++i) {
            result[i] = vector<int>(i + 1, 1);
            for (int j = 1; j < i; ++j) {
                result[i][j] = result[i - 1][j] + result[i - 1][j - 1];
            }
        }
        return result;
    }
};

void Tests() {
    Solution solution;
    {
        vector<vector<int>> ans = {{1}};
        assert(solution.generate(1) == ans);
    }
    {
        vector<vector<int>> ans = {{1}, {1, 1}};
        assert(solution.generate(2) == ans);
    }
    {
        vector<vector<int>> ans = {{1}, {1, 1}, {1,2,1}};
        assert(solution.generate(3) == ans);
    }
    {
        vector<vector<int>> ans = {{1}, {1, 1}, {1,2,1}, {1,3,3,1}};
        assert(solution.generate(4) == ans);
    }

}

}


namespace Subarray_Sum_Equals_K {

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int result = 0;
        vector<int> prefix_sum(nums.size());
        prefix_sum[0] = nums[0];
        for (size_t i = 1; i < nums.size(); ++i) {
            prefix_sum[i] = prefix_sum[i - 1] + nums[i];
        }
        unordered_map<int, int> map_;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (prefix_sum[i] == k) {
                ++result;
            }
            if (map_.count(prefix_sum[i] - k)) {
                result += map_[prefix_sum[i] - k];
            }
            map_[prefix_sum[i]]++;
        }
        return result;
    }
};

void Tests() {
     Solution solution;
     {
         vector<int> nums {1,1,1};
         assert(solution.subarraySum(nums, 2) == 2);
     }
     {
         vector<int> nums {1,2,3};
         assert(solution.subarraySum(nums, 3) == 2);
     }
     {
         vector<int> nums {1};
         assert(solution.subarraySum(nums, 1) == 1);
     }
     {
         vector<int> nums {2,1,2};
         assert(solution.subarraySum(nums, 2) == 2);
     }

}

}

namespace Number_of_Subarrays_with_Bounded_Maximum {

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int result = 0;
        int prev_bigger_than_r = -1;
        int count_prev = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] > right) {
                count_prev = 0;
                prev_bigger_than_r = i;
            } else if (nums[i] < left) {
                result += count_prev;
            } else {
                count_prev = i - prev_bigger_than_r;
                result += count_prev;
            }
        }
        return result;
    }
};

void Tests() {
    Solution solution;
    {
        vector<int> nums {2,1,4,3};
        assert(solution.numSubarrayBoundedMax(nums, 2, 3) == 3);
    }
    {
        vector<int> nums {2,9,2,5,6};
        assert(solution.numSubarrayBoundedMax(nums, 2, 8) == 7);
    }
    {
        vector<int> nums {2,9,2,5,6};
        assert(solution.numSubarrayBoundedMax(nums, 10, 11) == 0);
    }
    {
        vector<int> nums {2};
        assert(solution.numSubarrayBoundedMax(nums, 0, 8) == 1);
    }
    {
        vector<int> nums {2};
        assert(solution.numSubarrayBoundedMax(nums, 5, 8) == 0);
    }
}

}

namespace Is_Subsequence {

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.empty() && t.empty()) {
            return true;
        }
        for (size_t i = 0; i < t.size(); ++i) {
            if (s[0] == t[i]) {
                s = s.substr(1);
            }
            if (s.empty()) {
                return true;
            }
        }
        return false;
    }
};

void Tests() {
    Solution solution;
    {
        string s = "abc";
        string t = "ahbgdc";
        assert(solution.isSubsequence(s, t) == true);
    }
    {
        string s = "axc";
        string t = "ahbgdc";
        assert(solution.isSubsequence(s, t) == false);
    }
    {
        string s = "axc";
        string t = "abcxd";
        assert(solution.isSubsequence(s, t) == false);
    }
    {
        string s = "";
        string t = "abcxd";
        assert(solution.isSubsequence(s, t) == true);
    }

}

}

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
        solution.MemoryClearing(new_root);
    }
}

}


namespace Ugly_Number {

class Solution {
public:
    bool isUgly(int n) {
        while (n > 1) {
            if (n % 2 == 0) {
                n /= 2;
            } else if (n % 3 == 0) {
                n /= 3;
            } else if (n % 5 == 0) {
                n /= 5;
            } else {
                return false;
            }
        }
        return true;
    }
};

void Tests() {
    Solution solution;
    {
        int n = 6;
        assert(solution.isUgly(n) == true);
    }
    {
        int n = 1;
        assert(solution.isUgly(n) == true);
    }
    {
        int n = 14;
        assert(solution.isUgly(n) == false);
    }
    {
        int n = 17;
        assert(solution.isUgly(n) == false);
    }
    {
        int n = 30;
        assert(solution.isUgly(n) == true);
    }
    {
        int n = -1;
        assert(solution.isUgly(n) == false);
    }
    {
        int n = 0;
        assert(solution.isUgly(n) == false);
    }
}

}

namespace Prime_Number_of_Set_Bits_in_Binary_Representation {

class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int result = 0;
        for (int i = left; i <= right; ++i) {
            result += IsPrime(SumBitsInNumber(i));
        }
        return result;
    }

    int SumBitsInNumber(int num) {
        int sum = 0;
        while(num > 0) {
            sum += num & 1;
            num = num >> 1;
        }
        return sum;
    }

    bool IsPrime(int num) {
        if (num == 1) {
            return false;
        }
        for (int i = 2; i < num - 1; ++i) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }
};

void Tests() {
    Solution solution;
    assert(solution.IsPrime(1) == false);
    assert(solution.IsPrime(19) == true);
    assert(solution.IsPrime(100) == false);
    assert(solution.IsPrime(97) == true);
    assert(solution.SumBitsInNumber(0) == 0);
    assert(solution.SumBitsInNumber(1) == 1);
    assert(solution.SumBitsInNumber(6) == 2);
    assert(solution.SumBitsInNumber(15) == 4);
    assert(solution.countPrimeSetBits(1, 1) == 0);
    assert(solution.countPrimeSetBits(6, 10) == 4);
    assert(solution.countPrimeSetBits(10, 15) == 5);
}

}

namespace Number_of_1_Bits {

class Solution {
public:
    int hammingWeight(uint32_t number) {
        int sum = 0;
        while(number > 0) {
            if ((number & 1) > 0) {
                ++sum;
            }
            number = number >> 1;
        }
        return sum;
    }
};

void Tests() {
    Solution solution;
    uint32_t n = 00000000000000000000000000001011;
    assert(solution.hammingWeight(n) == 3);
    n = 00000000000000000000000010000000;
    assert(solution.hammingWeight(n) == 1);
}

}

namespace Triangle {

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp {triangle[triangle.size() - 1]};
        for (int row = triangle.size() - 2; row >= 0; row--) {
            for (size_t colom = 0; colom < triangle[row].size(); ++colom) {
                dp[colom] = min(dp[colom], dp[colom + 1]) + triangle[row][colom];
            }
        }
        return dp[0];
    }
};

void Tests() {
    Solution solution;
    {
        vector<vector<int>> triangle {{-10}};
        assert(solution.minimumTotal(triangle) == -10);
    }
    {
        vector<vector<int>> triangle {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
        assert(solution.minimumTotal(triangle) == 11);
    }
    {
        vector<vector<int>> triangle {{2}, {2, 4}, {2, 5, 7}, {2, 1, 8, 3}};
        assert(solution.minimumTotal(triangle) == 7);
    }
    {
        vector<vector<int>> triangle {{-1}, {2, 3}, {1, -1, -3}};
        assert(solution.minimumTotal(triangle) == -1);
    }

}

}

namespace Replace_Elements_with_Greatest_Element_on_Right_Side {

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> result (arr.size());
        result[result.size() - 1] = -1;
        for (size_t i = arr.size() - 1; i > 0; --i) {
            result[i - 1] = max(result[i], arr[i]);
        }
        return result;
    }
};

void Tests() {
    Solution solution;
    {
        vector<int> test {17,18,5,4,6,1};
        vector<int> answer {18,6,6,6,1,-1};
        assert(solution.replaceElements(test) == answer);
    }
    {
        vector<int> test {40};
        vector<int> answer {-1};
        assert(solution.replaceElements(test) == answer);
    }
}

}

namespace Path_Crossing {

class Solution {
public:
    bool isPathCrossing(string path) {
        using point = std::pair<uint32_t, uint32_t>;
        set<point> points;
        point current_point = {0, 0};
        points.insert(current_point);
        for (auto& element : path) {
            if (element == 'N') {
                current_point.second += 1;
            } else if (element == 'S') {
                current_point.second -= 1;
            } else if (element == 'E') {
                current_point.first += 1;
            } else {
                current_point.first -= 1;
            }
            if (points.count(current_point)) {
                return true;
            } else {
                points.insert(current_point);
            }
        }
        return false;
    }
};

void Tests() {
    Solution solution;
    {
        string path = "NES";
        assert(solution.isPathCrossing(path) == false);
        path = "N";
        assert(solution.isPathCrossing(path) == false);
        path = "NESWW";
        assert(solution.isPathCrossing(path) == true);
    }
}

}

namespace Delete_Node_in_a_BST {

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
    TreeNode* FindElement(TreeNode* root, int key) {
        if (root) {
            TreeNode* node = root;
            TreeNode* parent = root;
            while(node) {
                if (key == node->val) {
                    return parent;
                } else if (node->left && (key <= node->left->val)) {
                    parent = node;
                    node = node->left;
                } else if (node->right && (key >= node->right->val)) {
                    parent = node;
                    node = node->right;
                } else {
                    return nullptr;
                }
            }
        }
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* parent = FindElement(root, key);
        if (parent) {
            if (parent->val == key) {
            }
        }
        return root;
    }
};

void Tests() {
    Solution solution;
    {
        TreeNode* root = new TreeNode{5, new TreeNode{3, new TreeNode{2}, new TreeNode{4}}, new TreeNode{6, nullptr, new TreeNode{7}}};
        solution.deleteNode(root, 3);
    }
}

}

namespace Reverse_String {

class Solution {
public:
    void reverseString(vector<char>& s) {
        if (s.empty()) {
            return;
        }
        for (size_t i = 0; i < s.size() / 2; ++i) {
            std::swap(s[i], s[s.size() - 1 - i]);
        }
    }
};

void Tests() {
    Solution solution;
    {
        vector<char> s;
        solution.reverseString(s);
        vector<char> result;
        assert(s == result);
    }
    {
        vector<char> s = {'h','e','l','l','o'};
        solution.reverseString(s);
        vector<char> result = {'o', 'l', 'l', 'e', 'h'};
        assert(s == result);
    }
    {
        vector<char> s = {'H','a','n','n','a','h'};
        solution.reverseString(s);
        vector<char> result = {'h','a','n','n','a','H'};
        assert(s == result);
    }
    {
        vector<char> s = {'H'};
        solution.reverseString(s);
        vector<char> result = {'H'};
        assert(s == result);
    }
}
}

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

}

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

}

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

namespace Max_Sequence_Size {

class Solution {
public:
    int MaxSize(const vector<int>& seq) {
        if (seq.empty()) {
            return 0;
        }
        int max_count = 0;
        int current_count = 0;
        unordered_set<int> sub_seq;
        for (const auto value : seq) {
            if (sub_seq.count(value)) {
                if (current_count > max_count) {
                    max_count = current_count;
                }
                current_count = 0;
                sub_seq.clear();
            }
            sub_seq.insert(value);
            ++current_count;
        }
        if (current_count > max_count) {
            max_count = current_count;
        }
        return max_count;
    }
};

void Tests() {
    Solution solution;
    {
        std::vector<int> seq{1, 2, 3};
        assert(solution.MaxSize(seq) == 3);
    }
    {
        std::vector<int> seq{1, 2, 2, 3};
        assert(solution.MaxSize(seq) == 2);
    }
    {
        std::vector<int> seq{1, 1, 2, 3};
        assert(solution.MaxSize(seq) == 3);
    }
    {
        std::vector<int> seq{1, 2, 3, 3};
        assert(solution.MaxSize(seq) == 3);
    }
    {
        std::vector<int> seq{1, 2, 4, 5, 2, 2, 6, 7, 1};
        assert(solution.MaxSize(seq) == 4);
    }
    {
        std::vector<int> seq{1, 2, 3, 4, 5, 5, 1};
        assert(solution.MaxSize(seq) == 5);
    }
}

}

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

int main() {
    Smallest_String_Starting_From_Leaf::Tests();
    return 0;
}
