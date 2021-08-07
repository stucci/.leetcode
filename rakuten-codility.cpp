// codilityで気をつけることリスト
// [ ] 空配列
// [ ] edge case 値が0のとき。要素数が1つだけのとき
// [ ] off-by-one error 特に、0のとき
// [ ] overflow check INT_MAXのときにoverflowしないかどうか？
// [ ] limit check limitのチェックはlimitを超えるか、overflowして、0より小さいか？を調べる
// [ ] test caseは多めに。油断しない。

#include <bits/stdc++.h>
using namespace std;

// -----------------------------------------------------------------------------
// LeetCode
// -----------------------------------------------------------------------------

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
        sort(boxTypes.begin(), boxTypes.end(), cmp);
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

// -----------------------------------------------------------------------------
// Codility
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// BinaryGap

int solution(int N){
    bool cnt_start = false;
    int cnt = 0, max_gap = 0;
    while(N){
        if(N%2){
            cnt_start = true;
            max_gap = max(max_gap, cnt);
            cnt = 0;
        }else if(cnt_start){
            cnt++;
        }
        N /= 2;
    }
    return max_gap;
}

// -----------------------------------------------------------------------------
// CyclicRotation

vector<int> solution(vector<int> &A, int K){
    int n = A.size();
    if(n==0) return A;
    K %= n;
    if(K==0) return A;
    vector<int> ret(A.size());
    for(int i = 0; i < n; i++){
        ret[(i + K) % n] = A[i];
    }
    return ret;
}

// -----------------------------------------------------------------------------
// OddOccurrenceInArray

int solution(vector<int> &A){
    int ret = 0;
    for(auto n : A){
        ret ^= n;
    }
    return ret;
}

// -----------------------------------------------------------------------------
// FrogJmp

int solution(int X, int Y, int D){
    return ceil((Y - X) * 1.0 / D);
}

// -----------------------------------------------------------------------------
// PermMissingElem

int solution(vector<int> &A){
    int sum = 0, n = A.size();
    for(auto a : A) sum += a;
    return ((n + 1) * (n + 2)) / 2 - sum;
}

// -----------------------------------------------------------------------------
// TapeEquilibrium

int solution(vector<int> &A){
    int n = A.size();
    vector<int> cumsum(n);
    cumsum[0] = A[0];
    for(int i = 1; i < n; i++){
        cumsum[i] = cumsum[i-1] + A[i];
    }
    int mi = 10000;
    for(int i = 0; i < n - 1; i++){
        mi = min( mi, abs(cumsum[i] - (cumsum[n-1] - cumsum[i])) );
    }
    return mi;
}

// -----------------------------------------------------------------------------
// FrogRiverOne

int solution(int X, vector<int> &A){
    unordered_set<int> leaves;
    for(int i = 0; i < (int)A.size(); i++){
        leaves.insert(A[i]);
        if((int)leaves.size() == X) return i;
    }
    return -1;
}

// -----------------------------------------------------------------------------
// MaxCounters

vector<int> solution(int N, vector<int> &A){
    int maxcnt = 0, base = 0;
    vector<int> ret(N);
    for(auto a : A){
        if(a == N+1){
            base = maxcnt;
        }else{
            ret[a-1] = max(ret[a-1], base) + 1;
            maxcnt = max(maxcnt, ret[a-1]);
        }
    }
    for(auto &n : ret){
        n = max(n, base);
    }
    return ret;
}

// -----------------------------------------------------------------------------
// MissingInteger

int solution(vector<int> &A){
    set<int> s(A.begin(), A.end());
    int prev = 0;
    for(auto n : s){
        if(n <= 0) continue;
        else if(prev + 1 < n) break;
        prev = n;
    }
    return prev + 1;
}

// -----------------------------------------------------------------------------
// PermCheck

int solution(vector<int> &A){
    set<int> s(A.begin(), A.end());
    int first = *s.begin(), last = *(prev(s.end()));
    if(s.size() == A.size() && first == 1 && last == (int)A.size()) return 1;
    return 0;
}

// -----------------------------------------------------------------------------
// CountDiv

int solution(int A, int B, int K){
    if(K==1) return B-A+1;
    int ret = (B/K) - ((A-1)/K);
    if(A==0) ret++;
    return ret;
}

// -----------------------------------------------------------------------------
// GenomicRangeQuery

vector<int> solution(string &S, vector<int> &P, vector<int> &Q){
    vector<vector<int>> presum(S.size()+1, vector<int>(4));
    map<char, int> m;
    m['A'] = 0;
    m['C'] = 1;
    m['G'] = 2;
    m['T'] = 3;
    for(int i = 0; i < (int)S.size(); i++){
        for(int j = 0; j < 4; j++){
            presum[i+1][j] = presum[i][j];
        }
        presum[i+1][m[S[i]]]++;
    }
    vector<int> ret;
    for(int i = 0; i < (int)P.size(); i++){
        for(int j = 0; j < 4; j++){
            int cnt = presum[Q[i]+1][j] - presum[P[i]][j];
            if(cnt > 0) {
                ret.push_back(j+1);
                break;
            }
        }
    }
    return ret;
}

// -----------------------------------------------------------------------------
// MinAvgTwoSlice

int solution(vector<int> &A){
    int curpos = 0, cursum = A[0], minpos = 0;
    double minavg = 100000;
    for(int i = 1; i < A.size(); i++){
        cursum += A[i];
        double curavg = cursum * 1.0 / (i - curpos + 1);
        if(minavg > curavg){
            minavg = curavg;
            minpos = curpos;
        }
        if(cursum > A[i] * (i - curpos + 1)){
            cursum = A[i];
            curpos = i;
        }
    }
    return minpos;
}

// -----------------------------------------------------------------------------
// PassingCars

int solution(vector<int> &A){
    int cnt0 = 0, cnt1 = 0, sum = 0, limit = 1e9;
    for(auto a : A){
        if(a==0){
            sum += (cnt0 * cnt1);
            if(sum > limit || sum < 0) return -1;
            cnt0++;
            cnt1 = 0;
        }else{
            cnt1++;
        }
    }
    sum += (cnt0 * cnt1);
    if(sum > limit || sum < 0) return -1;
    return sum;
}

// -----------------------------------------------------------------------------
// Distinct

int solution(vector<int> &A){
    set<int> s(A.begin(), A.end());
    return s.size();
}

// -----------------------------------------------------------------------------
// MaxProductOfThree

int solution(vector<int> &A){
    sort(A.begin(), A.end());
    int n = A.size();
    return max(A[n-1] * A[n-2] * A[n-3], A[n-1] * A[0] * A[1]);
}

// -----------------------------------------------------------------------------
// NumberOfDiscIntersections

int solution(vector<int> &A){
    vector<pair<int, int>> points; // { pos : flag }
    for(int i = 0; i < (int)A.size(); i++){
        points.push_back({i - A[i], 0});
        if(A[i] < INT_MAX - i)
            points.push_back({i + A[i], 1});
    }
    sort(points.begin(), points.end());
    int cnt = 0, ret = 0, limit = 1e7;
    for(auto p : points){
        if(p.second == 0){
            ret += cnt;
            if(ret > limit) return -1;
            cnt++;
        }else{
            cnt--;
        }
    }
    return ret;
}

// vector<pair<int, int>> のソートは、特に比較関数を用意せずとも、
// firstが同じ場合は、secondの値で昇順にソートしてくれる。

// -----------------------------------------------------------------------------
// Triangle

int solution(vector<int> &A){
    if(A.size() < 3) return 0;
    sort(A.begin(), A.end());
    for(int i = 2; i < (int)A.size(); i++){
        if(A[i-2] > A[i] - A[i-1]) return 1;
    }
    return 0;
}

// -----------------------------------------------------------------------------
// Brackets

int solution(string &S){
    stack<char> stk;
    for(char c : S){
        if(c=='(' || c=='{' || c=='['){
            stk.push(c);
        }else{
            if(stk.empty()) return 0;
            if(c==')'){
                if(stk.top()=='('){
                    stk.pop();
                }else{
                    return 0;
                }
            }else if(c=='}'){
                if(stk.top()=='{'){
                    stk.pop();
                }else{
                    return 0;
                }
            }else{
                if(stk.top()=='['){
                    stk.pop();
                }else{
                    return 0;
                }
            }
        }
    }
    if(stk.size() > 0) return 0;
    return 1;
}

// -----------------------------------------------------------------------------
// Fish

int solution(vector<int> &A, vector<int> &B){
    stack<int> downfish;
    int upfish = 0;
    for(int i = 0; i < (int)A.size(); i++){
        if(B[i] == 1){
            downfish.push(A[i]);
            continue;
        }
        while(!downfish.empty() && downfish.top() < A[i]){
            downfish.pop();
        }
        if(downfish.empty()) upfish++;
    }
    return upfish + downfish.size();
}
