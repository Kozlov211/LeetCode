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

