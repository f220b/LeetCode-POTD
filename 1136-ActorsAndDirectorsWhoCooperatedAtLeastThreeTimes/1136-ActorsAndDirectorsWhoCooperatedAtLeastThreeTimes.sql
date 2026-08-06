-- Last updated: 8/6/2026, 1:18:43 PM
# Write your MySQL query statement below
SELECT actor_id,director_id
FROM ActorDirector 
GROUP BY actor_id, director_id
HAVING count(timestamp)>=3;