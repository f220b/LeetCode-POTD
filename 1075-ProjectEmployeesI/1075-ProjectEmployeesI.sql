-- Last updated: 9/5/2026, 12:34:46 AM
# Write your MySQL query statement below
SELECT project_id, ROUND(AVG(e.experience_years), 2) AS average_years
FROM Project p
LEFT JOIN Employee e
ON e.employee_id = p.employee_id
GROUP BY (p.project_id);