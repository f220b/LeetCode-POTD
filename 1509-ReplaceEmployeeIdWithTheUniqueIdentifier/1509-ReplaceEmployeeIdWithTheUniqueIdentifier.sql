-- Last updated: 8/6/2026, 1:16:16 PM
# Write your MySQL query statement below
SELECT 
    eu.unique_id,
    e.name
FROM Employees e
LEFT JOIN EmployeeUNI eu
ON e.id = eu.id;