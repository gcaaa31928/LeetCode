#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int> &nums) {
        int dp[nums.size() + 1] = {0};
        int p[nums.size()+1]={0};
        sort(nums.begin(), nums.end());
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            int max_res = 1;
            int parent = -1;
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[j]+1>max_res) {
                    max_res = dp[j]+1;
                    parent=j;
                }
            }
            p[i]=parent;
            dp[i] = max_res;
        }
        vector<int> ans;
        int max_ans = 0, max_index = -1;
        for(int i =0;i<nums.size();i++) {
            if (dp[i]>max_ans) {
                max_ans=dp[i];
                max_index=i;
            }
        }

        for(int i=max_index;i!=-1;i=p[i]) {
            ans.push_back(nums[i]);
        }
        return ans;
    }
};