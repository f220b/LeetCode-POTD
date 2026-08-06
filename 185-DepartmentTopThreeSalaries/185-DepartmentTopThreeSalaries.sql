-- Last updated: 8/6/2026, 1:25:23 PM
# Write your MySQL query statement below
select Department, Employee, Salary 
from (
    select
        d.name as Department,
        e.name as Employee,
        e.salary as Salary,
    dense_rank() over (partition by d.id order by e.salary desc) as rnk
    from Employee e
    join Department d
    on e.departmentId=d.id
) as rnk_table
where rnk <= 3;