-- Last updated: 8/6/2026, 1:12:02 PM
select
    e.employee_id
from Employees e
left join Salaries s
on e.employee_id=s.employee_id
where s.salary is null

union

select
    s.employee_id
from Employees e
right join Salaries s
on e.employee_id=s.employee_id
where e.name is null

order by employee_id;