#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int result = 1;
        auto it = nums.begin() + 1;
        int tmp = nums[0];
        while (it != nums.end()) {
            if (tmp == *it) {
                ++it;
            } else {
                tmp = *it;
                nums[result++] = tmp;
            }
        }
        return  result;
    }
};

int main() {

	return 0;
}
