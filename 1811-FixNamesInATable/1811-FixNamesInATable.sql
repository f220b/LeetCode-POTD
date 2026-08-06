-- Last updated: 8/6/2026, 1:14:15 PM
# Write your MySQL query statement below
select
    user_id,
    concat(upper(substr(name,1,1)), lower(substr(name,2))) as name
from Users
order by user_id;