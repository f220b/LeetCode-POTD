-- Last updated: 9/5/2026, 12:20:45 AM
# Write your MySQL query statement below
select
    teacher_id,
    count(distinct subject_id) as cnt
from Teacher
group by teacher_id;