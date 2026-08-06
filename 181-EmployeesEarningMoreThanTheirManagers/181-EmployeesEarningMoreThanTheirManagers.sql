-- Last updated: 8/6/2026, 1:25:35 PM
# Write your MySQL query statement below
select
    e1.name as Employee
from Employee e1
join Employee e2
on e1.managerId=e2.id and e1.salary>e2.salary;