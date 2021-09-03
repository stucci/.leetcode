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
    for(int i = 1; i < peeks.size(); i++){
        while(i < peeks.size() && peeks[i] - prev < mid) i++;
        flags++;
        prev = peeks[i];
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

    int lo = 1, hi = peeks.size();
    whiel(hi - lo > 1){
        int mid = (hi + lo) / 2;
        if(check(peeks, mid)){
            lo = mid;
        }else{
            hi = mid;
        }
    }
    return hi;
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
                r++;
                cnt++;
            }else{
                q++;
                if(q < r && A[p] + A[q] > A[r]) cnt++;
            }
            if(q == r) r++;
        }
    }
    return cnt;
}

// -----------------------------------------------------------------------------
// NailingPlanks

int solution(vector<int> &A, vector<int> &B, vector<int> &C){
    int lo = 0, hi = C.size();
    while(hi - lo > 1){
        int mid = (lo + hi) / 2;
        map<int, int> m;
        for(int i = 0; i < mid; i++){
            m[C[i]]++;
        }
        bool failed = false;
        for(int i = 0; i < A.size(); i++){
            if(m.upper_bound(A[i]) == m.upperbound(B[i])){
                failed = true;
            }
        }
        if(failed){
            lo = mid;
        }else{
            hi = mid;
        }
    }
    if(hi == C.size()) return -1;
    return hi;
}
