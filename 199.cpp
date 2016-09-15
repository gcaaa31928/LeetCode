#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    vector<int> ans;

    void getRightSide(TreeNode *root, int level){
        if(root) {
            if (ans.size() <= level)
                ans.push_back(root->val);
            if (root->right)
                getRightSide(root->right, level+1);
            if (root->left)
                getRightSide(root->left, level+1);
        }
    }

    vector<int> rightSideView(TreeNode *root) {
        ans.clear();
        this->getRightSide(root, 0);
        return ans;
    }
};