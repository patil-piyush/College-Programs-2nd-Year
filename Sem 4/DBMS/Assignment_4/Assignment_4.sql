-- Creating Customers Table
CREATE TABLE Customers_220 (
    customer_id INT PRIMARY KEY,
    name VARCHAR(50),
    email VARCHAR(100),
    city VARCHAR(50),
    age INT
);

-- Inserting data into Customers
INSERT INTO Customers_220 VALUES 
(1, 'Alice Johnson', 'alice@example.com', 'New York', 28),
(2, 'Bob Smith', 'bob@example.com', 'Los Angeles', 35),
(3, 'Charlie Brown', 'charlie@example.com', 'Chicago', 22),
(4, 'David Lee', 'david@example.com', 'Houston', 40),
(5, 'Eve Adams', 'eve@example.com', 'Miami', 30),
(6, 'Frank White', 'frank@example.com', 'Seattle', 27);

-- Creating Orders Table
CREATE TABLE Orders_220 (
    order_id INT PRIMARY KEY,
    customer_id INT,
    order_date DATE,
    total_amount DECIMAL(10,2),
    status VARCHAR(20),
    FOREIGN KEY (customer_id) REFERENCES Customers_220(customer_id)
);

-- Inserting data into Orders
INSERT INTO Orders_220 VALUES 
(101, 1, '2024-02-01', 150.50, 'Shipped'),
(102, 2, '2024-02-02', 75.00, 'Pending'),
(103, 3, '2024-02-03', 220.75, 'Delivered'),
(104, 4, '2024-02-04', 90.25, 'Cancelled'),
(105, 5, '2024-02-05', 180.40, 'Shipped'),
(106, 6, '2024-02-06', 125.60, 'Processing');

-- Creating Products Table
CREATE TABLE Products_220 (
    product_id INT PRIMARY KEY,
    name VARCHAR(50),
    category VARCHAR(50),
    price DECIMAL(10,2),
    stock INT
);

-- Inserting data into Products
INSERT INTO Products_220 VALUES 
(201, 'Laptop', 'Electronics', 800.00, 10),
(202, 'Smartphone', 'Electronics', 500.00, 15),
(203, 'Headphones', 'Accessories', 100.00, 30),
(204, 'Backpack', 'Bags', 50.00, 25),
(205, 'Wristwatch', 'Fashion', 150.00, 20),
(206, 'Bookshelf', 'Furniture', 200.00, 5);

-- Creating Order_Items Table
CREATE TABLE Order_Items_220 (
    order_item_id INT PRIMARY KEY,
    order_id INT,
    product_id INT,
    quantity INT,
    subtotal DECIMAL(10,2),
    FOREIGN KEY (order_id) REFERENCES Orders_220(order_id),
    FOREIGN KEY (product_id) REFERENCES Products_220(product_id)
);

-- Inserting data into Order_Items
INSERT INTO Order_Items_220 VALUES 
(301, 101, 201, 1, 800.00),
(302, 102, 202, 2, 1000.00),
(303, 103, 203, 1, 100.00),
(304, 104, 204, 3, 150.00),
(305, 105, 205, 1, 150.00),
(306, 106, 206, 2, 400.00);


SELECT * FROM Customers_220;
SELECT * FROM Orders_220;
SELECT * FROM Products_220;
SELECT * FROM Order_Items_220;

-- QUE 1
SELECT total_amount FROM Orders_220
WHERE customer_id = 3;


SELECT SUM(total_amount) AS total_spent
FROM Orders_220
WHERE customer_id = 3;


-- QUE 2
SELECT SUM(total_amount) AS total_revenue
FROM Orders_220;


SELECT product_id, name, price * stock AS total_value 
FROM Products_220;


SELECT * FROM Customers_220
WHERE age>30 AND city = "New York";

SELECT * FROM Customers_220
JOIN Orders_220 ON Orders_220.customer_id = Customers_220.customer_id
WHERE Customers_220.city = "Los Angeles" OR Orders_220.total_amount > 500;

SELECT * FROM Products_220
WHERE stock > 0 AND price < 50;

SELECT * FROM Products_220
WHERE stock < 5;


SELECT * FROM Orders_220
WHERE status != "Delivered";

SELECT * FROM Products_220
WHERE category = "Electronics" OR stock = 0;


SELECT email 
FROM Customers_220 
WHERE email LIKE '%@gmail.com';

SELECT name 
FROM Products_220 
WHERE NAME LIKE '%phone';

SELECT * 
FROM Customers_220
WHERE name LIKE '_____';

SELECT name 
FROM Products_220 
WHERE name LIKE '%Laptop' OR name LIKE '%Tablet';

SELECT * FROM Orders_220
WHERE YEAR(order_date) = 2024;

SELECT * FROM Customers_220
WHERE city = "New York" OR city = "Los Angeles" OR city = "Chicago";


SELECT * FROM Products_220
WHERE category != "Electronics" OR category != "Fashion";









