//
//  main.cpp
//  126
//
//  Created by ChangMingfung on 2016/2/7.
//  Copyright © 2016年 ChangMingfung. All rights reserved.
//

#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    
    unordered_map<string, vector<string> > mp; // result map <current string, parent neighbors>
    vector<vector<string> > res;
    vector<string> path;
    
    void findDict2(string str, unordered_set<string> &dict, unordered_set<string> &next_lev){
        for (int i = 0, sz = str.size(); i<sz; ++i){
            string s = str;
            for (char j = 'a'; j <= 'z'; ++j){
                s[i] = j;
                if (dict.find(s) != dict.end()){
                    next_lev.insert(s);
                    mp[s].push_back(str); //save the string which could be transformed to s
                }
            }
        }
    }
    //DFS
    void output(string start, string last){
        if (last == start){
            reverse(path.begin(), path.end());
            res.push_back(path);
            reverse(path.begin(), path.end());
        }
        else{
            for (auto i : mp[last]){
                path.push_back(i);
                output (start, i);
                path.pop_back();
            }

        }
    }
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        
        dict.insert(end);
        unordered_set<string> cur_lev;
        cur_lev.insert(start);
        unordered_set<string> next_lev;
        path.push_back(end);
        
        while (true){
            for (auto it : cur_lev){
                dict.erase(it);
            } //delete previous level words
            
            for (auto it : cur_lev){
                findDict2(it, dict, next_lev);
            }
            //find current level words
            
            if (next_lev.empty()){
                return res; }
            
            if (next_lev.count(end) != 0){ //if find end string
                output(start, end);
                return res;
            }
            cur_lev.clear();
            cur_lev = next_lev;
            next_lev.clear();
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    unordered_set<string> input = { "hot", "dot", "dog", "lot", "log" };
    Solution sol;
    vector<vector<string>> Ret = sol.findLadders("hit", "cog", input);
    
    return 0;
}
