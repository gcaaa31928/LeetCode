#include <string>
using namespace std;
class Solution {
public:
    int firstUniqChar(string s) {
        int exists[300]={0};
        for(int i=0;i<s.size();i++) {
            exists[s[i]-'a']++;
        }
        for(int i=0;i<s.size();i++) {
            if(exists[s[i]-'a']<2) {
                return i;
            }
        }
        return -1;
    }
};