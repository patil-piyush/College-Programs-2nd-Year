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


SELECT Orders.order_id, Customers.name, Orders.total_amount
FROM Orders
JOIN Customers ON Orders.customer_id = Customers.customer_id
WHERE Orders.order_date >= CURDATE() - INTERVAL 30 DAY;


SELECT Sellers.seller_name
FROM Sellers
JOIN Product_Sellers ON Sellers.seller_id = Product_Sellers.seller_id
JOIN Products ON Product_Sellers.product_id = Products.product_id
WHERE Products.product_name = 'Laptop';


SELECT Customers.customer_id, Customers.name
FROM Customers
LEFT JOIN Orders ON Customers.customer_id = Orders.customer_id
WHERE Orders.order_id IS NULL;

SELECT *
FROM Orders
WHERE total_amount > (SELECT AVG(total_amount) FROM Orders);

SELECT customer_id, COUNT(order_id) AS total_orders
FROM Orders
GROUP BY customer_id
HAVING COUNT(order_id) >= 2;

SELECT Products.product_name, SUM(Order_Items.quantity) AS total_quantity
FROM Order_Items
JOIN Products ON Order_Items.product_id = Products.product_id
GROUP BY Products.product_name
ORDER BY total_quantity DESC
LIMIT 3;

SELECT Products.product_name
FROM Product_Sellers
JOIN Products ON Product_Sellers.product_id = Products.product_id
GROUP BY Products.product_name
HAVING COUNT(DISTINCT Product_Sellers.seller_id) > 1;

SELECT Sellers.seller_id, Sellers.seller_name
FROM Sellers
LEFT JOIN Product_Sellers ON Sellers.seller_id = Product_Sellers.seller_id
WHERE Product_Sellers.product_id IS NULL;


SELECT Products.product_id, Products.product_name
FROM Products
LEFT JOIN Order_Items ON Products.product_id = Order_Items.product_id
WHERE Order_Items.order_item_id IS NULL;

SELECT Customers.name, COUNT(Orders.order_id) AS total_orders
FROM Customers
JOIN Orders ON Customers.customer_id = Orders.customer_id
GROUP BY Customers.name
ORDER BY total_orders DESC
LIMIT 1;

SELECT Orders.customer_id, Customers.name, COUNT(DISTINCT Order_Items.product_id) AS product_count
FROM Orders
JOIN Order_Items ON Orders.order_id = Order_Items.order_id
JOIN Customers ON Orders.customer_id = Customers.customer_id
GROUP BY Orders.customer_id, Customers.name
HAVING COUNT(DISTINCT Order_Items.product_id) > 5;

SELECT Products.product_id, Products.product_name
FROM Products
JOIN Product_Sellers ON Products.product_id = Product_Sellers.product_id
GROUP BY Products.product_id, Products.product_name
HAVING COUNT(DISTINCT Product_Sellers.seller_id) > 1
AND NOT EXISTS (
    SELECT 1 
    FROM Order_Items
    WHERE Order_Items.product_id = Products.product_id
);

SELECT Customers.customer_id, Customers.name, SUM(Orders.total_amount) AS total_spent
FROM Customers
JOIN Orders ON Customers.customer_id = Orders.customer_id
GROUP BY Customers.customer_id, Customers.name
ORDER BY total_spent DESC
LIMIT 1;


SELECT customer_id, name
FROM Customers
WHERE customer_id IN (SELECT customer_id FROM Orders)
UNION
SELECT customer_id, name
FROM Customers
WHERE city IN (SELECT city FROM Sellers);

SELECT product_id, product_name
FROM Products
WHERE product_id IN (SELECT product_id FROM Product_Sellers)
UNION
SELECT product_id, product_name
FROM Products
WHERE product_id IN (SELECT product_id FROM Order_Items);

SELECT product_id, product_name
FROM Products
WHERE product_id IN (SELECT product_id FROM Order_Items)
AND product_id IN (SELECT product_id FROM Product_Sellers);

SELECT customer_id, name
FROM Customers
WHERE customer_id IN (SELECT customer_id FROM Orders)
AND city IN (SELECT city FROM Sellers);

SELECT Customers.customer_id, Customers.name
FROM Customers
WHERE NOT EXISTS (
    SELECT DISTINCT YEAR(Orders.order_date)
    FROM Orders
    WHERE NOT EXISTS (
        SELECT 1 FROM Orders
        WHERE Orders.customer_id = Customers.customer_id
        AND YEAR(Orders.order_date) = YEAR(Orders.order_date)
    )
);
