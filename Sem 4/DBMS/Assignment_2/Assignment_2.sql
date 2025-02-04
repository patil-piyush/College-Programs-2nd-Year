CREATE TABLE Student_220(
  PRN int primary key NOT NULL,
  First_name VARCHAR(50) NOT NULL,
  Last_name VARCHAR(50) NOT NULL,
  Middle_name VARCHAR(50) NULL,
  Year INT NOT NULL,
  Email VARCHAR(100) UNIQUE,
  Age INT NOT NULL,
  Department VARCHAR(100) NOT NULL
);

DESC Student_220;

INSERT INTO Student_220 
VALUES (101,"John","Doe","A",2,"john.doe@example.com",20,"Computer Science");

INSERT INTO Student_220 
VALUES (102,"Jane","Smith","B",1,"jane.smith@example.com",19,"Electronic");

INSERT INTO Student_220 
VALUES (103,"Alice","Johnson",NULL,3,"alice.johnson@example.com",21,"Mechanical");

INSERT INTO Student_220 
VALUES (104,"Brod","Stud","b",2,"brod.stud@example.com",20,"Electronic");

INSERT INTO Student_220 
VALUES (105,"Piyush","Patil","Rajkumar",2,"piyush.patil@example.com",20,"Computer Science");

SELECT * 
FROM Student_220;

UPDATE Student_220
SET Year = 2
WHERE PRN = 102;

DELETE FROM Student_220
WHERE PRN = 103;

ALTER TABLE Student_220 ADD PhoneNumber
VARCHAR(15);

SELECT * 
FROM Student_220;

SELECT DISTINCT Department
FROM Student_220;

SELECT COUNT(DISTINCT Department)
FROM Student_220;

SELECT DISTINCT Year
FROM Student_220;


SELECT DISTINCT Age
FROM Student_220
WHERE Department = "Computer Science";

SELECT DISTINCT First_name
FROM Student_220
WHERE Age < 21;

SELECT *
FROM Student_220
WHERE Year = 3;

SELECT First_name, Last_name, Department
FROM Student_220
WHERE PRN > 101;

SELECT First_name,Email
FROM Student_220
WHERE Department = "Electronic";

SELECT *
FROM Student_220
WHERE Department = "Computer Science" AND Age > 19;

DELETE FROM Student_220;
SELECT*
FROM Student_220;

DROP TABLE Student_220;


