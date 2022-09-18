namespace Ugly_Number {

class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0) {
            return false;
        }
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
