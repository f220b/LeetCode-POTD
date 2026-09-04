-- Last updated: 9/5/2026, 12:28:15 AM
# Write your MySQL query statement below
select tweet_id
from Tweets
where length(content)>15;