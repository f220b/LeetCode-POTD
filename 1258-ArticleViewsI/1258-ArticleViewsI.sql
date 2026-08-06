-- Last updated: 8/6/2026, 1:17:59 PM
# Write your MySQL query statement below

select distinct author_id as id from Views
where author_id = viewer_id 
order by id;