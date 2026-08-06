-- Last updated: 8/6/2026, 1:18:39 PM
# Write your MySQL query statement below
SELECT p.product_name, s.year, s.price
FROM Sales s
JOIN Product p
ON p.product_id = s.product_id;