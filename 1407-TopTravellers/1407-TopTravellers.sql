-- Last updated: 9/5/2026, 12:30:49 AM
# Write your MySQL query statement below
SELECT
    name,
    COALESCE(SUM(distance), 0) AS travelled_distance
FROM Users u
LEFT JOIN Rides r
ON u.id = r.user_id
GROUP BY u.id
ORDER BY travelled_distance DESC, u.name ASC;