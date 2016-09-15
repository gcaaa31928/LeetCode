/**
 * Definition for a binary tree node.
 *
 *  1
   / \
  2   2
 / \ / \
3  4 4  3

    1
   / \
  2   2
   \   \
   3    3
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    bool symmetric(TreeNode* sym_left, TreeNode* sym_right) {
        if (sym_left->val != sym_right->val){
            return false;
        }
        bool is_sym = true;
        if ((sym_left->left && !sym_right->right) || (!sym_left->left && sym_right->right)) return false;
        if ((sym_left->right && !sym_right->left) || (!sym_left->right && sym_right->left)) return false;

        if (sym_left->left && sym_right->right)
            is_sym = is_sym && symmetric(sym_left->left, sym_right->right);
        if (sym_left->right && sym_right->left)
            is_sym = is_sym && symmetric(sym_left->right, sym_right->left);

        return is_sym;
    }

    bool isSymmetric(TreeNode* root) {
        if (root) {
            if (root->left && root->right)
                return symmetric(root->left, root->right);
            if ((root->left && !root->right) || (!root->left && root->right))
                return false;
        }
        return true;
    }
};

