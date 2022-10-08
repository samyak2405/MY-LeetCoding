# Write your MySQL query statement below
select employee_id,if(mod(employee_id,2)=1 and name not like 'M%',salary,0) as bonus
from Employees as e
order by employee_id;