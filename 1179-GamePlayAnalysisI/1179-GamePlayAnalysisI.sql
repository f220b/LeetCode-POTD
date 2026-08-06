-- Last updated: 8/6/2026, 1:18:23 PM
# Write your MySQL query statement below
select player_id, min(event_date) as first_login
from Activity 
group by player_id