set @time := -1;

select (@time := @time + 1) hour,
(select count(*) from animal_outs
where @time = hour(datetime)) count from animal_outs
where @time < 23