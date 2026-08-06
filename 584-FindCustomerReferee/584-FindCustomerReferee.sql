-- Last updated: 8/6/2026, 1:22:14 PM
# Write your MySQL query statement below
SELECT name
FROM Customer
WHERE referee_id IS NULL OR referee_id != 2;