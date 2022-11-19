select year(sales_date) year,
       month(sales_date) month,
       gender,
       count(distinct(a.user_id)) users
from user_info a
join online_sale b
on a.user_id = b.user_id
where gender is not null
group by year, month, gender
order by year asc, month asc, gender asc;