#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int> &nums) {
        vector<string> ans;
        if (nums.size() == 0)return ans;
        int start = 0;
        int tmp = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (tmp + 1 == nums[i]) {
                tmp = nums[i];
            } else {
                char res[20];
                if (start == i - 1)
                    sprintf(res, "%d", nums[start]);
                else
                    sprintf(res, "%d->%d", nums[start], nums[i - 1]);
                ans.push_back(res);
                start = -1;
            }
            if (start == -1) {
                start = i;
                tmp = nums[i];
            }
        }
        if (start != -1) {
            char res[20];
            if (start == nums.size() - 1)
                sprintf(res, "%d", nums[start]);
            else
                sprintf(res, "%d->%d", nums[start], nums[nums.size() - 1]);
            ans.push_back(res);
        }
        return ans;
    }
};