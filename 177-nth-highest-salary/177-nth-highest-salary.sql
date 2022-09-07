CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
declare m INT;
set m = N-1;
  RETURN (
      select distinct salary as getNthHighestSalary
      from Employee
      order by salary desc
      limit m,1
  );
END