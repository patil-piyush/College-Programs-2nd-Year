
--creation and displaying of student_220 table
CREATE TABLE Student_220 (
  StudentId int primary key,
  firstname varchar(50),
  lastname varchar(50),
  middlename varchar(50),
  email varchar(50),
  year int, 
  age int,
  dept varchar(50)
);

-- insert
INSERT INTO Student_220(StudentId,firstname,lastname,middlename,email,year,age,dept) VALUES (001,"Piyush","Patil","Rajkumar","piyush.patil231@pccoepune.org",2025,20,"comp");
INSERT INTO Student_220(StudentId,firstname,lastname,middlename,email,year,age,dept) VALUES (002,"ram","Raut","Keshav","ram.Raut23@pccoepune.org",2025,20,"comp");
INSERT INTO Student_220(StudentId,firstname,lastname,middlename,email,year,age,dept) VALUES (003,"sham","Lele","Guru","sham.lele23@pccoepune.org",2025,20,"comp");
INSERT INTO Student_220(StudentId,firstname,lastname,middlename,email,year,age,dept) VALUES (004,"Ghansham","Gurav","ram","ghansham.gurav23@pccoepune.org",2025,20,"comp");
INSERT INTO Student_220(StudentId,firstname,lastname,middlename,email,year,age,dept) VALUES (005,"Omkar","Shinde","sham","omkar.shinde23@pccoepune.org",2025,20,"comp");
INSERT INTO Student_220(StudentId,firstname,lastname,middlename,email,year,age,dept) VALUES (006,"Mohit","Kamat","Dhruv","mohit.Kamat23@pccoepune.org",2025,20,"comp");

-- fetch 
SELECT * FROM Student_220;


--creation and displaying of course_220 table
CREATE TABLE Course_220 (
  CourseId int primary key,
  Coursename varchar(50),
  year int, 
  dept varchar(50)
);

INSERT INTO Course_220(CourseId,Coursename,year,dept) VALUES (111,"DBMS",2025,"comp");
INSERT INTO Course_220(CourseId,Coursename,year,dept) VALUES (112,"ADS",2025,"comp");
INSERT INTO Course_220(CourseId,Coursename,year,dept) VALUES (113,"DTIM",2025,"comp");
INSERT INTO Course_220(CourseId,Coursename,year,dept) VALUES (114,"PDT",2025,"comp");
INSERT INTO Course_220(CourseId,Coursename,year,dept) VALUES (115,"DSA",2025,"comp");
INSERT INTO Course_220(CourseId,Coursename,year,dept) VALUES (116,"IOT",2025,"comp");

SELECT * FROM Course_220;

-- SELECT 
--   StudentId, 
--   firstname, 
--   lastname, 
--   middlename, 
--   email, 
--   year, 
--   age, 
--   dept, 
--   NULL as CourseId, 
--   NULL as Coursename
-- FROM Student_220
-- UNION
-- SELECT 
--   NULL as StudentId, 
--   NULL as firstname, 
--   NULL as lastname, 
--   NULL as middlename, 
--   NULL as email, 
--   year, 
--   NULL as age, 
--   dept, 
--   CourseId, 
--   Coursename
-- FROM Course_220;

-- aggregate functions for student_220 table
SELECT COUNT(*)
FROM Student_220;

SELECT COUNT(*)
FROM Student_220
WHERE StudentId > 3;

SELECT SUM(StudentId)
FROM Student_220;

SELECT SUM(year)
FROM Student_220;

SELECT SUM(age)
FROM Student_220;

SELECT AVG(StudentId)
FROM Student_220;

SELECT AVG(year)
FROM Student_220;

SELECT AVG(age)
FROM Student_220;

SELECT MAX(StudentId)
FROM Student_220;

SELECT MAX(year)
FROM Student_220;

SELECT MAX(age)
FROM Student_220;

SELECT MIN(StudentId)
FROM Student_220;

SELECT MIN(year)
FROM Student_220;

SELECT MIN(age)
FROM Student_220;




-- aggregate functions for course_220 table

SELECT COUNT(*)
FROM Course_220;

SELECT COUNT(*)
FROM Course_220
WHERE CourseId > 113;


SELECT SUM(CourseId)
FROM Course_220;

SELECT SUM(year)
FROM Course_220;

SELECT AVG(CourseId)
FROM Course_220;

SELECT AVG(year)
FROM Course_220;

SELECT MAX(CourseId)
FROM Course_220;

SELECT MAX(year)
FROM Course_220;

SELECT MIN(CourseId)
FROM Course_220;

SELECT MIN(year)
FROM Course_220;

--creating a view from course_220 table
CREATE VIEW CourseData AS
SELECT Coursename
FROM Course_220;

SELECT * FROM CourseData;
