#include <iostream>
using namespace std;

class Node
{
    string jobName;
    int priority;
    string time;

public:
    Node *prev;
    Node *next;
    Node();
    Node(string j, int p, string t);
    void display();
    int showPriority();
};

class doubleQueue
{
public:
    Node *f;
    Node *r;
    doubleQueue();
    void insertFront(Node &nnn);
    void insertRear(Node &nnn);
    void DeleteFront();
    void DeleteRear();
    void displayQueue();
};

Node::Node()
{
    jobName = "NA";
    priority = 0;
    time = "NA";
    prev = next = nullptr;
}

Node::Node(string j, int p, string t)
{
    jobName = j;
    priority = p;
    time = t;
    prev = next = nullptr;
}

void Node::display()
{
    cout << "Job Name: " << jobName << ", Priority: " << priority << ", Time: " << time << endl;
}

int Node::showPriority()
{
    return priority;
}

doubleQueue::doubleQueue()
{
    f = r = nullptr;
}

void doubleQueue::insertFront(Node &nnn)
{
    Node *nn = new Node(nnn);

    if (f == nullptr && r == nullptr)
    {
        f = r = nn;
    }
    else
    {
        nn->next = f;
        f->prev = nn;
        f = nn;
    }
    cout << "Inserted at the front successfully!\n";
}

void doubleQueue::insertRear(Node &nnn)
{
    Node *nn = new Node(nnn);

    if (f == nullptr && r == nullptr)
    {
        f = r = nn;
    }
    else
    {
        nn->prev = r;
        r->next = nn;
        r = nn;
    }
    cout << "Inserted at the rear successfully!\n";
}

void doubleQueue::DeleteFront()
{
    if (f == nullptr && r == nullptr)
    {
        cout << "Queue is Empty!!" << endl;
        return;
    }
    else
    {
        Node *temp = f->next;
        if (temp != nullptr)
        {
            temp->prev = nullptr;
        }
        delete f;
        f = temp;
        if (f == nullptr)
            r = nullptr; // In case there was only one element
        cout << "Deleted from the front successfully!\n";
    }
}

void doubleQueue::DeleteRear()
{
    if (f == nullptr && r == nullptr)
    {
        cout << "Queue is Empty!!" << endl;
        return;
    }
    else
    {
        Node *temp = r->prev;
        if (temp != nullptr)
        {
            temp->next = nullptr;
        }
        delete r;
        r = temp;
        if (r == nullptr)
            f = nullptr; // In case there was only one element
        cout << "Deleted from the rear successfully!\n";
    }
}

void doubleQueue::displayQueue()
{
    if (f == nullptr && r == nullptr)
    {
        cout << "Queue is Empty!!" << endl;
        return;
    }

    Node *temp = f;
    while (temp != nullptr)
    {
        temp->display();
        temp = temp->next;
    }
}

int main()
{
    doubleQueue dq;
    int choice;
    string jobname, time;
    int priority;

    while (1)
    {
        cout << "\n--- Double Ended Queue Operations Menu ---\n";
        cout << "1. Insert Job\n";
        cout << "2. Delete Job from Front\n";
        cout << "3. Delete Job from Rear\n";
        cout << "4. Display all Jobs\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter the Job name: ";
            cin >> jobname;
            cout << "Enter priority of the job: ";
            cin >> priority;
            cout << "Enter the shift (Day/Night): ";
            cin >> time;

            Node nn(jobname, priority, time);

            // Check if the queue is empty or compare with front node priority
            if (dq.f == nullptr || priority > dq.f->showPriority())
                dq.insertFront(nn);
            else
                dq.insertRear(nn);
        }
        else if (choice == 2)
        {
            dq.DeleteFront();
        }
        else if (choice == 3)
        {
            dq.DeleteRear();
        }
        else if (choice == 4)
        {
            dq.displayQueue();
        }
        else if (choice == 5)
        {
            cout << "Exiting the program...\n";
            return 0;
        }
        else
        {
            cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
