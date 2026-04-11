class Solution {
public:
    void dfs(TreeNode* root, string path, vector<string>& result) {
        if (!root) return;

        // Add current node to path
        if (!path.empty()) path += "->";
        path += to_string(root->val);

        // If leaf node → save path
        if (!root->left && !root->right) {
            result.push_back(path);
            return;
        }

        // Recurse left and right
        dfs(root->left, path, result);
        dfs(root->right, path, result);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        dfs(root, "", result);
        return result;
    }
};
