#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>> &matrix) {
        vector<vector<int>> dp;
        for (int i = 0; i < matrix.size(); i++) {
            dp.push_back(vector<int>());
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == '1')
                    dp[i].push_back(1);
                else
                    dp[i].push_back(0);
            }
        }
        int max_ans = INT_MIN;
        for (int i = 0; i < dp.size(); i++) {
            for (int j = 0; j < dp[i].size(); j++) {
                bool up = i - 1 >= 0 && i - 1 < dp.size() && j >= 0 && j < dp[i - 1].size();
                bool left = i >= 0 && i < dp.size() && j - 1 >= 0 && j - 1 < dp[i].size();
                bool slash = i - 1 >= 0 && i - 1 < dp.size() && j - 1 >= 0 && j - 1 < dp[i - 1].size();
                int get_min = INT_MAX;
                if (up && left && slash && dp[i][j]) {
                    get_min = min(dp[i-1][j],dp[i][j-1]);
                    get_min = min(get_min, dp[i-1][j-1]);
                    dp[i][j]=max(dp[i][j],get_min+1);
                }
                max_ans = max(dp[i][j], max_ans);
            }
        }
        for (int i = 0; i < dp.size(); i++) {
            for (int j = 0; j < dp[i].size(); j++) {
                printf("%d", dp[i][j]);
            }
            printf("\n");
        }
        return max_ans*max_ans;
    }
};
