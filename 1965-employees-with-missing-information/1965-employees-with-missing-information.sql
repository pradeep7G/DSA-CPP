# Write your MySQL query statement below
# select employee_id from Employees where employee_id not in (select employee_id from Salaries) union
# select employee_id from Salaries where employee_id not in (select employee_id from Employees) order by employee_id asc;

select sub.employee_id 
from (
 select e.employee_id,name,salary from Employees e left join Salaries as s on e.employee_id=s.employee_id
    union 
select s.employee_id,name,salary from Employees e right join Salaries as s on e.employee_id=s.employee_id
) as sub where sub.name is null or sub.salary is null order by sub.employee_id;