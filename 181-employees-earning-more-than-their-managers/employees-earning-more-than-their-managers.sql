# Write your MySQL query statement below
select e.Name as Employee from Employee e join Employee m on e.managerId=m.Id where e.Salary>m.Salary;