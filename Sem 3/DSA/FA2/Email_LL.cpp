#include <iostream>
#include <string>
using namespace std;

// Class to store the email details and act as a node in the linked list
class Email {
public:
    string sender;
    string receiver;
    string subject;
    string body;
    Email* next; // Pointer to the next email (acting as a node)

    // Default constructor
    Email(){
        next = nullptr;
    }

    // Parameterized constructor
    Email(string s, string r, string sub, string b){
        sender = s;
        receiver = r;
        subject = sub;
        body = b;
        next = nullptr;
    }

    // Display email details
    void display(){
        cout << "From: " << sender << ", To: " << receiver
             << ", Subject: " << subject << ", Body: " << body << endl;
    }
};

// Class to manage the email queue using a linked list
class EmailQueue {
private:
    Email* front; // Front of the queue (for dequeue)
    Email* rear;  // Rear of the queue (for enqueue)

public:
    // Constructor to initialize an empty queue
    EmailQueue(){
        front = nullptr;
        rear = nullptr;
    }

    // Enqueue: Add an email to the queue
    void enqueue(Email& email) {
        Email* newNode = new Email(email);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Email from " << email.sender << " to " << email.receiver
             << " has been added to the queue." << endl;
    }

    // Dequeue: Remove the email from the front of the queue
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty." << endl;
            return;
        }
        Email* temp = front;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        cout << "Email from " << temp->sender << " to " << temp->receiver
             << " has been processed and removed from the queue." << endl;

        delete temp;
    }

    // Display all emails currently in the queue
    void displayAllEmails() {
        if (front == nullptr) {
            cout << "No emails in the queue." << endl;
        } else {
            Email* temp = front;
            int index = 1;
            cout << "Emails in the queue:" << endl;
            while (temp != nullptr) {
                cout << index++ << ". ";
                temp->display();
                temp = temp->next;
            }
        }
    }
};

// Function to display the menu
void displayMenu() {
    cout << "\nMenu:\n";
    cout << "1. Enqueue Email\n";
    cout << "2. Dequeue Email\n";
    cout << "3. Display All Emails\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

// Main function to drive the menu and manage the queue
int main() {
    EmailQueue emailQueue;
    int choice;

    while (1) {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1: {
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
            getline(cin, body);    // Taking full line input for body

            Email email(sender, receiver, subject, body);
            emailQueue.enqueue(email);
            break;
        }
        case 2: {
            // Dequeue email
            emailQueue.dequeue();
            break;
        }
        case 3: {
            // Display all emails
            emailQueue.displayAllEmails();
            break;
        }
        case 4: {
            cout << "Exiting the program." << endl;
            return 0; 
        }
        default: {
            cout << "Invalid choice, please try again." << endl;
        }
        }
    }

    return 0;
}
