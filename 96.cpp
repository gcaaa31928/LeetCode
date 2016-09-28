#include <vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 5, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            int sum=0;
            for(int j=0;j<=i-1;j++) {
                sum+=dp[j]*dp[i-j-1];
            }
            dp[i]=sum;
        }
        return dp[n];

    }
};