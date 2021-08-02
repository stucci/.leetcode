#include <bits/stdc++.h>
using namespace std;

// -----------------------------------------------------------------------------
// 53. Maximum Subarray

class Solution{
public:
    vector<int> maxSubArray(vector<int>& nums){
        int cur = nums[0], ret = nums[0];
        for(auto n : nums){
            cur = max(n, n + cur);
            ret = max(ret, cur);
        }
        return ret;
    }
};

// -----------------------------------------------------------------------------
// 1822. Sign of the Product of an Array

class Solution{
public:
    int arraySign(vector<int>& nums){
        int cnt = 0;
        for(auto n : nums){
            if(n == 0) return 0;
            if(n < 0) cnt++;
        }
        if(cnt%2) return -1;
        return 1;
    }
};

// -----------------------------------------------------------------------------
// 1710. Maximum Units on a Truck

class Solution{
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize){
        auto cmp = [](const vector<int> a, const vector<int> b){ return a[1] > b[1]; };
        sort(boxTypes.bigin(), boxTypes.end(), cmp);
        int sum = 0;
        for(auto box : boxTypes){
            if(truckSize >= box[0]){
                sum += box[0] * box[1];
                truckSize -= box[0];
            }else{
                sum += truckSize * box[1];
                truckSize = 0;
            }
            if(truckSize <= 0) break;
        }
        return sum;
    }
};

// いつも比較関数の演算子で迷うが、以下の法則なので覚えておこう
//
// auto cmp = [](const int a, const int b){return a < b; };
// 演算子が < なら昇順。つまり、小さい順。
// つまり、a < b < c < d < etc... のように、「< 演算子と同じ順番で並ぶ」と覚えておく
//
// auto cmp = [](const int a, const int b){return a > b; };
// 演算子が > なら降順。つまり、大きい順。
// つまり、a > b > c > d > etc... のように、「> 演算子と同じ順番で並ぶ」と覚えておく

// -----------------------------------------------------------------------------
// 67. Add Binary

class Solution{
public:
    string addBinary(string a, string b){
        int na = a.length(), nb = b.length();
        string ret;
        int carry = 0;
        for(int i = 1; i <= na || i <= nb; i++){
            int da = (i <= na) ? a[na-i] - '0' : 0;
            int db = (i <= nb) ? b[nb-i] - '0' : 0;
            int s = da + db + carry;
            ret = to_string(s%2) + ret;
            carry = s/2;
        }
        if(carry) ret = to_string(s%2) + ret;
        return ret;
    }
};

// -----------------------------------------------------------------------------
// 953. Verifying an Alien Dictionary

class Solution{
public:
    bool isAlienSorted(vector<string>& words, string order){
        unordered_map<char, char> table;
        for(int i = 0; i < order.length(); i++){
            table[order[i]] = 'a' + i;
        }
        for(auto w : words){
            for(int i = 0; i < w.size(); i++){
                w[i] = table[w[i]];
            }
        }
        for(int i = 0; i + 1 < words.size(); i++){
            if(words[i] > words[i+1]) return false;
        }
        return true;
    }
};

// -----------------------------------------------------------------------------
// 852. Peak Index in a Mountain Array

class Solution{
public:
    int peakIndexInMountainArray(vector<int>& arr){
        int lo = 0, hi = arr.size()-1;
        while(hi - lo > 1){
            int mid = lo + (hi - lo) / 2;
            if(arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1]) return mid;
            if(arr[mid] < arr[mid+1]) lo = mid;
            else hi = mid;
        }
        return 0;
    }
};

// -----------------------------------------------------------------------------
// 884. Uncommon Words from Two Sentences

class Solution{
public:
    vector<string> uncommonFromSentences(string s1, string s2){
        unordered_map<string, int> words; // { word : count }
        split(words, s1);
        split(words, s2);
        vector<string> ret;
        for(auto [w, cnt] : words){
            if(cnt == 1) ret.push_back(w);
        }
        return ret;
    }
    void split(unordered_map<string, int>& words, string& s){
        for(int i = 0, j = 0; j < s.size(); j++){
            if(s[j] == ' ' || j == s.size() - 1){
                string w = s.substr(i, j - i);
                words[w]++;
                i = j+1;
            }
        }
    }
};

// -----------------------------------------------------------------------------
// 278. First Bad Version

class Solution{
public:
    int firstBadVersion(int n){
        int lo = -1, hi = n+1;
        while(hi - lo > 1){
            int mid = lo + (hi - lo) / 2;
            if(isBadVersion(mid)) hi = mid;
            else lo = mid;
        }
        return hi;
    }
};
