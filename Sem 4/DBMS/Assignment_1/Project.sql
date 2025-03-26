-- Department Table
CREATE TABLE Department (
    Department_ID INT PRIMARY KEY AUTO_INCREMENT,
    Name VARCHAR(100) NOT NULL,
    HoD_ID INT UNIQUE
);

-- User Table
CREATE TABLE User (
    User_ID INT PRIMARY KEY AUTO_INCREMENT,
    Name VARCHAR(100) NOT NULL,
    Role ENUM('Admin', 'Director', 'Dean', 'HoD', 'Coordinator', 'Faculty', 'Student Chapter In-charge', 'Lab Assistant') NOT NULL,
    Email VARCHAR(255) UNIQUE NOT NULL,
    Password VARCHAR(255) NOT NULL,
    Department_ID INT NOT NULL,
    FOREIGN KEY (Department_ID) REFERENCES Department(Department_ID)
);

-- Assign HoD_ID Foreign Key
ALTER TABLE Department ADD CONSTRAINT FK_HoD FOREIGN KEY (HoD_ID) REFERENCES User(User_ID);

-- Budget Table (Without Remaining_Budget)
CREATE TABLE Budget (
    Budget_ID INT PRIMARY KEY AUTO_INCREMENT,
    Department_ID INT NOT NULL,
    Total_Allocated DECIMAL(15,2) NOT NULL,
    Approved_By INT NOT NULL,
    Approval_Date TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (Department_ID) REFERENCES Department(Department_ID),
    FOREIGN KEY (Approved_By) REFERENCES User(User_ID)
);

-- Budget Expenditure Table (To Track Expenses Separately)
CREATE TABLE Budget_Expenditure (
    Expense_ID INT PRIMARY KEY AUTO_INCREMENT,
    Budget_ID INT NOT NULL,
    Amount DECIMAL(15,2) NOT NULL,
    Purpose TEXT NOT NULL,
    FOREIGN KEY (Budget_ID) REFERENCES Budget(Budget_ID)
);

-- Budget Request Table
CREATE TABLE Budget_Request (
    Request_ID INT PRIMARY KEY AUTO_INCREMENT,
    Requested_By INT NOT NULL,
    Department_ID INT NOT NULL,
    Category ENUM('MIS', 'SDW', 'R&D', 'Events', 'Other') NOT NULL,
    Amount DECIMAL(15,2) NOT NULL,
    Status ENUM('Pending', 'Approved', 'Rejected') DEFAULT 'Pending',
    Submitted_Date TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    Approved_By INT NOT NULL,
    FOREIGN KEY (Requested_By) REFERENCES User(User_ID),
    FOREIGN KEY (Department_ID) REFERENCES Department(Department_ID),
    FOREIGN KEY (Approved_By) REFERENCES User(User_ID)
);

-- Approval Flow Table
CREATE TABLE Approval_Flow (
    Approval_ID INT PRIMARY KEY AUTO_INCREMENT,
    Request_ID INT NOT NULL,
    Approved_By INT NOT NULL,
    Approval_Status ENUM('Approved', 'Rejected', 'Pending') DEFAULT 'Pending',
    Approval_Date TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    Remarks TEXT,
    FOREIGN KEY (Request_ID) REFERENCES Budget_Request(Request_ID),
    FOREIGN KEY (Approved_By) REFERENCES User(User_ID)
);

-- Expenditure Approval Flow Table
CREATE TABLE Expenditure_Approval_Flow (
    Approval_ID INT PRIMARY KEY AUTO_INCREMENT,
    Expense_ID INT NOT NULL,
    Approved_By INT NOT NULL,
    Approval_Status ENUM('Approved', 'Rejected', 'Pending') DEFAULT 'Pending',
    Approval_Date TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    Remarks TEXT,
    FOREIGN KEY (Expense_ID) REFERENCES Budget_Expenditure(Expense_ID),
    FOREIGN KEY (Approved_By) REFERENCES User(User_ID)
);

-- Transaction Log Table (No More NULLs, Single Request_ID Column)
CREATE TABLE Transaction_Log (
    Transaction_ID INT PRIMARY KEY AUTO_INCREMENT,
    User_ID INT NOT NULL,
    Request_ID INT NOT NULL,
    Action ENUM('Created', 'Updated', 'Approved', 'Rejected') NOT NULL,
    Timestamp TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (User_ID) REFERENCES User(User_ID),
    FOREIGN KEY (Request_ID) REFERENCES Budget_Request(Request_ID)
);


SELECT * FROM Department;
SELECT * FROM User;
SELECT * FROM Budget_Request;
SELECT * FROM Budget;
SELECT * FROM Approval_Flow;
SELECT * FROM Expenditure_Approval_Flow;
SELECT * FROM Transaction_Log;
