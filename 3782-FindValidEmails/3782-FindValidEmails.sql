-- Last updated: 8/6/2026, 1:02:58 PM
# Write your MySQL query statement below
select
    user_id,
    email
from Users
where email regexp '^[a-zA-Z0-9_]+@[a-zA-Z]+\\.com$'
order by user_id;