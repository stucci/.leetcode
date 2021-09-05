#include <bits/stdc++.h>
using namespace std;

// -----------------------------------------------------------------------------
// Codility
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Flags

bool check(vector<int> &peeks, int mid){
    int prev = peeks[0];
    int flags = 1;
    for(int i = 1; i < (int)peeks.size(); i++){
        while(i < (int)peeks.size() && peeks[i] - prev < mid) i++;
        if(i < (int)peeks.size()){
            flags++;
            prev = peeks[i];
        }
    }
    return (flags >= mid);
}

int solution(vector<int> &A){
    int n = A.size();
    if(n <= 2) return 0;

    vector<int> peeks;
    for(int i = 1; i < n - 1; i++){
        if(A[i] > max(A[i - 1], A[i + 1])){
            peeks.emplace_back(i);
        }
    }

    if(peeks.size() <= 2) return peeks.size();

    int lo = 1, hi = peeks.size() + 1;
    while(hi - lo > 1){
        int mid = (hi + lo) / 2;
        if(check(peeks, mid)){
            lo = mid;
        }else{
            hi = mid;
        }
    }
    return lo;
}

// -----------------------------------------------------------------------------
// CountTriangles

int solution(vector<int> &A){
    int n = A.size();
    if(n <= 2) return 0;
    sort(A.begin(), A.end());
    int cnt = 0;
    for(int p = 0; p < n - 2; p++){
        int q = p + 1, r = q + 1;
        while(r < n){
            if(A[p] + A[q] > A[r]){
                cnt += (r-q);
                r++;
            }else{
                q++;
                if(q == r) r++;
            }
        }
    }
    return cnt;
}

// -----------------------------------------------------------------------------
// NailingPlanks

// you can use includes, for example:
#include <map>

int solution(vector<int> &A, vector<int> &B, vector<int> &C){
    int lo = 0, hi = C.size() + 1;
    while(hi - lo > 1){
        int mid = (lo + hi) / 2;
        map<int, int> m;
        for(int i = 0; i < mid; i++){
            m[C[i]]++;
        }
        bool failed = false;
        for(int i = 0; i < (int)A.size(); i++){
            if(m.upper_bound(A[i]-1) == m.upper_bound(B[i])){
                failed = true;
            }
        }
        if(failed){
            lo = mid;
        }else{
            hi = mid;
        }
    }
    if(hi == (int)C.size() + 1) return -1;
    return hi;
}

// -----------------------------------------------------------------------------
// a after b (nomura)

bool solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)
    bool b_occur = false;
    for(auto c : S){
        if(c=='b'){
            b_occur = true;
        }else{
            if(b_occur) return false;
        }
    }
    return true;
}

// -----------------------------------------------------------------------------
// letter occurs twice (nomura)

string solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)
    set<char> s;
    string ret;
    for(auto c : S){
        if(s.count(c)){
            ret = c;
            return ret;
        }else{
            s.insert(c);
        }
    }
    return ret;
}

// -----------------------------------------------------------------------------
// Delete and Get Unique String  (nomura)

int solution(string &S, vector<int> &C) {
    // write your code in C++14 (g++ 6.2.0)
    char prev = '\0';
    int N = S.size(), sum = 0, max_cost = 0, ret = 0;
    for(int i = 0; i < N; i++){
        if(prev == S[i]){
            sum += C[i];
            max_cost = max(max_cost, C[i]);
        }else{
            ret += (sum - max_cost);
            prev = S[i];
            sum = C[i];
            max_cost = C[i];
        }
    }
    ret += (sum - max_cost);
    return ret;
}

// -----------------------------------------------------------------------------
// Cleaning Robot  (nomura)

int solution(vector<string> &R){
    int N = R.size(), M = R[0].size();
    int dir = 0x1; // 0x1: right, 0x10: down, 0x100: left, 0x1000: up
    int x = 0, y = 0;
    vector<vector<int>> vis(N, vector<int>(M, 0));
    bool looped = false;
    while(!looped){
        if(dir == 0x1){
            while(x < M && R[y][x] != 'X'){
                if(vis[y][x] & dir) looped = true;
                vis[y][x] |= dir;
                x++;
            }
            x--;
            dir = 0x10;
        }
        if(dir == 0x10){
            while(y < N && R[y][x] != 'X'){
                if(vis[y][x] & dir) looped = true;
                vis[y][x] |= dir;
                y++;
            }
            y--;
            dir = 0x100;
        }
        if(dir == 0x100){
            while(x >= 0 && R[y][x] != 'X'){
                if(vis[y][x] & dir) looped = true;
                vis[y][x] |= dir;
                x--;
            }
            x++;
            dir = 0x1000;
        }
        if(dir == 0x1000){
            while(y >= 0 && R[y][x] != 'X'){
                if(vis[y][x] & dir) looped = true;
                vis[y][x] |= dir;
                y--;
            }
            y++;
            dir = 0x1;
        }
    }
    int ret = 0;
    for(auto col : vis){
        for(auto cell : col){
            if(cell) ret++;
        }
    }
    return ret;
}