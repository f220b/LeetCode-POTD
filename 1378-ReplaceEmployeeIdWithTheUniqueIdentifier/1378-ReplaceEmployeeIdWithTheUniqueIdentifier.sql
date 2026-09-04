-- Last updated: 9/5/2026, 12:31:22 AM
# Write your MySQL query statement below
SELECT 
    eu.unique_id,
    e.name
FROM Employees e
LEFT JOIN EmployeeUNI eu
ON e.id = eu.id;