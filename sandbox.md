```cpp
// 411. Add Strings

// approach
// 1. naive

// QA
// range of num1 and range of num2?
// only digits?
// leading zero?

// edge cases
// "" "" -> ""
// "0" "0" -> "0"
// "99" "3" -> "102"

class Solution{
public:
    string addStrings(string num1, string num2){
        string ret;
        int ca = 0;
        for(int i=0; i<max(num1.size(), num2.size()); i++){
            // int d1 = num1[i] - '0';
            int d1 = i<num1.size() ? num1[i] - '0' : 0;
            int d2 = i<num2.size() ? num2[i] - '0' : 0;
            int s = d1 + d2 + ca;
            char c = '0' + s%10;
            ret += c;
            ca = s / 10;
        }
        return string(ret.rbegin(), ret.rend());
    }
}
```

```cpp
// 844. Backspace String Compare

// approach
// 1. naive

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
}
```

```cpp
// 504. Base 7

// approach
// 1. naive

// QA
// range of num?

// edge cases
// 0 -> "0"
// 7 -> "10"
// -7 -> "-10"

class Solution{
public:
    string convertToBase7(int num){
        string ret;
        int tmp = abs(num);
        while(tmp>=7){
            ret = to_string(tmp%7) + ret;
            tmp /= 7;
        }
        ret = to_string(num) + ret;
        if(num<0) ret = "-" + ret;
        return ret;
    }
}
```

```cpp
// 551. Student Attendance Recode I

// approach
// 1. naive counting

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
                if(cntA==3) return false;
            }else if(c=='L'){
                cntL++;
                if(cntL==3) return false;
            }else{
                cntL=0;
            }
        }
        return true;
    }
}
```

```cpp
// 374. Guess Number Higher or Lower

// approach
// 1. naive
// 2. binary-search

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
            int mi = (lo+hi)/2;
            int ret = guess(mi);
            if(ret == 0) return mi;
            else if(ret>0) lo = mi;
            else hi = mi;
        }
        return hi;
    }
}
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
}
```

```cpp
// 680. Valid Palindrome II

//// approach
// 1. naive O(N^2)
// 2. two pointers O(N)

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
}
```

leetcodeの拡張機能がうまくworkしないので、ここで解く