--
-- @lc app=leetcode id=181 lang=mysql
--
-- [181] Employees Earning More Than Their Managers
--

-- @lc code=start
# Write your MySQL query statement below

select
    a.Name as Employee
from
    Employee as a
join
    Employee as b
    on a.ManagerId = b.id and a.Salary > b.Salary

-- select
--     *
-- from
--     Employee as a
-- join
--     Employee as b

-- {
--     "headers": ["Id", "Name", "Salary", "ManagerId", "Id", "Name", "Salary", "ManagerId"],
--     "values": [
--         [4, "Max", 90000, null, 1, "Joe", 70000, 3],
--         [3, "Sam", 60000, null, 1, "Joe", 70000, 3],
--         [2, "Henry", 80000, 4, 1, "Joe", 70000, 3],
--         [1, "Joe", 70000, 3, 1, "Joe", 70000, 3],
--         [4, "Max", 90000, null, 2, "Henry", 80000, 4],
--         [3, "Sam", 60000, null, 2, "Henry", 80000, 4],
--         [2, "Henry", 80000, 4, 2, "Henry", 80000, 4],
--         [1, "Joe", 70000, 3, 2, "Henry", 80000, 4],
--         [4, "Max", 90000, null, 3, "Sam", 60000, null],
--         [3, "Sam", 60000, null, 3, "Sam", 60000, null],
--         [2, "Henry", 80000, 4, 3, "Sam", 60000, null],
--         [1, "Joe", 70000, 3, 3, "Sam", 60000, null],
--         [4, "Max", 90000, null, 4, "Max", 90000, null],
--         [3, "Sam", 60000, null, 4, "Max", 90000, null],
--         [2, "Henry", 80000, 4, 4, "Max", 90000, null],
--         [1, "Joe", 70000, 3, 4, "Max", 90000, null]
--         ]
-- }


-- @lc code=end

