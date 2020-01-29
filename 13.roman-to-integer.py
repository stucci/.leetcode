#
# @lc app=leetcode id=13 lang=python3
#
# [13] Roman to Integer
#

# @lc code=start
class Solution:
    def romanToInt(self, s: str) -> int:
        roman={ "I":1, "V":5, "X":10, "L":50, "C":100, "D":500, "M":1000 }
        sum=0
        for i in range(len(s)):
            sign=1
            if len(s)-i>=2:
                if ((s[i]=="I" and (s[i+1]=="V" or s[i+1]=="X")) or
                    (s[i]=="X" and (s[i+1]=="L" or s[i+1]=="C")) or
                    (s[i]=="C" and (s[i+1]=="D" or s[i+1]=="M"))):
                    sign=-1
            sum+=(roman[s[i]]*sign)
        return sum
# @lc code=end

