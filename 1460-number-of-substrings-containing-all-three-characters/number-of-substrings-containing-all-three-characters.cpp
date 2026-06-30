class Solution {
public:
    int numberOfSubstrings(string s) {
        int count[3] = {0, 0, 0};
        int left = 0;
        int result = 0;
        
        for (int right = 0; right < s.size(); right++) {
            count[s[right] - 'a']++;
            
            // Shrink window from left while it still contains all 3 chars
            while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
                count[s[left] - 'a']--;
                left++;
            }
            
            // 'left' valid starting points for substrings ending at 'right'
            result += left;
        }
        
        return result;
    }
};