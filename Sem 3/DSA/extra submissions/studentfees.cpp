#include <iostream>
#include <string>
using namespace std;

class Student {
    string name;
    int rollNumber;

public:
    Student *next;
    Student();
    void read();
    void display();
    string showName();
    int showRollNumber();
};

class StudentQueue {
public:
    Student *head;
    StudentQueue();
    void enqueueStudent();    // Arrival of student
    void dequeueStudent();    // Pay fees
    void displayQueue();      // Display all waiting students
    bool isEmpty();           // Check if queue is empty
};

// Function definitions for Student class
Student::Student() {
    name = "null";
    rollNumber = 0;
    next = nullptr;
}

void Student::read() {
    cout << "Enter student details:" << endl;
    cout << "Name: ";
    cin >> name;
    cout << "Roll Number: ";
    cin >> rollNumber;
}

void Student::display() {
    cout << "Student Name: " << name << ", Roll Number: " << rollNumber << endl;
}

string Student::showName() {
    return name;
}

int Student::showRollNumber() {
    return rollNumber;
}

// Function definitions for StudentQueue class
StudentQueue::StudentQueue() {
    head = nullptr;
}

bool StudentQueue::isEmpty() {
    return head == nullptr;
}

void StudentQueue::enqueueStudent() {
    Student *newStudent = new Student();
    newStudent->read();
    if (isEmpty()) {
        head = newStudent;
    } else {
        Student *temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newStudent;
    }
    cout << "Student added to the queue." << endl;
}

void StudentQueue::dequeueStudent() {
    if (isEmpty()) {
        cout << "No students in the queue." << endl;
    } else {
        Student *temp = head;
        cout << "Processing fees for: ";
        temp->display();
        head = head->next;
        delete temp;
        cout << "Fees paid successfully." << endl;
    }
}

void StudentQueue::displayQueue() {
    if (isEmpty()) {
        cout << "No students are waiting." << endl;
    } else {
        Student *temp = head;
        cout << "Students in the queue:" << endl;
        while (temp != nullptr) {
            temp->display();
            temp = temp->next;
        }
    }
}

int main() {
    StudentQueue queue;
    int choice;

    do {
        cout << "\n--- Fee Collection System ---\n";
        cout << "1. Arrival of Student\n";
        cout << "2. Pay Fees\n";
        cout << "3. Display All Waiting Students\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                queue.enqueueStudent();
                break;
            case 2:
                queue.dequeueStudent();
                break;
            case 3:
                queue.displayQueue();
                break;
            case 4:
                cout << "Exiting the system." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
