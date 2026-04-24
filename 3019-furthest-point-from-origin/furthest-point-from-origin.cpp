class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int left = 0, right = 0, unknown = 0;

        for (char c : moves) {
            if (c == 'L') left++;
            else if (c == 'R') right++;
            else unknown++; // '_'
        }

        return abs(right - left) + unknown;
    }
};