-- Last updated: 8/6/2026, 1:22:01 PM
# Write your MySQL query statement below
SELECT class
FROM Courses
GROUP BY class
HAVING COUNT(class) >= 5;