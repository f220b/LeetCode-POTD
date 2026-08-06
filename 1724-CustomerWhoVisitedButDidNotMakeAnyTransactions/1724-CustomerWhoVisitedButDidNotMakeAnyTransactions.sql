-- Last updated: 8/6/2026, 1:14:42 PM
# Write your MySQL query statement below
select
    customer_id,
    count(distinct v.visit_id) as count_no_trans
from Visits v
left join Transactions t
on v.visit_id = t.visit_id
where t.transaction_id IS NULL
group by v.customer_id;