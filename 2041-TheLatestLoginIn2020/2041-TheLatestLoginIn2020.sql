-- Last updated: 8/6/2026, 1:12:32 PM
# Write your MySQL query statement below
select
    user_id,
    max(time_stamp) as last_stamp
from Logins
where year(time_stamp) = 2020
group by user_id;