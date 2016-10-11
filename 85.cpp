#include <vector>
#include <stack>
#include <libintl.h>

using namespace std;

class Solution {
public:

    int largestArea(vector<int> rows) {
        int i = 0;
        stack<int> st;
        rows.push_back(0);
        int area = 0;
        while (i < rows.size()) {
            if (st.empty() || rows[st.top()] < rows[i]) {
                st.push(i++);
            } else {
                int prevIndex = st.top();
                st.pop();
                int width;
                if (st.empty()) width=i;
                else width = i-st.top()-1;
                area=max(area, width*rows[prevIndex]);
            }
        }
        return area;
    }

    int maximalRectangle(vector<vector<char>> &matrix) {
        int n = matrix.size();
        if (n==0) return 0;
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m));
        for (int i = 0; i < m; i++) {
            dp[0][i] = matrix[0][i] - '0';
        };
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1')
                    dp[i][j] = dp[i - 1][j] + 1;
                else
                    dp[i][j] = 0;
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                printf("%d", dp[i][j]);
            }
            puts("");
        }
        int ans =0 ;
        for(int i =0;i<n;i++) {
            ans=max(ans, largestArea(dp[i]));
        }
        return ans;
    }
};