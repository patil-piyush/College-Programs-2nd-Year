CREATE TABLE Courses_220(
  CourseID INT PRIMARY KEY NOT NULL,
  CourseName VARCHAR(100) NOT NULL UNIQUE,
  Credits INT DEFAULT 3
);

CREATE TABLE Students_220 (
  StudentID INT PRIMARY KEY NOT NULL,
  FirstName VARCHAR(50) NOT NULL,
  LastName VARCHAR(50),
  Email VARCHAR(100) UNIQUE,
  DOB DATE NOT NULL,
  CourseID INT,
  FOREIGN KEY (CourseID) REFERENCES Courses_220(CourseID)
);

DESC Courses_220;
DESC Students_220;

INSERT INTO Courses_220 VALUES(101, 'Computer Science', 3);
INSERT INTO Courses_220 VALUES(102, 'Mechanical Engineering', 3);
INSERT INTO Courses_220 VALUES(103, 'Electronics and Communication', 3);
INSERT INTO Courses_220 VALUES(104, 'Civil Engineering', 3);

INSERT INTO Students_220 VALUES(1, 'Amit', 'Sharma', 'amit.sharma@example.com', '1998-07-15', 101);
INSERT INTO Students_220 VALUES(2, 'Priya', 'Verma', 'priya.verma@example.com', '1999-12-20', 102);
INSERT INTO Students_220 VALUES(3, 'Rahul', 'Patel', 'rahul.patel@example.com', '2001-03-25', 103);
INSERT INTO Students_220 VALUES(4, 'Sneha', 'Rao', 'sneha.rao@example.com', '2002-08-10', 104);
INSERT INTO Students_220 VALUES(5, 'Arjun', 'Iyer', 'arjun.iyer@example.com', '2003-05-05', NULL);
INSERT INTO Students_220 VALUES(6,"Piyush","Patil","piyush.patil@gmail.com","2005-09-09",101);

SELECT * FROM Students_220;
SELECT * FROM Courses_220;

-- INSERT INTO Courses_220(CourseID) VALUES(NULL);

-- INSERT INTO Students_220 VALUES(7, 'Sahil', 'Patel', 'rahul.patel@example.com', '1997-02-02', 103);

-- INSERT INTO Students_220 
-- VALUES(7, 'Sahil', 'Patel', 'sahil.patel@example.com', '1997-02-02', 105);


SELECT * FROM Students_220
WHERE DOB > '2000-01-01';

UPDATE Courses_220
SET Credits = 4
WHERE CourseName = "Computer Science";

SELECT * FROM Courses_220;

DELETE FROM Students_220
WHERE Email = "priya.verma@example.com";

-- SELECT * FROM Students_220;

SELECT * FROM Students_220
WHERE CourseID IS NULL;