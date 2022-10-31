# Write your MySQL query statement below
# select t.Request_at Day,
#        ROUND((count(IF(t.status!='completed',TRUE,null))/count(*)),2) as 'Cancellation Rate'
# from Trips t where 
# t.Client_Id in (Select Users_Id from Users where Banned='No') 
# and t.Driver_Id in (Select Users_Id from Users where Banned='No')
# and t.Request_at between '2013-10-01' and '2013-10-03'
# group by t.Request_at;

select t.request_at Day,round((count(if(t.status!='completed',true,null))/count(*)),2) as 'Cancellation Rate'
from Trips t where
t.client_id in (select users_id from Users where banned='NO')
and t.driver_id in (select users_id from Users where banned='NO')
and t.request_at between '2013-10-01' and '2013-10-03'
group by t.request_at