-- Last updated: 9/5/2026, 12:25:55 AM
# Write your MySQL query statement below
select
    user_id,
    max(time_stamp) as last_stamp
from Logins
where year(time_stamp) = 2020
group by user_id;