-- Last updated: 8/6/2026, 1:25:32 PM
# Write your MySQL query statement below
select email
from Person
group by email
having count(id)>1;