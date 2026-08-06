-- Last updated: 8/6/2026, 1:25:39 PM
select 
    distinct num as ConsecutiveNums
from (
    select
        num,
        lag(num) over (order by id) as prev_num,
        lead(num) over (order by id) as next_num
    from Logs
    ) as temp where 
        prev_num=num and
        next_num=num;