#include <iostream>
#include <string>
using namespace std;

// Global variable for queue size
#define SIZE 20

// Class to store the email details
class Email
{
public:
    string sender;
    string receiver;
    string subject;
    string body;

    // Default constructor
    Email() {}

    // Parameterized constructor
    Email(string s, string r, string sub, string b)
    {
        sender = s;
        receiver = r;
        subject = sub;
        body = b;
    }

    // Display email details
    void display()
    {
        cout << "From: " << sender << ", To: " << receiver
             << ", Subject: " << subject << ", Body: " << body << endl;
    }
};

// Class to manage the email queue using an array
class EmailQueue
{
private:
    Email queue[SIZE]; // Array to store emails
    int front;         // Index of the front of the queue
    int rear;          // Index of the rear of the queue

public:
    // Constructor to initialize an empty queue
    EmailQueue()
    {
        front = 0;
        rear = -1;
    }

    // Check if the queue is full
    bool isFull()
    {
        return (rear + 1) % SIZE == front; // Circular check
    }

    // Check if the queue is empty
    bool isEmpty()
    {
        return front == (rear + 1) % SIZE; // Circular check
    }

    // Enqueue: Add an email to the queue
    void enqueue(Email &email)
    {
        if (isFull())
        {
            cout << "Queue is full. Cannot enqueue email." << endl;
            return;
        }
        rear = (rear + 1) % SIZE; // Circular increment
        queue[rear] = email;
        cout << "Email from " << email.sender << " to " << email.receiver
             << " has been added to the queue." << endl;
    }

    // Dequeue: Remove the email from the front of the queue
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Email from " << queue[front].sender << " to " << queue[front].receiver
             << " has been processed and removed from the queue." << endl;
        front = (front + 1) % SIZE; // Circular increment
    }

    // Display all emails currently in the queue
    void displayAllEmails()
    {
        if (isEmpty())
        {
            cout << "No emails in the queue." << endl;
        }
        else
        {
            cout << "Emails in the queue:" << endl;
            for (int i = 0; i < (rear + 1 + SIZE - front) % SIZE; i++)
            {
                int index = (front + i) % SIZE; // Circular indexing
                cout << i + 1 << ". ";
                queue[index].display();
            }
        }
    }
};

// Function to display the menu
void displayMenu()
{
    cout << "\nMenu:\n";
    cout << "1. Enqueue Email\n";
    cout << "2. Dequeue Email\n";
    cout << "3. Display All Emails\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

// Main function to drive the menu and manage the queue
int main()
{
    EmailQueue emailQueue; // Create an instance of EmailQueue
    int choice;

    while (1)
    {
        displayMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            // Enqueue email
            string sender, receiver, subject, body;
            cout << "Enter sender email: ";
            cin >> sender;
            cout << "Enter receiver email: ";
            cin >> receiver;
            cout << "Enter subject: ";
            cin.ignore();          // To ignore newline character left in the buffer
            getline(cin, subject); // Taking full line input for subject
            cout << "Enter body: ";
            getline(cin, body); // Taking full line input for body

            Email email(sender, receiver, subject, body);
            emailQueue.enqueue(email);
            break;
        }
        case 2:
        {
            // Dequeue email
            emailQueue.dequeue();
            break;
        }
        case 3:
        {
            // Display all emails
            emailQueue.displayAllEmails();
            break;
        }
        case 4:
        {
            // Exit
            cout << "Exiting the program." << endl;
            return 0; // Exit the program
        }
        default:
        {
            cout << "Invalid choice, please try again." << endl;
        }
        }
    }

    return 0;
}
