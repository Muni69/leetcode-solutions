class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) return false;

        int n = s.length();

        for (int i = 0; i < n; i++) {
            string rotated = "";

            // Build rotated string starting from index i
            for (int j = 0; j < n; j++) {
                rotated += s[(i + j) % n];
            }

            // Compare with goal
            if (rotated == goal) return true;
        }

        return false;
    }
};