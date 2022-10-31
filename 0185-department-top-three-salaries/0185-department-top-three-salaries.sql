# Write your MySQL query statement below

# Select dep.Name as Department, emp.Name as Employee, emp.Salary from Department dep, 
# Employee emp where emp.DepartmentId=dep.Id and 
# (Select count(distinct Salary) From Employee where DepartmentId=dep.Id and Salary>emp.Salary)<3

select dep.name as Department, emp.name as Employee, emp.salary from Department dep,Employee emp
where emp.DepartmentId=dep.id and 
(select count(distinct salary) from Employee where DepartmentId=dep.id and salary > emp.salary) < 3;