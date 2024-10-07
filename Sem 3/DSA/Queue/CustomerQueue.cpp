#include <iostream>
#include <string>
using namespace std;
const int SIZE = 20;

class Customer
{
    string name;
    long long contact;

public:
    void read()
    {
        cout << "Enter the details of the customer: " << endl;
        cout << "Customer Name: ";
        cin >> name;
        cout << "Customer Contact Number: ";
        cin >> contact;
    }

    void Display()
    {
        cout << "Customer Name: " << name << endl
             << "Customer Contact Number: " << contact << endl;
    }

    string ShowName()
    {
        return name;
    }
};

class Queue
{
    Customer arr[SIZE]; // Array to store customer names
    int front, rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }
    void Insert(); // Add Customer to the queue
    void Delete(); // Remove Customer from the queue
    void display(); // Display the customer queue
    bool isEmpty(); // Check if queue is empty
    bool isFull(); // Check if queue is full
};

bool Queue::isEmpty()
{
    return (front == -1 || front > rear);
}

bool Queue::isFull()
{
    return (rear == SIZE - 1);
}

void Queue::Insert()
{
    if (isFull())
    {
        cout << "Customer list is full!" << endl;
        return;
    }
    else
    {
        if (front == -1)
            front = 0;
        rear = (rear + 1) % SIZE; // Move rear forward
        arr[rear].read();         // Input from user
        cout << "Customer " << arr[rear].ShowName() << " added to the customer list successfully!" << endl;
    }
}

void Queue::Delete()
{
    if (isEmpty())
    {
        cout << "Customer list is empty!" << endl;
        return;
    }
    else
    {
        cout << "Customer " << arr[front].ShowName() << " has been served." << endl;
        front = (front + 1) % SIZE; // Remove the front Customer
    }
}

void Queue::display()
{
    if (isEmpty())
    {
        cout << "Customer list is empty!" << endl;
    }
    else
    {
        cout << "Current Customer List: " << endl;
        for (int i = front; i <= rear; i++)
        {
            cout << i + 1 << "th Customer: " << endl;
            arr[i].Display();
        }
        cout << endl;
    }
}

int main()
{
    Queue q;
    int choice;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Add Customer to List\n";
        cout << "2. Serve Customer\n";
        cout << "3. Display Customer List\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            q.Insert();
            break;
        case 2:
            q.Delete();
            break;
        case 3:
            q.display();
            break;
        case 4:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
