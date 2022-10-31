# Write your MySQL query statement below


# SELECT A.Name from Customers A
# WHERE NOT EXISTS (SELECT 1 FROM Orders B WHERE A.Id = B.CustomerId)

# SELECT A.Name from Customers A
# WHERE A.Id NOT IN (SELECT B.CustomerId from Orders B)


# select name Customers from Customers c left join Orders o on c.id=o.customerId where o.customerId is null;

select c.name Customers from Customers c where not exists (select 1 from orders o where c.id=o.CustomerId);

# select c.name from Customers from Customers c where c.id not in (select B.CustomerId from Orders B);