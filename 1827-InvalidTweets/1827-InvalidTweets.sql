-- Last updated: 8/6/2026, 1:14:05 PM
# Write your MySQL query statement below
select tweet_id
from Tweets
where length(content)>15;