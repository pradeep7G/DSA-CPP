# Write your MySQL query statement below

select t1.id from Weather t1 inner join Weather t2 on TO_DAYS(t1.recordDate)=TO_DAYS(t2.recordDate)+1 where t1.temperature > t2.temperature;