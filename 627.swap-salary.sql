--
-- @lc app=leetcode id=627 lang=mysql
--
-- [627] Swap Salary
--

-- @lc code=start
# Write your MySQL query statement below

update
    Salary
set
    sex = if (sex = 'm', 'f', 'm')

-- update
--     Salary
-- set
--     sex = case sex
--         when 'm' then 'f'
--         else 'm'
--     end;

-- update
--     Salary
-- set
--     sex = case when sex = 'm' then 'f'
--                when sex = 'f' then 'm'
--                end;

-- @lc code=end

