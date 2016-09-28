#include <vector>
using namespace std;
class Solution {
public:
    int countPrimes(int n) {
        if (n==0)return 0;
        bool seize[n]={0};
        for(long long i=2;i*i<n;i++){
            if(!seize[i]) {
                for(long long j=i*i;j<n;j+=i) {
                    seize[j]=true;
                }
            }
        }
        int ans=0;
        for(int i=2;i<n;i++) {
            if(!seize[i]) ans++;
        }
        return ans;
    }
};