# Write your MySQL query statement below
# limit clause, nested queries, correlated-queries..

#1
select (select distinct salary
from Employee
order by salary DESC
limit 1 offset 1) as SecondHighestSalary;

# NOTE: can't handle null values, might handle it with extra code like using if else etc.. but can try with nested queries with max aggrigate function.
#2

# select max(s.salary) SecondHighestSalary from Employee s where s.salary <> (select max(t.salary) from Employee t);

# NOTE: max() returns null if no value exists