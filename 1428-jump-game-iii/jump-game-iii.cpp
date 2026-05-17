class Solution {
public:
    bool dfs(vector<int>& arr, int idx, vector<int>& vis) {
        
        // Out of bounds
        if (idx < 0 || idx >= arr.size())
            return false;

        // Already visited
        if (vis[idx])
            return false;

        // Found zero
        if (arr[idx] == 0)
            return true;

        vis[idx] = 1;

        return dfs(arr, idx + arr[idx], vis) ||
               dfs(arr, idx - arr[idx], vis);
    }

    bool canReach(vector<int>& arr, int start) {
        vector<int> vis(arr.size(), 0);

        return dfs(arr, start, vis);
    }
};