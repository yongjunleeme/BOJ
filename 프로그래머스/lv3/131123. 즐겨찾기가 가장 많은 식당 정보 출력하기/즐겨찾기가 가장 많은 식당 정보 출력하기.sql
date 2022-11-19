select a.food_type, a.rest_id, a.rest_name, a.favorites
from (select max(favorites) max_favorites, food_type from rest_info group by food_type) b
join rest_info a
on a.food_type = b.food_type
where a.favorites = b.max_favorites
order by a.food_type desc;