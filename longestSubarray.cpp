#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int result = 0;
        auto it_begin = nums.begin();
        auto it_end = nums.begin();
        pair<vector<int>::iterator, vector<int>::iterator> minmax_ = minmax_element(it_begin, it_end); 
        while (it_end != nums.end()) {
            cout << *it_begin << " " << *it_end << endl;
            ++it_end;
			if (std::abs(*it_end - *minmax_.second) > limit) {
                result = (distance(it_begin, it_end) > result ? distance(it_begin, it_end) : result);
                ++it_begin;
                minmax_ = minmax_element(it_begin, it_end);
            } else {
				*minmax_.second = (*it_end > *minmax_.second ? *it_end : *minmax_.second);
                ++it_end;
            }
        }
        return result;
    }
};

int main() {
	Solution sol;
	vector<int> nums = {10,1,2,4,7,2};
	int limit = 5;
	cout << sol.longestSubarray(nums, limit);
	return 0;
}
