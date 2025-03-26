
CREATE TABLE Departments (
DepartmentID INT PRIMARY KEY AUTO_INCREMENT,
DeptName VARCHAR(100) UNIQUE NOT NULL,
HOD VARCHAR(100) NOT NULL 
);


CREATE TABLE Students (
StudentID INT PRIMARY KEY AUTO_INCREMENT,
Name VARCHAR(100) NOT NULL,
Age INT CHECK (Age >= 18), 
DepartmentID INT,
CGPA DECIMAL(3,2) CHECK (CGPA BETWEEN 0 AND 10), 
FOREIGN KEY (DepartmentID) REFERENCES Departments(DepartmentID) ON DELETE SET NULL
);



CREATE TABLE Courses (
CourseID VARCHAR(10) PRIMARY KEY, 
CourseName VARCHAR(100) NOT NULL,
DepartmentID INT,
FOREIGN KEY (DepartmentID) REFERENCES Departments(DepartmentID) ON DELETE CASCADE
);

CREATE TABLE Enrollments (
EnrollmentID INT PRIMARY KEY AUTO_INCREMENT,
StudentID INT,
CourseID VARCHAR(10),
Marks INT CHECK (Marks BETWEEN 0 AND 100),
FOREIGN KEY (StudentID) REFERENCES Students(StudentID),
FOREIGN KEY (CourseID) REFERENCES Courses(CourseID),
UNIQUE (StudentID, CourseID) 
);


DESC Departments;
DESC Students;
DESC Enrollments;
DESC Courses;


INSERT INTO Departments (DeptName, HOD) VALUES 
('Computer Sci', 'Dr. Smith'),
('Mechanical Eng', 'Dr. Johnson'),
('Electrical Eng', 'Dr. Brown'),
('Civil Eng', 'Dr. White');

INSERT INTO Students (Name, Age, DepartmentID, CGPA) VALUES 
('Alice', 20, 1, 8.5),
('Bob', 22, 1, 7.2),
('Charlie', 21, 2, 6.8),
('David', 23, 3, 9.1),
('Eve', 20, 4, 7.9),
('Frank', 24, NULL, 5.5),
('Grace', 19, 1, 6.0),
('Hank', 22, 2, 7.5),
('Ivy', 21, 3, 9.1),
('Jack', 23, 4, 8.2);

INSERT INTO Courses (CourseID, CourseName, DepartmentID) VALUES 
('CS101', 'Data Structures', 1),
('CS102', 'Algorithms', 1),
('ME101', 'Thermodynamics', 2),
('EE101', 'Circuits', 3),
('CE101', 'Structural Analysis', 4),
('CS103', 'Databases', 1);

INSERT INTO Enrollments (StudentID, CourseID, Marks) VALUES 
(1, 'CS101', 90),
(1, 'CS102', 75),
(2, 'CS101', 65),
(3, 'ME101', 50),
(4, 'EE101', 88),
(5, 'CE101', 77),
(6, 'CS103', 35),
(7, 'CS101', 80),
(8, 'ME101', 90),
(9, 'EE101', 95),
(10, 'CE101', 85),
(1, 'CS103', 92),
(2, 'CS103', 45),
(8, 'CS101', 78),
(9, 'CS103', 81);


SELECT * FROM Departments;
SELECT * FROM Students;
SELECT * FROM Courses;
SELECT * FROM Enrollments;

SELECT * FROM Students 
WHERE CGPA > (SELECT AVG(CGPA) FROM Students);

SELECT * FROM Students 
WHERE StudentID NOT IN (SELECT DISTINCT StudentID FROM Enrollments);

SELECT * FROM Courses 
WHERE CourseID NOT IN (SELECT DISTINCT CourseID FROM Enrollments);

SELECT DISTINCT S.* FROM Students S
JOIN Enrollments E ON S.StudentID = E.StudentID
JOIN Courses C ON E.CourseID = C.CourseID
JOIN Departments D ON C.DepartmentID = D.DepartmentID
WHERE D.DeptName = 'Computer Sci';


SELECT * FROM Students 
WHERE Age = (SELECT MAX(Age) FROM Students);

SELECT DISTINCT C.* FROM Courses C
JOIN Enrollments E ON C.CourseID = E.CourseID
WHERE E.Marks > 85;

SELECT D.DeptName, MAX(S.CGPA) AS Highest_CGPA FROM Students S
JOIN Departments D ON S.DepartmentID = D.DepartmentID
GROUP BY D.DeptName;

SELECT S.* FROM Students S
JOIN Enrollments E ON S.StudentID = E.StudentID
GROUP BY S.StudentID
HAVING COUNT(E.CourseID) > 1;

SELECT D.DeptName, COUNT(S.StudentID) AS Student_Count FROM Students S
JOIN Departments D ON S.DepartmentID = D.DepartmentID
GROUP BY D.DeptName
ORDER BY Student_Count DESC
LIMIT 1;


SELECT * FROM Students 
WHERE StudentID NOT IN (SELECT DISTINCT StudentID FROM Enrollments);

SELECT S.* FROM Students S
JOIN Enrollments E ON S.StudentID = E.StudentID
WHERE E.Marks < (SELECT AVG(Marks) FROM Enrollments);

SELECT D.DeptName FROM Departments D
JOIN Students S ON D.DepartmentID = S.DepartmentID
WHERE S.CGPA = (SELECT MAX(CGPA) FROM Students);

SELECT D.DeptName, COUNT(S.StudentID) AS Student_Count FROM Students S
JOIN Departments D ON S.DepartmentID = D.DepartmentID
GROUP BY D.DeptName
ORDER BY Student_Count DESC
LIMIT 1;

SELECT C.* FROM Courses C
JOIN Enrollments E ON C.CourseID = E.CourseID
GROUP BY C.CourseID
HAVING MIN(E.Marks) > 70;

SELECT * FROM Students 
WHERE CGPA = (SELECT CGPA FROM Students WHERE Name = 'Alice');


SELECT C.CourseName, COUNT(E.StudentID) AS Enrolled_Students FROM Courses C
JOIN Enrollments E ON C.CourseID = E.CourseID
GROUP BY C.CourseID
ORDER BY Enrolled_Students DESC
LIMIT 1;

SELECT S.* FROM Students S
JOIN Enrollments E ON S.StudentID = E.StudentID
GROUP BY S.StudentID
HAVING COUNT(E.CourseID) > 2;


SELECT S.*, E.Marks, C.CourseName FROM Students S
JOIN Enrollments E ON S.StudentID = E.StudentID
JOIN Courses C ON E.CourseID = C.CourseID
WHERE E.Marks = (SELECT MAX(Marks) FROM Enrollments WHERE CourseID = E.CourseID);

SELECT D.DeptName, AVG(S.CGPA) AS Avg_CGPA FROM Students S
JOIN Departments D ON S.DepartmentID = D.DepartmentID
GROUP BY D.DeptName
ORDER BY Avg_CGPA ASC
LIMIT 1;

SELECT C.CourseName, COUNT(E.StudentID) AS Failed_Students FROM Courses C
JOIN Enrollments E ON C.CourseID = E.CourseID
WHERE E.Marks < 40
GROUP BY C.CourseID
ORDER BY Failed_Students DESC
LIMIT 1;
