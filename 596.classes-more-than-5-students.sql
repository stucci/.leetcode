--
-- @lc app=leetcode id=596 lang=mysql
--
-- [596] Classes More Than 5 Students
--

-- @lc code=start
# Write your MySQL query statement below

select class
from courses
group by class
having count(distinct student) >= 5

-- select c.class
-- from (select distinct * from courses order by student) as c
-- group by c.class
-- having count(c.class) >= 5

-- @lc code=end
