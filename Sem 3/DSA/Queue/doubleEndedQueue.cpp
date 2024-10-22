#include<iostream>
using namespace std;

class Node{
    string jobName;
    int priority;
    string time;
    public:
    Node* prev;
    Node* next;
    Node();
    Node(string j, int p, string t);
    void read();
    void display(); // To display job details
};

class doubleQueue{
    public:
    Node* f;
    Node* r;
    doubleQueue();
    void insertFront();
    void insertRear();
    void DeleteFront();
    void DeleteRear();
    void displayQueue(); // To display all the jobs in the queue
};

Node::Node(){
    jobName = "NA";
    priority = 0;
    time = "NA";
    prev = next = nullptr;
}

Node::Node(string j, int p, string t){
    jobName = j;
    priority = p;
    time = t;
    prev = next = nullptr;
}

void Node::read(){
    cout << "Enter Job Name: ";
    cin >> jobName;
    cout << "Enter Priority: ";
    cin >> priority;
    cout << "Enter Time: ";
    cin >> time;
}

void Node::display(){
    cout << "Job Name: " << jobName << ", Priority: " << priority << ", Time: " << time << endl;
}

doubleQueue::doubleQueue(){
    f = r = nullptr;
}

void doubleQueue::insertFront(){
    Node* nn = new Node;
    nn->read();

    if(f == nullptr && r == nullptr){
        f = r = nn;
    }
    else{
        nn->next = f;
        f->prev = nn;
        f = nn;
    }
    cout << "Inserted at the front successfully!\n";
}

void doubleQueue::insertRear(){
    Node* nn = new Node;
    nn->read();

    if(f == nullptr && r == nullptr){
        f = r = nn;
    }
    else{
        nn->prev = r;
        r->next = nn;
        r = nn;
    }
    cout << "Inserted at the rear successfully!\n";
}

void doubleQueue::DeleteFront(){
    if(f == nullptr && r == nullptr){
        cout << "Queue is Empty!!" << endl; 
        return;
    }
    else{
        Node* temp = f->next;
        if (temp != nullptr) {
            temp->prev = nullptr;
        }
        delete f;
        f = temp;
        if(f == nullptr) r = nullptr;  // In case there was only one element
        cout << "Deleted from the front successfully!\n";
    }
}

void doubleQueue::DeleteRear(){
    if(f == nullptr && r == nullptr){
        cout << "Queue is Empty!!" << endl; 
        return;
    }
    else{
        Node* temp = r->prev;
        if (temp != nullptr) {
            temp->next = nullptr;
        }
        delete r;
        r = temp;
        if(r == nullptr) f = nullptr;  // In case there was only one element
        cout << "Deleted from the rear successfully!\n";
    }
}

void doubleQueue::displayQueue(){
    if(f == nullptr && r == nullptr){
        cout << "Queue is Empty!!" << endl; 
        return;
    }
    
    Node* temp = f;
    while(temp != nullptr){
        temp->display();
        temp = temp->next;
    }
}

void checkInsert(){
 
}
int main(){
    doubleQueue dq;
    int choice;
    
    do {
        cout << "\n--- Double Ended Queue Operations Menu ---\n";
        cout << "1. Insert Job\n";
        cout << "2. Delete Job from Front\n";
        cout << "3. Delete Job from Rear\n";
        cout << "4. Display all Jobs\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                checkInsert();
                break;
            case 2:
                dq.DeleteFront();
                break;
            case 3:
                dq.DeleteRear();
                break;
            case 4:
                dq.displayQueue();
                break;
            case 5:
                cout << "Exiting the program...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while(choice != 6);
    
    return 0;
}
