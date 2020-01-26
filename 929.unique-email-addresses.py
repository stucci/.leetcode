#
# @lc app=leetcode id=929 lang=python3
#
# [929] Unique Email Addresses
#

# @lc code=start
class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        ret=set()
        for e in emails:
            res = e.split('@')
            res[0]=res[0].replace(".","")
            res[0]=re.sub(r'\+.*$',"", res[0])
            res=res[0]+"@"+res[1]
            print(res)
            ret.add(res)
        return len(ret)
# @lc code=end

