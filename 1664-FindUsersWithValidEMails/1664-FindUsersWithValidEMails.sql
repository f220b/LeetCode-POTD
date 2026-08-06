-- Last updated: 8/6/2026, 1:15:00 PM
# Write your MySQL query statement below
select
    user_id,
    name,
    mail
from Users
where 
    mail regexp '^[a-zA-Z][a-zA-Z0-9_.-]*@leetcode\\.com$'
    and mail LIKE BINARY '%@leetcode.com';