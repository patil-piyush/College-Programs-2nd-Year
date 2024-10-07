#include<iostream>
#include<string>
using namespace std;

class Queue{
    string arr[20];  // Array to store party names
    int front, rear;
public:
    Queue() {
        front = -1;
        rear = -1;
    }
    void Insert(string name);  // Add party to waitlist
    void Delete();             // remove from waitlist
    void display();            // Display the waitlist
    bool isEmpty();            // Check if waitlist is empty
    bool isFull();             // Check if waitlist is full
};

bool Queue::isEmpty() {
    return (front == -1 || front > rear);
}

bool Queue::isFull() {
    return (rear == 19);
}

void Queue::Insert(string name) {
    if (isFull()) {
        cout << "Waitlist is Full!!" << endl;
        return;
    }
    else {
        if (front == -1)
            front = 0;
        rear++;  // Move rear forward
        arr[rear] = name;  // Add party name to the waitlist
        cout << "Party " << name << " added to the waitlist." << endl;
    }
}

void Queue::Delete() {
    if (isEmpty()) {
        cout << "Waitlist is Empty!!" << endl;
        return;
    }
    else {
        cout << "Party " << arr[front] << " has been seated." << endl;
        front++;  // Remove the front party
    }
}

void Queue::display() {
    if (isEmpty()) {
        cout << "Waitlist is Empty!!" << endl;
    } else {
        cout << "Current Waitlist: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    Queue q;
    int choice;
    string partyName;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Party to Waitlist\n";
        cout << "2. Seat Party\n";
        cout << "3. Display Waitlist\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter party name to add: ";
                cin >> partyName;
                q.Insert(partyName);
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
