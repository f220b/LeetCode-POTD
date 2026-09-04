-- Last updated: 9/5/2026, 12:27:40 AM
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