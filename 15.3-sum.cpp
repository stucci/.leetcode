#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> s;
        sort(nums.begin(), nums.end());
        int i=0,j=0;
        while(i<nums.size()&&j<nums.size()){
            if(nums[i]==nums[j]){
                j++;
            }else{
                if(j-i>=3){
                    nums.erase(nums.begin()+i+3,nums.begin()+j);
                }
                i=j;
                j++;
            }
            if(j==nums.size()&&j-1-i>=3){
                nums.erase(nums.begin()+i+3,nums.begin()+j-1);
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i+1; j < nums.size(); j++) {
                int lo=j+1, hi=nums.size()-1;
                while(hi-lo>=0){
                    int mid=(lo+hi)/2;
                    int sum=nums[i]+nums[j]+nums[mid];
                    if(sum==0){
                        s.insert({nums[i],nums[j],nums[mid]});
                        break;
                    }else if(sum>0){
                        hi=mid-1;
                    }else{
                        lo=mid+1;
                    }
                }
            }
        }
        vector<vector<int>> ret(s.begin(),s.end());
        return ret;
    }
};
// @lc code=end

