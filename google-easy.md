```cpp
// 415. Add Strings

// approach
// 1. naive

// QA
// range of num1 and range of num2?
// only digits?
// leading zero?

// edge cases
// "" "" -> ""
// "0" "0" -> "0"
// "1" "9" -> "10"
// "99" "3" -> "102"

class Solution{
public:
    string addStrings(string num1, string num2){
        string ret;
        int ca = 0;
        int n1 = num1.size(), n2 = num2.size();
        for(int i=0; i<max(n1, n2); i++){
            int d1 = i<n1 ? num1[n1-1-i] - '0' : 0;
            int d2 = i<n2 ? num2[n2-1-i] - '0' : 0;
            int s = d1 + d2 + ca;
            char c = '0' + s%10;
            ret += c;
            ca = s / 10;
        }
        if(ca) ret += '1';
        return string(ret.rbegin(), ret.rend());
    }
};
```

```cpp
// 844. Backspace String Compare

// approach
// 1. build new string
//    time:O(M+N) space: O(M+N)
// 2. stack
//    time:O(M+N) space: O(M+N)
// 3. two pointer 後ろから比較していって、backspaceが現れたら現れ数分だけ、英文字をskipする。
//    time:O(M+N) space: O(1)
// 4. erase original string
//    time:O(M+N) space: O(1)

// QA
// length of s?
// length of t?

// edge cases
// "a#" "b#" -> true
// "#" "#" -> true
// "#" "" -> true
// "" "" -> true
// "####" "" -> true
// "####a" "a" -> true

class Solution{
public:
    bool backspaceCompare(string s, string t){
        backspace(s);
        backspace(t);
        return s == t;
    }
    void backspace(string& s){
        for(auto itr = s.begin(); itr != s.end();){
            if(*itr=='#'){
                if(itr==s.begin()){
                    itr = s.erase(itr);
                }else{
                    itr = s.erase(prev(itr), itr);
                }
            }else{
                itr++;
            }
        }
    }
};
```

```cpp
// 504. Base 7

// approach
// 1. iterative
// 2. recursive

// QA
// range of num?

// edge cases
// 0 -> "0"
// 7 -> "10"
// -7 -> "-10"

// 1. iterative
class Solution{
public:
    string convertToBase7(int num){
        if(num==0) return "0";
        string ret;
        int tmp = abs(num);
        while(tmp){
            ret = to_string(tmp%7) + ret;
            tmp /= 7;
        }
        if(num<0) ret = "-" + ret;
        return ret;
    }
};

// 2. recursive
class Solution{
public:
    string convertToBase7(int num){
        if(num<0) return '-' + convertToBase7(-num);
        if(num<7) return to_string(num);
        return convertToBase7(num/7) + convertToBase7(num%7);
    }
};
```

```cpp
// 551. Student Attendance Recode I

// approach
// 1. count 'A' and find 'L'
// 2. count 'A' and 'L'
// 3. using Regex

// QA
// length of s?

// edge cases
// ""
// "A"

class Solution{
public:
    bool checkRecord(string s){
        int cntA=0, cntL=0;
        for(char c : s){
            if(c=='A'){
                cntA++;
                cntL=0;
                if(cntA==2) return false;
            }else if(c=='L'){
                cntL++;
                if(cntL==3) return false;
            }else{
                cntL=0;
            }
        }
        return true;
    }
};
```

```cpp
// 374. Guess Number Higher or Lower

// approach
// 1. brute force
// 2. binary-search 数値の上限がINT_MAXに近いときは、(lo+hi)/2がoverflowするので、lo+(hi-lo)/2と工夫しなければならないことに注意

// QA
// range of n?
// pick is valid?

// edge cases
// 1 -> 1

class Solution{
public:
    int guessNumber(int n){
        int lo = 0, hi = n;
        while(hi-lo>1){
            int mi = lo + (hi-lo)/2;
            int ret = guess(mi);
            if(ret == 0) return mi;
            else if(ret>0) lo = mi;
            else hi = mi;
        }
        return hi;
    }
};
```

```cpp
// 228. Summary Ranges

// approach
// 1. naive
// 2. binary-search

// QA
// int?
// nums.length?

// edge cases
// [0,1,2,4,5,7] -> ["0->2","4->5","7"]
// [] -> []
// [1] -> ["1"]

class Solution{
public:
    vector<string> summaryRanges(vector<int>& nums){
        int sidx = 0;
        vector<string> ret;
        for(int i=0; i<nums.size(); i++){
            if(i==nums.size()-1 || nums[i]!=nums[i+1]-1){
                if (sidx==i) ret.push_back(to_string(sidx));
                else ret.push_back(to_string(sidx)+"->"+to_string(i));
                sidx = i+1;
            }
        }
        return ret;
    }
};
```

```cpp
// 680. Valid Palindrome II

//// approach
// 1. naive O(N^2)
// 2. two pointers O(N)
//    2-1. iterative
//    2-2. recursive

//// QA
// s.length?

//// edge cases
// "abca" -> true
// "abcba" -> true
// "abcbad" -> true
// "dabcba" -> true
// "a" -> true
// "" -> ?

class Solution{
public:
    bool validPalindrome(string s){
        int n = s.length();

        bool valid = true;
        bool deleted = false;
        for(int i=0, ri=n-1; i<n/2; i++, ri--){
            if(s[i]!=s[ri]) {
                if(deleted==false && s[i]==s[ri-1]) {
                    ri--;
                    deleted = true;
                }else{
                    valid = false;
                    break;
                }
            }
        }
        if(valid == true) return true;

        valid = true;
        deleted = false;
        for(int i=0, ri=n-1; i<n/2; i++, ri--){
            if(s[i]!=s[ri]) {
                if(deleted==false && s[i+1]==s[ri]) {
                    i++;
                    deleted = true;
                }else{
                    valid = false;
                    break;
                }
            }
        }
        if(valid == true) return true;
        return false;

    }
};
```

leetcodeの拡張機能がうまくworkしないので、ここで解く