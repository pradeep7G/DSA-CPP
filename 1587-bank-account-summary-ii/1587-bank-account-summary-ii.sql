# Write your MySQL query statement below
select 
    name,sum(t.amount) as balance 
from 
    Users u 
join
    Transactions t 
on 
    t.account=u.account
group by 
    u.account
having
    balance>10000;