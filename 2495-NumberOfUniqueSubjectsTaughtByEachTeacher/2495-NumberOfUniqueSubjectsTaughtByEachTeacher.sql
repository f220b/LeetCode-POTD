-- Last updated: 8/6/2026, 1:09:29 PM
# Write your MySQL query statement below
select
    teacher_id,
    count(distinct subject_id) as cnt
from Teacher
group by teacher_id;