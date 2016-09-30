#include <vector>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, cand=-1;
        for(int i=0;i<nums.size();i++) {
            if (cand!=nums[i]) {
                count--;
            }else {
                count++;
            }
            if (count<=0) {
                cand = nums[i];
                count=1;
            }
        }
        return cand;
    }
};