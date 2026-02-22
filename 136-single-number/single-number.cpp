class Solution {
public:
    int singleNumber(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) 
        {
            int x = 0;  // initialize here
            
            for(int j = 0; j < nums.size(); j++) 
            {
                if(nums[i] == nums[j]) 
                {
                    x++;
                }
            }
            
            if(x == 1)   // check AFTER inner loop
            {
                return nums[i];
            }
        }
        return -1;
    }
};