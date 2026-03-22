class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for (int k = 0; k < 4; k++) {
            if (mat == target) return true;

            // Transpose
            int n = mat.size();
            for (int i = 0; i < n; i++) {
                for (int j = i; j < n; j++) {
                    swap(mat[i][j], mat[j][i]);
                }
            }

            // Reverse each row
            for (auto &row : mat) {
                reverse(row.begin(), row.end());
            }
        }
        return false;
    }
};