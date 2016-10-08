#include <stack>
#include <afxres.h>
#include <climits>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    bool valid(TreeNode *node, long lowerBound, long upperBound) {
        if (node==NULL)return true;
        int val = node->val;
        if (lowerBound >= val)
            return false;
        if (upperBound <=val)
            return false;
        return valid(node->left,lowerBound,val) && valid(node->right, val, upperBound);
    }

    bool isValidBST(TreeNode* root) {
        if (root==NULL)return true;
        return valid(root, (long)INT_MIN-1, (long)INT_MAX+1);
    }
};