namespace Number_of_1_Bits {

class Solution {
public:
    int hammingWeight(uint32_t number) {
        int sum = 0;
        while(number > 0) {
            if (number & 1 > 0) {
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
