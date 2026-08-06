-- Last updated: 8/6/2026, 1:16:35 PM
# Write your MySQL query statement below
SELECT
    p.product_name AS product_name,
    SUM(o.unit) AS unit
FROM Products p
JOIN Orders o
ON p.product_id = o.product_id
WHERE o.order_date like '2020-02-%'
GROUP BY p.product_id
HAVING unit >= 100;