-- Last updated: 4/3/2026, 2:01:37 PM
# Write your MySQL query statement below
select max(salary) as SecondHighestSalary from Employee where salary<(select max(salary) from Employee);