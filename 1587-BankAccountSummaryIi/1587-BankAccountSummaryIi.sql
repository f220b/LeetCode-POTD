-- Last updated: 9/5/2026, 12:29:00 AM
# Write your MySQL query statement below
select
    u.name,
    sum(t.amount) as balance
from Users u
left join Transactions t
on u.account = t.account
group by u.account
having balance > 10000;