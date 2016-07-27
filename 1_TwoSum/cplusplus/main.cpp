//
//  main.cpp
//  1_TwoSum
//
//  Created by ChangMingfung on 7/26/16.
//  Copyright © 2016 ChangMingfung. All rights reserved.
//

/*
 Given an array of integers, find two numbers such that they add up to a specific target number.
 
 The function twoSum should return indices of the two numbers such that they add up to the target,
 where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
 
 You may assume that each input would have exactly one solution.
 
 Input: numbers={2, 7, 11, 15}, target=9
 Output: index1=1, index2=2
 
 */
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    
public:
    
    vector<int> twoSum(vector<int>& nums, int target)
    {
        size_t size = nums.size();
        vector<int> retV;
        unordered_map<int, int> hmap;
        
        // initialize the map use each number value as keys, and assgin the index as value
        for (int i = 0; i < size; ++i)
            hmap[nums[i]] = i;
        
        for (int i = 0; i < size; ++i){
            int cand2 = target - nums[i];
            if (hmap.count(cand2) != 0){
                if (i < hmap[cand2]){  //if i == hmap[2], means it is the same number, skip
                    retV.push_back(i);
                    retV.push_back(hmap[cand2]);
                    return retV;
                }
                if (i > hmap[cand2]){
                    retV.push_back(hmap[cand2]);
                    retV.push_back(i);
                    return retV;
                }
            }
        }
        return  retV;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> vct = {3,2,4};
    Solution S;
    vector<int> retV = S.twoSum(vct,6);
    return 0;
}
