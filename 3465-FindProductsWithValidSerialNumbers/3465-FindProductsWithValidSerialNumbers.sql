-- Last updated: 9/5/2026, 12:09:36 AM
select
    product_id,
    product_name,
    description
from products
where regexp_like(description, '\\bSN[0-9]{4}-[0-9]{4}\\b', 'c')
order by product_id;