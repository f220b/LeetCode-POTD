-- Last updated: 9/5/2026, 12:26:07 AM
# Write your MySQL query statement below
select
    employee_id,
    if (employee_id%2=1 and name not like 'M%', salary, 0) as bonus
from Employees
order by employee_id;