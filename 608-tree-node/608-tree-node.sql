# Write your MySQL query statement below
select id,
(case
    when p_id is NULL then "Root"
    when id = any(select p_id from Tree) then "Inner"
    else "Leaf"
end) as type
from Tree
order by id;
