#include <vector>
#include <map>
#include <cstdio>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> hmap;
        vector<int> ans;
        for (int i =0;i<nums.size();i++) {
            int tmp = target - nums[i];
            map<int,int>::iterator it = hmap.find(tmp);
            if (it != hmap.end()) {
                ans.push_back(i);
                ans.push_back(it->second);
                return ans;
            }
            hmap[nums[i]] = i;
        }
        return ans;
    }
};
