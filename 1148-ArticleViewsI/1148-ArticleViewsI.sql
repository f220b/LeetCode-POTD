-- Last updated: 9/5/2026, 12:34:04 AM
# Write your MySQL query statement below

select distinct author_id as id from Views
where author_id = viewer_id 
order by id;