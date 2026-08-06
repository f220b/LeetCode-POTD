-- Last updated: 8/6/2026, 1:21:43 PM
# Write your MySQL query statement below
UPDATE Salary SET sex =
CASE sex
    WHEN 'm' THEN 'f'
    ELSE 'm'
END;