CREATE TABLE Customers (
  customer_id INT PRIMARY KEY AUTO_INCREMENT,
  name VARCHAR(50),
  dob DATE,
  city VARCHAR(50),
  account_type VARCHAR(50)
);

CREATE TABLE Branches (
  branch_id INT PRIMARY KEY AUTO_INCREMENT,
  branch_name VARCHAR(50),
  city VARCHAR(50)
);

CREATE TABLE Accounts (
  account_id INT PRIMARY KEY AUTO_INCREMENT,
  customer_id INT,
  FOREIGN KEY (customer_id) REFERENCES Customers(customer_id),
  balance DECIMAL(10,2),
  account_type VARCHAR(50),
  branch_id INT,
  FOREIGN KEY (branch_id) REFERENCES Branches(branch_id)
);

CREATE TABLE Transactions (
  transaction_id INT PRIMARY KEY AUTO_INCREMENT,
  account_id INT,
  FOREIGN KEY (account_id) REFERENCES Accounts(account_id),
  amount DECIMAL(10,2),
  transaction_type VARCHAR(50),
  transaction_date DATE
);

CREATE TABLE Loans (
  loan_id INT PRIMARY KEY AUTO_INCREMENT,
  customer_id INT, 
  FOREIGN KEY (customer_id) REFERENCES Customers(customer_id),
  amount DECIMAL(10,2),
  loan_type VARCHAR(50),
  status VARCHAR(50)
);


DESC Customers;
DESC Branches;
DESC Accounts;
DESC Transactions;
DESC Loans;





INSERT INTO Customers (name, dob, city, account_type) VALUES
('Alice Johnson', '1990-05-15', 'New York', 'Savings'),
('Bob Smith', '1985-08-22', 'Los Angeles', 'Checking'),
('Charlie Brown', '1992-03-10', 'Chicago', 'Savings'),
('David Wilson', '1988-07-19', 'Houston', 'Checking'),
('Emma Davis', '1995-11-25', 'San Francisco', 'Savings'),
('Frank Miller', '1983-09-30', 'Seattle', 'Checking'),
('Grace Lee', '1991-12-12', 'Boston', 'Savings'),
('Henry Adams', '1980-06-21', 'New York', 'Checking'),
('Ivy Watson', '1993-04-17', 'Los Angeles', 'Savings'),
('Jake Turner', '1997-08-05', 'Chicago', 'Checking');


INSERT INTO Branches (branch_name, city) VALUES
('Downtown Branch', 'New York'),
('Westside Branch', 'Los Angeles'),
('North Branch', 'Chicago'),
('South Branch', 'Houston'),
('Central Branch', 'San Francisco'),
('Eastside Branch', 'Seattle'),
('Harbor Branch', 'Boston'),
('Uptown Branch', 'New York'),
('Suburban Branch', 'Los Angeles');


INSERT INTO Accounts (customer_id, balance, account_type, branch_id) VALUES
(1, 15000.00, 'Savings', 1),
(2, 5000.00, 'Checking', 2),
(3, 30000.00, 'Savings', 3),
(4, 4000.00, 'Checking', 4),
(5, 2000.00, 'Savings', 5),
(6, 10000.00, 'Checking', 6),
(7, 24000.00, 'Savings', 7),
(1, 12000.00, 'Checking', 8),
(8, 60000.00, 'Savings', 9),
(9, 500.00, 'Checking', 1);


INSERT INTO Transactions (account_id, amount, transaction_type, transaction_date) VALUES
(1, 1000.00, 'Deposit', '2024-01-15'),
(2, 2000.00, 'Withdrawal', '2024-01-16'),
(3, 3000.00, 'Deposit', '2024-01-17'),
(4, 500.00, 'Withdrawal', '2024-01-18'),
(5, 7000.00, 'Transfer', '2024-02-20'),
(6, 9000.00, 'Deposit', '2024-02-21'),
(7, 2500.00, 'Withdrawal', '2024-03-01'),
(8, 3500.00, 'Deposit', '2024-03-02'),
(9, 1500.00, 'Withdrawal', '2024-03-10'),
(1, 8000.00, 'Deposit', '2024-04-12'), 
(3, 9000.00, 'Transfer', '2023-12-01'), 
(5, 11000.00, 'Deposit', '2024-04-15'),
(6, 4000.00, 'Deposit', '2024-04-18'),
(8, 5000.00, 'Withdrawal', '2024-04-19'),
(9, 6000.00, 'Deposit', '2024-04-20');


INSERT INTO Loans (customer_id, amount, loan_type, status) VALUES
(1, 50000.00, 'Home', 'Approved'),
(2, 25000.00, 'Car', 'Pending'),
(3, 10000.00, 'Personal', 'Approved'),
(4, 15000.00, 'Car', 'Rejected'),
(5, 5000.00, 'Personal', 'Approved'),
(6, 20000.00, 'Home', 'Pending'),
(8, 45000.00, 'Home', 'Approved'),
(10, 30000.00, 'Car', 'Approved'); 


SELECT * FROM Customers;
SELECT * FROM Branches;
SELECT * FROM Accounts;
SELECT * FROM Transactions;
SELECT * FROM Loans;




