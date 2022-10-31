# Write your MySQL query statement below
# limit clause, nested queries, correlated-queries..

#1
# select s.salary as SecondHighestSalary from Employee s order by s.salary desc limit 1 offset 1;

#2

select max(s.salary) SecondHighestSalary from Employee s where s.salary <> (select max(t.salary) from Employee t);