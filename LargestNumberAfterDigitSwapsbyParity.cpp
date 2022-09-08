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
