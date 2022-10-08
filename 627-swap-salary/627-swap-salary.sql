# Write your MySQL query statement below
update Salary set sex = CHAR(ASCII('m')^ASCII('f')^ASCII(sex));