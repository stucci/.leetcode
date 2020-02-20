#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 */

// @lc code=start
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n);
        for (long long i = 2; i < n; i++) {
            isPrime[i]=true;
        }
        for (long long i = 2; i*i < n; i++) {
            if(!isPrime[i]) continue;
            for (long long j = i*i; j < n; j+=i) {
                isPrime[j]=false;
            }
        }
        int cnt=0;
        for (long long i = 2; i < n; i++) {
            cnt+=isPrime[i];
        }
        return cnt;
    }
};
// @lc code=end

