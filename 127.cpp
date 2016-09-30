#include <string>
#include <unordered_set>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:

    int ladderLength(string beginWord, string endWord, unordered_set<string> &wordList) {
        queue<pair<string, int>> q;
        unordered_set<string> visited;
        visited.insert(beginWord);
        q.push(pair<string, int>(beginWord, 1));
        while (!q.empty()) {
            string str = q.front().first;
            printf("%s\n", str.c_str());
            int dist = q.front().second;
            if (str == endWord) {
                return dist;
            }
            q.pop();
            for (int i = 0; i < str.size(); i++) {
                string tmp = str;
                for (char c = 'a'; c <= 'z'; c++) {
                    tmp[i] = c;
                    if (wordList.find(tmp) != wordList.end() && visited.find(tmp) == visited.end()) {
                        visited.insert(tmp);
                        q.push(pair<string, int>(tmp, dist + 1));
                    }
                }
            }
        }
        return 0;
    }
};

int main() {
    Solution solution;
    unordered_set<string> wordList;
    wordList.insert("hot");
    wordList.insert("dog");
    printf("%d\n", solution.ladderLength("hot", "dog", wordList));
}