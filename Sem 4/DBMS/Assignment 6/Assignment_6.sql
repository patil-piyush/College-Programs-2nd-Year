CREATE TABLE Customers (
    customer_id INT PRIMARY KEY,
    name VARCHAR(100),
    email VARCHAR(100),
    city VARCHAR(50)
);

CREATE TABLE Orders (
    order_id INT PRIMARY KEY,
    customer_id INT,
    order_date DATE,
    total_amount DECIMAL(10, 2),
    FOREIGN KEY (customer_id) REFERENCES Customers(customer_id)
);

CREATE TABLE Products (
    product_id INT PRIMARY KEY,
    product_name VARCHAR(100),
    category VARCHAR(50),
    price DECIMAL(10, 2)
);

CREATE TABLE Order_Items (
    order_item_id INT PRIMARY KEY,
    order_id INT,
    product_id INT,
    quantity INT,
    subtotal DECIMAL(10, 2),
    FOREIGN KEY (order_id) REFERENCES Orders(order_id),
    FOREIGN KEY (product_id) REFERENCES Products(product_id)
);

CREATE TABLE Sellers (
    seller_id INT PRIMARY KEY,
    seller_name VARCHAR(100),
    city VARCHAR(50)
);

DESC Customers;
DESC Orders;
DESC Products;
DESC Order_Items;
DESC Sellers;


INSERT INTO Customers VALUES
(1, 'John Doe', 'john@example.com', 'New York'),
(2, 'Jane Smith', 'jane@example.com', 'Los Angeles'),
(3, 'Alice Johnson', 'alice@example.com', 'Chicago'),
(4, 'Bob Brown', 'bob@example.com', 'New York'),
(5, 'Charlie Davis', 'charlie@example.com', 'San Francisco');

INSERT INTO Orders VALUES
(1, 1, '2025-03-01', 300.00),
(2, 2, '2025-02-15', 450.00),
(3, 1, '2025-03-05', 150.00),
(4, 3, '2025-01-20', 600.00);

INSERT INTO Products VALUES
(1, 'Laptop', 'Electronics', 1000.00),
(2, 'Phone', 'Electronics', 800.00),
(3, 'Tablet', 'Electronics', 500.00),
(4, 'Headphones', 'Accessories', 100.00),
(5, 'Monitor', 'Electronics', 300.00);

INSERT INTO Order_Items VALUES
(1, 1, 1, 1, 1000.00),
(2, 2, 2, 2, 1600.00),
(3, 3, 3, 1, 500.00),
(4, 4, 4, 3, 300.00),
(5, 4, 5, 1, 300.00);

INSERT INTO Sellers VALUES
(1, 'Best Buy', 'New York'),
(2, 'Amazon', 'Los Angeles'),
(3, 'Walmart', 'Chicago'),
(4, 'Target', 'San Francisco');

CREATE TABLE Product_Sellers (
    seller_id INT,
    product_id INT,
    FOREIGN KEY (seller_id) REFERENCES Sellers(seller_id),
    FOREIGN KEY (product_id) REFERENCES Products(product_id)
);

INSERT INTO Product_Sellers VALUES
(1, 1),
(1, 2),
(2, 1),
(2, 3),
(3, 4),
(4, 5),
(4, 2);


SELECT*FROM Customers;
SELECT*FROM Orders;
SELECT*FROM Products;
SELECT*FROM Order_Items;
SELECT*FROM Sellers;
SELECT*FROM Product_Sellers;


SELECT Customers.customer_id, Customers.name, Orders.order_id, Orders.order_date, Orders.total_amount
FROM Customers
LEFT JOIN Orders ON Customers.customer_id = Orders.customer_id;

SELECT Orders.order_id, Products.product_name, Order_Items.quantity
FROM Order_Items
JOIN Products ON Order_Items.product_id = Products.product_id
JOIN Orders ON Order_Items.order_id = Orders.order_id;

SELECT Customers.customer_id, Customers.name, COUNT(Orders.order_id) AS total_orders
FROM Customers
LEFT JOIN Orders ON Customers.customer_id = Orders.customer_id
GROUP BY Customers.customer_id, Customers.name;

SELECT category, COUNT(*) AS total_products
FROM Products
GROUP BY category;


