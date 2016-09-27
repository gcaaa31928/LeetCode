#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); i++) {
            s.insert(nums[i]);
        }
        int len = 0;
        for (int i = 0; i < nums.size(); i++) {
            int tmp = nums[i];
            int tmplen = 0;
            unordered_set<int>::const_iterator got = s.find(tmp);
            for (; got != s.end(); got = s.find(tmp)) {
                tmp--;
                tmplen++;
                s.erase(got);
            }
            tmp=nums[i]+1;
            got = s.find(tmp);
            for (; got != s.end(); got = s.find(tmp)) {
                tmp++;
                tmplen++;
                s.erase(got);
            }
            len = max(len, tmplen);
        }
        return len;
    }
};