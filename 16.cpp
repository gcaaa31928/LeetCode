#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        int ans;
        int closest = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            int t = target - nums[i];
            int l = 0;
            int r = nums.size() - 1;
            while (r > l) {
                if(r==i) {
                    r--;
                    continue;
                }
                if(l==i) {
                    l++;
                    continue;
                }
                int r_n = nums[r];
                int l_n = nums[l];
                if (closest > abs(target - r_n - l_n - nums[i])) {
                    closest = abs(target - r_n - l_n - nums[i]);
                    ans=r_n+l_n+nums[i];
                }
                if (r_n + l_n < t) {
                    l++;
                } else if (r_n + l_n > t) {
                    r--;
                }else{
                    return r_n+l_n+nums[i];
                }
            }
        }
        return ans;
    }
};