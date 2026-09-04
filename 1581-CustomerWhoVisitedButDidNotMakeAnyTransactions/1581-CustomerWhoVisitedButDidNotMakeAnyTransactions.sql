-- Last updated: 9/5/2026, 12:29:07 AM
# Write your MySQL query statement below
select
    customer_id,
    count(distinct v.visit_id) as count_no_trans
from Visits v
left join Transactions t
on v.visit_id = t.visit_id
where t.transaction_id IS NULL
group by v.customer_id;