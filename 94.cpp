#include <stack>
#include <vector>
#include <afxres.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;
        while(root!=NULL) {
            st.push(root);
            root=root->left;
        }
        while(!st.empty()) {
            TreeNode *current = st.top();
            st.pop();
            ans.push_back(current->val);
            if (current->right) {
                current = current->right;
                while(current!=NULL) {
                    st.push(current);
                    current = current->left;
                }
            }
        }
        return ans;
    }
};