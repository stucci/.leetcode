--
-- @lc app=leetcode id=197 lang=mysql
--
-- [197] Rising Temperature
--

-- @lc code=start
# Write your MySQL query statement below

select w1.id
from Weather w1, Weather w2
where datediff(w1.recordDate, w2.recordDate) = 1 and w1.Temperature > w2.Temperature

-- @lc code=end

