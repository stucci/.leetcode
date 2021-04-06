--
-- @lc app=leetcode id=183 lang=mysql
--
-- [183] Customers Who Never Order
--

-- @lc code=start
# Write your MySQL query statement below

select Name as Customers
from Customers
left join Orders
    on Customers.Id = Orders.CustomerId
where Orders.Id is null

-- select *
-- from Customers
-- left join Orders
--     on Customers.Id = Orders.CustomerId

-- {
--     "headers": ["Id", "Name", "Id", "CustomerId"],
--     "values":[
--         [1, "Joe", 2, 1],
--         [2, "Henry", null, null],
--         [3, "Sam", 1, 3],
--         [4, "Max", null, null]
--         ]
-- }

-- @lc code=end

