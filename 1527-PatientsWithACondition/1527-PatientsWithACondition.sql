-- Last updated: 9/5/2026, 12:29:26 AM
# Write your MySQL query statement below
select
    patient_id,
    patient_name,
    conditions
from Patients
where conditions regexp '(^| )DIAB1'