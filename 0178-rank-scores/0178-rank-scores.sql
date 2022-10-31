# Write your MySQL query statement below
select a.score score,a.rnk `rank` from (select s.*,dense_rank() over(order by score desc) rnk from Scores s) a;