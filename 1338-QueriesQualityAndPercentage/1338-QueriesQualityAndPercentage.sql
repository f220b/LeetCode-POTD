-- Last updated: 8/6/2026, 1:17:33 PM
# Write your MySQL query statement below
select
    query_name,
    round(avg(cast(rating as decimal) / position), 2) as quality,
    round(sum(case when rating < 3 then 1 else 0 end) * 100 / count(*), 2) as poor_query_percentage
from queries
group by query_name;