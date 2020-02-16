#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 */

// @lc code=start
template<class T>inline T gcd(T a,T b){if(b==0)return a; return(gcd(b,a%b));}
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k%=n;
        if(k==0) return;
        int tmp1;
        int tmp2=nums[0];
        int g=gcd(n,k);
        if(g!=1){
            for (int j = 0; j < g; j++) {
                int tmp2=nums[j];
                for (int i = 0; i < n/g; i++) {
                    int next_idx=((i+1)*k+j)%n;
                    tmp1=nums[next_idx];
                    nums[next_idx]=tmp2;
                    tmp2=tmp1;
                }
            }
        }else{
            for (int i = 0; i < n; i++) {
                int next_idx=((i+1)*k)%n;
                tmp1=nums[next_idx];
                nums[next_idx]=tmp2;
                tmp2=tmp1;
            }
        }
    }
};
// @lc code=end

