class Solution {
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
