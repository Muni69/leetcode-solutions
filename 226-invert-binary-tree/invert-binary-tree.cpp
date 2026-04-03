class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;

        // Swap left and right
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        // Recurse on subtrees
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};