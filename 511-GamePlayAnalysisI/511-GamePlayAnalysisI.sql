-- Last updated: 9/5/2026, 12:34:35 AM
# Write your MySQL query statement below
select player_id, min(event_date) as first_login
from Activity 
group by player_id