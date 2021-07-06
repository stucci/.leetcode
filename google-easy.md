* SubArrayにおける、ここの要素の出現数
  * [［Java/C++/Python］ O(N) Time, O(1) Space - LeetCode Discuss](https://leetcode.com/problems/sum-of-all-odd-length-subarrays/discuss/854184/JavaC%2B%2BPython-O(N)-Time-O(1)-Space)
    要するに、`(n-i)*(i+1)`になる。もはや、覚えておこう。
    偶数長さのsubarrayのみの場合の出現数は上記を単に2で割って、`(n-1)*(i+1)/2`
    奇数長さのsubarrayのみの場合の出現数は上記を+1して2で割って、`((n-1)*(i+1)+1)/2`
    となる。

* Morris traversal とは
  * 数パターン実装があるようだが、以下の説明が一番分かりやすいと思う
  * [Binary Tree Inorder Traversal - LeetCode](https://leetcode.com/problems/binary-tree-inorder-traversal/solution/)
    * しかし、上記は、in-orderのときのmorris-traversal
      morris-traversalはin-orderか、pre-orderかで実装が変わる。
      pre-orderの場合は以下
      [Binary Tree Preorder Traversal - LeetCode](https://leetcode.com/problems/binary-tree-preorder-traversal/solution/)

```cpp
// 501. Find Mode in Binary Search Tree

// approach
// 1. naive count
// 2. morris traversal

// QA
// number of nodes?
// range of val?

// edge cases
// [] -> []
// [1] -> [1]
// [1, 1, 2, 2] -> [1, 2]

class Solution{
public:
    vector<int> findMode(TreeNode* root){
        unordered_map<int, int> m; // {val : count}
        int maxcnt = 0;
        dfs(root, m, maxcnt);
        vector<int> ret;
        for(auto [val, cnt] : m){
            if(cnt == maxcnt) ret.push_back(val);
        }
        return ret;
    }
    void dfs(TreeNode* node, unordered_map<int, int>& m, int& maxcnt){
        if(node==NULL) return;
        m[node->val]++;
        maxcnt = max(maxcnt, m[node->val]);
        dfs(node->left, m, maxcnt);
        dfs(node->right, m, maxcnt);
    }
};

```

```cpp
// 110. Balanced Binary Tree

// approach
// 1. DFS and compare max depth and min depth
// 2. BFS

// QA
// number of nodes?

// edge cases
// [] -> true
//     1
//    /
//   2   -> false
//  /
// 3

// 1. DFS
class Solution{
public:
    bool isBalanced(TreeNode* root){
        if(root == NULL) return true;
        int max_depth = 0, min_depth = INT_MAX;
        dfs(root, 0, max_depth, min_depth);
        return (max_depth - min_depth <= 1);
    }
    void dfs(TreeNode* node, int depth, int& max_depth, int& min_depth){
        if(node == NULL){
            max_depth = max(max_depth, depth);
            min_depth = min(min_depth, depth);
        }else{
            dfs(node->left, depth + 1, max_depth, min_depth);
            dfs(node->right, depth + 1, max_depth, min_depth);
        }
    }
};

// 2. BFS
class Solution{
public:
    bool isBalanced(TreeNode* root){
        queue<pair<TreeNode*, int>> q; // {node, depth}
        int depth = 0, max_depth = 0, min_depth = INT_MAX;
        if(root!=NULL) q.push({root, depth});
        while(!q.empty()){
            auto [node, depth] = q.front();
            q.pop();
            if(node == NULL) {
                max_depth = max(max_depth, depth);
                min_depth = min(min_depth, depth);
                if(max_depth - min_depth > 1) return false;
            }else{
                q.push(root->left, depth + 1);
                q.push(root->right, depth + 1);
            }
        }
        return true;
    }
};

```

```cpp
// 203. Remove Linked List Elements

// approach
// 1. iterative
// 2. recursive

// QA
// range of val?
// number of node?

// edge cases
// [] 1 -> []
// [1], 1 -> []
// [1, 1], 1 -> []
// [1, 1], 2 -> [1, 1]
// [1, 2, 3], 2 -> [1, 3]

class Solution{
public:
    ListNode* removeElements(ListNode* head, int val){
        ListNode* prev = NULL, curr = head;
        while(curr != NULL){
            if(curr->val == val){
                if(prev == NULL) head = curr->next;
                else prev->next = curr->next;
            }else{
                prev = curr;
            }
            curr = curr->next;
        }
        return head;
    }
};

```

```cpp
// 1603. Design Parking System

// approach
// 1. just count car

// QA
// range of small, medium and big?
// Small car can park in big or medium?
// How many is addCar called?

// edge cases
// [0, 0, 0]

class ParkingSystem{
public:
    vector<int> cnt(3);
    ParkingSystem(int big, int medium, int small){
        cnt[0] = big;
        cnt[1] = medium;
        cnt[2] = small;
    }
    bool addCar(int carType){
        if(cnt[carType-1] > 0){
            cnt[carType-1]--;
            return true;
        }else{
            return false;
        }
    }
};

```

```cpp
// 1313. Decomparess Run-Length Encoded List

// approach
// 1. naive

// QA
// range of num?
// size of nums?
// size of nums is even?

// edge cases
// [] -> []
// [1, 0] -> X
// [1, 1] -> [1]
// [1, 3] -> [1, 1, 1]

class Solution{
public:
    vector<int> decompressRLElist(vector<int>& nums){
        vector<int> ret;
        for(int i = 0; i < nums.size(); i+=2){
            ret.insert(ret.end(), nums[i+1], nums[i]);
        }
        return ret;
    }
};

```

```cpp
// 905. Sort Array By Parity

// approach
// 1. define compare function and sort
// 2. deque
// 3. vector (push_back and insert)
// 4. backet sort
// 5. two pointers

// QA
// size of nums?
// range of num?

// edge case
// [] -> []
// [0] -> [0]
// [1, 2] -> [2, 1]
// [1] -> [1]
// [2] -> [2]

// 4. backet sort
class Solution{
public:
    vector<int> sortArrayByParity(vector<int>& nums){
        vector<int> even, odd;
        for(int n : nums){
            if(n%2) odd.push_back(n);
            else even.push_back(n);
        }
        even.insert(even.end(), odd.begin(), odd.end());
        return even;
    }
};

// 5. two pointers
class Solution{
public:
    vector<int> sortArrayByParity(vector<int>& nums){
        int n = nums.size();
        for(int i = 0, j = n - 1; i < j; i++, j--){
            while(i < n && nums[i]%2) i++;
            while(j >= 0 && nums[j]%2 == 0) j--;
            if(i < j) swap(nums[i], nums[j]);
        }
        return nums;
    }
};

```

```cpp
// 346. Moving Average from Data Stream

// approach
// 1. sliding window

// QA
// range of size?
// range of val?

// edge case
// [[1], [0]] -> [null, 0]

class MovingAverage{
public:
    queue<int> win;
    int sum = 0, n = 0;
    MovingAverage(int size){
        n = size;
    }
    double next(int val){
        win.push(val);
        sum += val;
        if(win.size() > n){
            sum -= win.front();
            win.pop();
        }
        return 1.0 * sum / win.size();
    }
};

```

```cpp
// 977. Squares of a Sorted Array

// approach
// 1. square & sort
// 2. sort by abs & square
// 3. two pointer
// 4. binary-search and two pointer

// QA
// range of nums?

// edge cases
// [-4, -1, 0, 3, 10] -> [0, 1, 9, 16, 100]
// [0, 3, 10] -> [0, 9, 100]
// [-4, -1, 0] -> [0, 1, 16]
// [-1, -1, -1] -> [1, 1, 1]
// [-1, -1, -1, 0, 0, 3] -> [0, 0, 1, 1, 1, 9]
// [0] -> [0]
// [] -> []

class Solution{
public:
    vector<int> sortedSquares(vector<int>& nums){
        int n = nums.size();
        auto itr = lower_bound(nums.begin(), nums.end(), 0);
        int right = (itr - nums.begin());
        int left = right - 1;
        vector<int> ret;
        while(left >= 0 || right < n){
            int abs_num_left = left >= 0 ? abs(nums[left]) : INT_MAX;
            int abs_num_right = right < n ? abs(nums[right]) : INT_MAX;
            if(abs_num_left < abs_num_right){
                ret.push_back(abs_num_left * abs_num_left)
                left--;
            }else{
                ret.push_back(abs_num_right * abs_num_right)
                right++;
            }
        }
        return ret;
    }
};

```

```cpp
// 509. Fibonacci Number

// approach
// 1. recursive
// 2. recursive + memo
// 3. dp
// 4. memo

// QA
// range of num?

// edge cases
// 0 -> 0
// 1 -> 1
// 2 -> 1
// 3 -> 2
// 4 -> 3
// 5 -> 5

// 1. recursive
class Solution{
public:
    int fib(int n){
        if(n==0) return 0;
        else if(n==1) return 1;
        return fib(n-1) + fib(n-2);
    }
};

// 2. recursive + memo
class Solution{
public:
    vector<int> memo(31);
    int fib(int n){
        if(n==0) return 0;
        else if(n==1) return 1;
        else if(memo[n]) return memo[n];
        memo[n] = fib(n-1) + fib(n-2);
        return memo[n];
    }
};

// 3. dp
class Solution{
public:
    int fib(int n){
        vector<int> dp(31);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

// 4. memo
class Solution{
public:
    int fib(int n){
        if(n==0) return 0;
        else if(n==1) return 1;
        int f2, f1 = 1, f0 = 0;
        for(int i = 2; i <= n; i++){
            f2 = f1 + f0;
            f0 = f1;
            f1 = f2;
        }
        return f2;
    }
};

```

```cpp
// 258. Add Digits

// approach
// 1. iterative
// 2. recursive
// 3. math

// QA
// num is int?

// edge cases
// 0 -> 0
// 1 -> 1
// 15 -> 6
// 999 -> 9

// 1. iterative
class Solution{
public:
    int addDigits(int num){
        while(num > 9){
            int ret = 0;
            while(num){
                ret += num%10;
                num /= 10;
            }
            ret = num;
        }
        return num;
    }
};

// 2. recursive
class Solution{
public:
    int addDigits(int num){
        while(num > 9){
            num = helper(num);
        }
        return num;
    }
    int helper(int num){
        if(num <= 9) return num;
        return num % 10 + helper(num / 10);
    }
};

```

```cpp
// 1417. Reformat The String

// approach
// make "alpha only vector" and "digit only vector"

// QA
// length of s?

// edge cases
// "" -> ""
// "abc" -> ""
// "abc1" -> ""
// "abc12" -> "a1b2c"
// "123" -> ""
// "123ab" -> "1a2b3"
// "1" -> "1"
// "a" -> "a"

class Solution{
public:
    string reformat(string s){
        vector<char> vecch, vecdi;
        for(char c : s){
            if('a' <= c && c <= 'z') vecch.push_back(c);
            else vecdi.push_back(c);
        }
        if(abs(vecch.size() - vecdi.size()) >= 2) return "";
        string ret;
        if(vecch.size() < vecdi.size()) vecch.swap(vecdi);
        for(char c : vecch){
            ret += c;
            if(vecdi.size()) {
                ret += vecdi.back();
                vecdi.pop_back();
            }
        }
        return ret;
    }
};

```

```cpp
// 1539. Kth Missing Positive Number

// approach
// 1. brute force
// 2. set_difference
// 3. take difference of k

// QA
// size of arr?
// element of arr is int?
// k is int?

// edge cases
// [1] 1 -> 2
// [3, 4, 5] 2 -> 2
// [3, 4, 5] 3 -> 6
// [3, 5, 6] 3 -> 4
// [2, 3, 4, 7, 11] 5 -> 9

class Solution{
public:
    int findKthPositive(vector<int>& arr, int k){
        int prev_n = 0;
        for(int n : arr){
            k -= (n - prev_n + 1);
            if (k <= 0) return n + k - 1;
            prev_n = n;
        }
        return prev_n + k;
    }
};

```

```cpp
// 485. Max Consecutive Ones

// approach
// 1. naive counting

// QA
// length of nums?

// edge cases
// [] -> 0
// [1] -> 1
// [0, 0, 0] -> 0
// [1, 1, 1] -> 3

class Solution{
public:
    int findMaxConsecutiveOnes(vector<int>& nums){
        int maxcnt = 0, cnt = 0;
        for(int n : nums){
            if(n==1){
                cnt++;
            }else{
                maxcnt = max(maxcnt, cnt);
                cnt = 0;
            }
        }
        maxcnt = max(maxcnt, cnt);
        return maxcnt;
    }
};

```

```cpp
// 1089. Duplicate Zeros

// approach
// 1. naive shift (in-place)

// QA
// int?
// size of arr?

// edge cases
// [0] -> [0]
// [] -> []
// [0, 1] -> [0, 0]
// [1, 0, 2, 3, 0, 5, 9] -> [1, 0, 0, 2, 3, 0, 0]

class Solution{
public:
    void duplicateZeros(vector<int>& arr){
        int n = arr.size();
        for(int i=0; i < n - 1; i++){
            if(arr[i]==0){
                for(int j=n-1; j > i; j--){
                    arr[j] = arr[j-1];
                }
                i++;
            }
        }
    }
};

```

```cpp
// 9. Palindrome Number

// approach
// 1. compare by string

// QA
// x is int?
// x includes nagative number

// edge case
// 1 -> true
// 21 -> false
// -1 -> false

class Solution{
public:
    bool isPalindrome(int x){
        string s = to_string(x);
        return s == string(s.rbegin(), s.rend());
    }
};

```

```cpp
// 1576. Replace All ?'s to Avoid Consecutive Repeating Characters

// approach
// 1. naive iterative replace (candidate a,b,c)

// QA
// lenght of s

// edge case
// "" -> ""
// "a" -> "a"
// "?" -> "a"
// "??" -> "ab"

class Solution{
public:
    string modifyString(string s){
        for(int i=0; i<s.size(); i++){
            if(s[i]=='?'){
                for(char ch='a'; ch<='c'; ch++){
                    if(i-1>=0 && s[i-1]==ch) continue;
                    if(i+1<=s.size()-1 && s[i+1]==ch) continue;
                    s[i]=ch;
                    break;
                }
            }
        }
        return s;
    }
};

```

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