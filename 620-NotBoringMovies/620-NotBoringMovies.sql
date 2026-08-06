-- Last updated: 8/6/2026, 1:21:47 PM
# Write your MySQL query statement below
SELECT *
FROM Cinema
WHERE id%2=1 AND description!='boring'
ORDER BY rating DESC;