# Write your MySQL query statement below
# update Salary set sex = CHAR(ASCII('m')^ASCII('f')^ASCII(sex));
# update Salary set sex = if(sex = 'm','f','m');
update Salary set sex = CHAR(ASCII('m')+ASCII('f')-ASCII(sex));