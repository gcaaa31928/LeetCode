#include <vector>
#include <queue>
#include <climits>
#include <cstdio>

using namespace std;

class Solution {
public:


    vector<int> findMinHeightTrees(int n, vector<pair<int, int>> &edges) {
        vector<int> ans;
        vector<int> leaf;
        int degree[n + 1] = {0};
        vector<vector<int>> to(n,vector<int>());

        for (int i = 0; i < edges.size(); i++) {
            degree[edges[i].first]++;
            degree[edges[i].second]++;
            to[edges[i].first].push_back(edges[i].second);
            to[edges[i].second].push_back(edges[i].first);
        }
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                leaf.push_back(i);
            }
        }
        int remained = n;
        while(remained >2) {
            for(int i =0;i<leaf.size();i++) {
                degree[leaf[i]]=-1;
                for(int j = 0;j<to[leaf[i]].size();j++) {
                    int target = to[leaf[i]][j];
                    degree[target]--;
                }
            }
            remained-=leaf.size();
            printf("%d\n", remained);
            leaf.clear();
            for (int i = 0; i < n; i++) {
                if (degree[i] == 1) {
                    leaf.push_back(i);
                }
            }
        }
        for(int i =0;i<n;i++) {
            if (degree[i]>-1)
                ans.push_back(i);
        }
        return ans;
    }
};