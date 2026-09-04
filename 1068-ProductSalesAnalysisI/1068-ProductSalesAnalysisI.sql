-- Last updated: 9/5/2026, 12:34:55 AM
# Write your MySQL query statement below
SELECT p.product_name, s.year, s.price
FROM Sales s
JOIN Product p
ON p.product_id = s.product_id;