#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low = 1, high = nums.size()-1;
        while(high>=low) {
            int mid = low + (high-low)/2;
            int count = 0;
            for(int i =0 ;i<nums.size();i++) {
                if (nums[i] <= mid) {
                    count ++;
                }
            }
            bool isover = count > mid;
            if (!isover) {
                low = mid + 1;
            }else
                high = mid;
        }
        return low;
    }
};