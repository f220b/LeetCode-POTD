-- Last updated: 8/6/2026, 1:22:11 PM
SELECT customer_number
FROM Orders
GROUP BY customer_number
ORDER BY COUNT(customer_number) DESC
LIMIT 1;