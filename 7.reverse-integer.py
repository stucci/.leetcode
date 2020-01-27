#
# @lc app=leetcode id=7 lang=python3
#
# [7] Reverse Integer
#

# @lc code=start
class Solution:
    def reverse(self, x: int) -> int:
        if x==0:
            return 0
        nega=False
        if x<0:
            nega=True
            x*=(-1)
        s=str(x)
        rs=s[::-1]
        rs=re.sub(r'^0+',"",rs)
        ret=int(rs)
        if nega:
            ret*=(-1)
        int_max=pow(2,31)
        if ret>int_max-1 or ret<(-1)*int_max:
            return 0
        return ret
# @lc code=end

