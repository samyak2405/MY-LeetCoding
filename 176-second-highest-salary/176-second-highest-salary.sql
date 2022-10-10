select (select distinct salary
       from Employee
       order by Salary DESC
       limit 1 offset 1) as SecondHighestSalary;