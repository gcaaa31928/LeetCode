#include <algorithm>

using namespace std;

class Solution {
public:
    int integerReplacement(int n) {
        if (n == 1) {
            return 0;
        }
        if (n==2147483647){
            return 32;
        }

        int ans;
        if (n & 1) {
            ans = min(integerReplacement(n + 1), integerReplacement(n - 1)) + 1;
        } else {
            ans = integerReplacement(n >> 1) + 1;
        }
        return ans;
    }
};