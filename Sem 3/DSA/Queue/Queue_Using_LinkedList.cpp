// the code for customer list at the hotel by using linked list and make it menu driven program
#include <iostream>
#include <string>
using namespace std;

class Customer
{
    string name;
    long long contact;

public:
    Customer *next;
    Customer();
    void read();
    void Display();
    string ShowName();
};

class CustomerList{
    public:
    Customer *head;
    CustomerList();
    void InsertCustomer();
    void ServeCustomer();
    void Display();
    bool isEmpty(); // Check if queue is empty
    bool isFull();  // Check if queue is full
};

// function definations for class customer
Customer::Customer()
{
    name = "null";
    contact = 0;
    next = nullptr;
}

void Customer::Display()
{
    cout << "Customer Name: " << name << endl
         << "Customer Contact Number: " << contact << endl;
}

void Customer::read()
{
    cout << "Enter the details of the customer: " << endl;
    cout << "Customer Name: ";
    cin >> name;
    cout << "Customer Contact Number: ";
    cin >> contact;
}

string Customer::ShowName()
{
    return name;
}

//function Definition for CustomerList class

CustomerList::CustomerList(){
    head = nullptr;
}

bool CustomerList::isFull(){
     
}

bool CustomerList::isEmpty (){
     
}

void CustomerList::InsertCustomer(){
     
}
