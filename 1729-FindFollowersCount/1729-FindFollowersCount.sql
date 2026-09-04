-- Last updated: 9/5/2026, 12:27:47 AM
# Write your MySQL query statement below
select
    user_id,
    count(distinct follower_id) as followers_count
from Followers
group by user_id
order by user_id;