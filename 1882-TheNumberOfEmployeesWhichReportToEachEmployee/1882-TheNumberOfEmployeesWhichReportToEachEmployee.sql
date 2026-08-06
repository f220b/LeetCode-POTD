-- Last updated: 8/6/2026, 1:13:40 PM
# Write your MySQL query statement below
select
    e1.employee_id,
    e1.name,
    count(distinct e2.employee_id) as reports_count,
    round(avg(e2.age), 0) as average_age
from Employees e1
join Employees e2
on e1.employee_id=e2.reports_to
where e2.employee_id is not null
group by e1.employee_id;