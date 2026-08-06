-- Last updated: 8/6/2026, 1:14:55 PM
# Write your MySQL query statement below
select
    patient_id,
    patient_name,
    conditions
from Patients
where conditions regexp '(^| )DIAB1'