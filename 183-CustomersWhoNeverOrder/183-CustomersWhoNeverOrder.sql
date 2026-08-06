-- Last updated: 8/6/2026, 1:25:29 PM
# Write your MySQL query statement below
select
    c.name as Customers
from Customers c
left join Orders o
on c.id=o.customerId
where o.id is null;