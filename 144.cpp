#include <afxres.h>
#include <vector>
#include <stack>

using namespace std;
/**
 * Definition for a binary tree node.*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    stack<TreeNode*> st;
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> ans;
        st.push(root);
        while(!st.empty()) {
            TreeNode* current = st.top();
            st.pop();
            if (current==NULL)continue;
            ans.push_back(current->val);
            st.push(current->right);
            st.push(current->left);
        }
        return ans;
    }
};