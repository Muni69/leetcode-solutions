class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorAll = 0;

        for (int num : nums) {
            xorAll ^= num;
        }

        unsigned int x = xorAll;
        unsigned int diff = x & ~(x - 1);

        int a = 0, b = 0;

        for (int num : nums) {
            if (num & diff)
                a ^= num;
            else
                b ^= num;
        }

        return {a, b};
    }
};