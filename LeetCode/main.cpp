#include <iostream>
#include <vector>

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

int main()
{
    Solution4 sol;
    vector<int> tmp1 {1, 2, 3, 4, 5};
    vector<int> tmp2 {};
    cout << sol.findMedianSortedArrays(tmp1, tmp2);
    return 0;
}
