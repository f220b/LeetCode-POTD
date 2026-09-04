-- Last updated: 9/5/2026, 12:27:32 AM
# Write your MySQL query statement below
select
    event_day as day,
    emp_id,
    sum(out_time-in_time) as total_time
from Employees
group by emp_id, event_day;