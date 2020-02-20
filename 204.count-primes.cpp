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
        int cnt=0;
        for (long long i = 0; i < n; i++) {
            cnt+=is_prime(i);
        }
        return cnt;
    }
    bool is_prime(int num){
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false;
    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}
};
// @lc code=end

