-- Last updated: 8/6/2026, 1:25:13 PM
delete p1
from Person p1
join Person p2
on p1.email=p2.email and p1.id>p2.id;