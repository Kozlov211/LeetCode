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
