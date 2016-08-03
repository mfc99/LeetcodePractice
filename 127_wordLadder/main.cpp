#include <string>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string> &wordList) {
        
        wordList.insert(endWord);
        queue<pair<string, int>> q; //queue <current_string, the # of transform>
                                    // Space O(WordList size)
        q.push(make_pair(beginWord, 1));
        while (!q.empty()) {
            string s = q.front().first;
            int len = q.front().second;
            if (s == endWord) return len;
            q.pop();
            vector<string> neighbors = findNeighbors(s, wordList);
            for (int i = 0; i<neighbors.size(); i++) //Runtime O(WordList_size)
                q.push(make_pair(neighbors[i], len + 1));
        }
        return 0; // if there's no match, return 0;
    }
    vector<string> findNeighbors(string s, unordered_set<string> &dict) {
        vector<string> ret;
        
        for (int i = 0, n = s.size(); i < n; ++i) { //Runtime O(string size x 26)
            char c = s[i];
            for (int j = 0; j<26; ++j) {
                if (c == 'a' + j) continue; //
                s[i] = 'a' + j;
                if (dict.count(s)) {
                    ret.push_back(s);
                    dict.erase(s);
                }
            }
            s[i] = c;
        }
        return ret;
    }
};


int main(int argc, const char * argv[]) {
    
    unordered_set<string> input = {"hot","dot","dog","lot","log"};
    Solution sol;
    //return the shortest transformation
    // Runtime O(WordList_size * string_size)
    // space O()
    int Ret = sol.ladderLength("hit","cog",input);
    
    return 0;
}
