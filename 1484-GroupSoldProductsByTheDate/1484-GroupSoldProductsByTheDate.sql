-- Last updated: 9/5/2026, 12:30:08 AM
# Write your MySQL query statement below
select
    sell_date,
    count(distinct product) as num_sold,
    group_concat(
        distinct product
        order by product
        separator ','
    ) as products
from Activities
group by sell_date
order by sell_date asc;