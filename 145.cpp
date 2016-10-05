#include <vector>
#include <afxres.h>
#include <stack>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ans;
        stack<TreeNode *> st;
        stack<int> res;
        if (root==NULL)return ans;
        st.push(root);
        while(!st.empty()) {
            TreeNode *current = st.top();
            st.pop();
            if (current == NULL) continue;
            res.push(current->val);
            st.push(current->left);
            st.push(current->right);
        }
        while(!res.empty()) {
            ans.push_back(res.top());
            res.pop();
        }
        return ans;
    }
};