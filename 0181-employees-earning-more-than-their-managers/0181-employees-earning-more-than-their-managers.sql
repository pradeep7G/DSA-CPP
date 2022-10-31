# Write your MySQL query statement below
select e.name as Employee from Employee e where e.salary > (select s.salary from Employee s where e.managerId is not NULL and s.id=e.managerId);