class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }
        
        int ans = INT_MAX;
        
        for (auto& [num, indices] : mp) {
            if (indices.size() >= 3) {
                for (int i = 0; i + 2 < indices.size(); i++) {
                    int dist = 2 * (indices[i + 2] - indices[i]); // ✅ FIX
                    ans = min(ans, dist);
                }
            }
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};