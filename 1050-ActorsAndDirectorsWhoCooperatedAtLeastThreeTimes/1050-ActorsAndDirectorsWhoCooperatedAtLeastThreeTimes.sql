-- Last updated: 9/5/2026, 12:34:58 AM
# Write your MySQL query statement below
SELECT actor_id,director_id
FROM ActorDirector 
GROUP BY actor_id, director_id
HAVING count(timestamp)>=3;