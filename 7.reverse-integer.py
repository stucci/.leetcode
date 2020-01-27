#
# @lc app=leetcode id=7 lang=python3
#
# [7] Reverse Integer
#

# @lc code=start
class Solution:
    def reverse(self, x: int) -> int:
        sign=(x>0)-(x<0)
        s=str(x*sign)
        r=s[::-1]
        ret=int(r)
        if ret>2**31-1:
            return 0
        return sign*ret
# @lc code=end

