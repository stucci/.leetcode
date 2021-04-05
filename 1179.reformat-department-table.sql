--
-- @lc app=leetcode id=1179 lang=mysql
--
-- [1179] Reformat Department Table
--

-- @lc code=start
# Write your MySQL query statement below

select id, 
	sum(case when month = 'jan' then revenue else null end) as Jan_Revenue,
	sum(case when month = 'feb' then revenue else null end) as Feb_Revenue,
	sum(case when month = 'mar' then revenue else null end) as Mar_Revenue,
	sum(case when month = 'apr' then revenue else null end) as Apr_Revenue,
	sum(case when month = 'may' then revenue else null end) as May_Revenue,
	sum(case when month = 'jun' then revenue else null end) as Jun_Revenue,
	sum(case when month = 'jul' then revenue else null end) as Jul_Revenue,
	sum(case when month = 'aug' then revenue else null end) as Aug_Revenue,
	sum(case when month = 'sep' then revenue else null end) as Sep_Revenue,
	sum(case when month = 'oct' then revenue else null end) as Oct_Revenue,
	sum(case when month = 'nov' then revenue else null end) as Nov_Revenue,
	sum(case when month = 'dec' then revenue else null end) as Dec_Revenue
from department
group by id
order by id

-- select
--     id,
--     sum( if( month = 'Jan', revenue, null ) ) AS Jan_Revenue,
--     sum( if( month = 'Feb', revenue, null ) ) AS Feb_Revenue,
--     sum( if( month = 'Mar', revenue, null ) ) AS Mar_Revenue,
--     sum( if( month = 'Apr', revenue, null ) ) AS Apr_Revenue,
--     sum( if( month = 'May', revenue, null ) ) AS May_Revenue,
--     sum( if( month = 'Jun', revenue, null ) ) AS Jun_Revenue,
--     sum( if( month = 'Jul', revenue, null ) ) AS Jul_Revenue,
--     sum( if( month = 'Aug', revenue, null ) ) AS Aug_Revenue,
--     sum( if( month = 'Sep', revenue, null ) ) AS Sep_Revenue,
--     sum( if( month = 'Oct', revenue, null ) ) AS Oct_Revenue,
--     sum( if( month = 'Nov', revenue, null ) ) AS Nov_Revenue,
--     sum( if( month = 'Dec', revenue, null ) ) AS Dec_Revenue
-- from Department
-- group by id;

-- @lc code=end

-- {
--     "headers": ["id", "Jan_Revenue", "Feb_Revenue", "Mar_Revenue", "Apr_Revenue", "May_Revenue", "Jun_Revenue", "Jul_Revenue", "Aug_Revenue", "Sep_Revenue", "Oct_Revenue", "Nov_Revenue", "Dec_Revenue"],
--     "values": [[1, 8000, 7000, 6000, null, null, null, null, null, null, null, null, null], [2, 9000, null, null, null, null, null, null, null, null, null, null, null], [3, null, 10000, null, null, null, null, null, null, null, null, null, null]]
-- }