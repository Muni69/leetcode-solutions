#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int r, int c, int k) {
        
        for (int i = 0; i < k / 2; i++) {
            for (int j = 0; j < k; j++) {
                swap(grid[r + i][c + j], grid[r + k - 1 - i][c + j]);
            }
        }
        
        return grid;
    }
};