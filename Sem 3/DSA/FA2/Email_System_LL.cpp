#include <iostream>
#include <string>
#include <ctime>

using namespace std;

// Function to convert date and time to Unix timestamp
time_t convertToUnixTimestamp(int year, int month, int day, int hour, int minute)
{
    tm email_time = {};
    email_time.tm_year = year - 1900; // Year since 1900
    email_time.tm_mon = month - 1;    // Month (0 = January)
    email_time.tm_mday = day;         // Day of the month
    email_time.tm_hour = hour;        // Hours
    email_time.tm_min = minute;       // Minutes
    email_time.tm_sec = 0;            // Seconds
    return mktime(&email_time);       // Convert to Unix timestamp
}

// Email class to store email details
class Email
{
public:
    string sender_email;
    string receiver_email;
    string subject;
    string body;
    time_t scheduled_time;

    Email() {}
    Email(string sender, string receiver, string sub, string bod, time_t sched_time)
    {
        sender_email = sender;
        receiver_email = receiver;
        subject = sub;
        body = bod;
        scheduled_time = sched_time;
    }

    // Display the email details
    void displayEmail() const
    {
        cout << "\n-------------------------------------\n";
        cout << "From: " << sender_email << "\n";
        cout << "To: " << receiver_email << "\n";
        cout << "Subject: " << subject << "\n";
        cout << "Body: " << body << "\n";
        cout << "Scheduled Time: " << ctime(&scheduled_time); // Show scheduled time in a human-readable format
        cout << "-------------------------------------\n";
    }
};

// Node structure to represent each node in the linked list
struct Node
{
    Email email;
    Node* next;

    Node(Email e){
        email = e;
        next = nullptr;
    }
};

// EmailScheduler class using a linked list for processing scheduled emails
class EmailScheduler
{
private:
    Node* head; // Pointer to the head of the linked list
    Node* tail; // Pointer to the tail of the linked list

public:
    EmailScheduler(){
        head = nullptr;
        tail = nullptr;
    }

    // Schedule a new email by adding it to the linked list
    void scheduleEmail(Email email)
    {
        Node* newNode = new Node(email); // Dynamically allocate memory for the new node

        if (!head)
        {
            head = tail = newNode; // If list is empty, both head and tail point to the new node
        }
        else
        {
            tail->next = newNode;  // Add the new node at the end of the list
            tail = newNode;        // Update the tail to point to the last node
        }

        cout << "Email scheduled from " << email.sender_email
             << " to " << email.receiver_email
             << " at " << ctime(&email.scheduled_time); // Show scheduled time in the format that human can read
    }

    // Sort the scheduled emails by scheduled time (Insertion Sort for linked list)
    void sortEmails()
    {
        if (!head || !head->next) // If the list is empty or contains only one element
            return;

        Node* sorted = nullptr; // Start with an empty sorted list

        Node* current = head;
        while (current)
        {
            Node* next = current->next; // Store next for later use
            sortedInsert(&sorted, current); // Insert current node into sorted list
            current = next;
        }

        head = sorted; // Update head to point to the sorted list
    }

    // Helper function to insert a node into a sorted linked list
    void sortedInsert(Node** sorted, Node* newNode)
    {
        if (!*sorted || (*sorted)->email.scheduled_time > newNode->email.scheduled_time)
        {
            newNode->next = *sorted; // Insert at the beginning
            *sorted = newNode;
        }
        else
        {
            Node* current = *sorted;
            while (current->next && current->next->email.scheduled_time <= newNode->email.scheduled_time)
            {
                current = current->next; // Find the correct position for the new node
            }
            newNode->next = current->next;
            current->next = newNode; // Insert the new node
        }
    }

    // Process emails and send those whose time has come
    void processEmails()
    {
        if (!head)
        {
            cout << "No emails to send right now.\n";
            return;
        }

        // Sort emails by scheduled time before processing
        sortEmails();

        time_t now = time(0); // Get current time
        Node* current = head;

        while (current && current->email.scheduled_time <= now)
        {
            cout << "\n--- Sending Email ---";
            current->email.displayEmail();
            Node* temp = current;
            current = current->next; // Move to the next email
            delete temp;              // Free the memory of the sent email
        }

        head = current; // Update head to point to the remaining emails

        if (!head)
        {
            tail = nullptr; // Reset tail if the list is empty
            cout << "\nAll emails have been sent.\n";
        }
        else
        {
            cout << "\nWaiting for the next email to be sent...\n";
        }
    }

    // Display all scheduled emails
    void displayScheduledEmails() const
    {
        if (!head)
        {
            cout << "\nNo scheduled emails.\n";
            return;
        }

        cout << "\nScheduled Emails:\n";
        Node* current = head;
        while (current)
        {
            current->email.displayEmail();
            current = current->next;
        }
    }
};

// Function to display the menu
void displayMenu()
{
    cout << "\nMenu:\n";
    cout << "1. Schedule an email\n";
    cout << "2. Process emails\n";
    cout << "3. Display all scheduled emails\n";
    cout << "4. Quit\n";
    cout << "Enter your choice: ";
}

// Main program for email scheduling system
int main()
{
    EmailScheduler scheduler;
    int choice;

    do
    {
        displayMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            // Input email details from user
            cout << "Enter sender's email: ";
            string sender_email;
            cin >> sender_email;

            cout << "Enter receiver's email: ";
            string receiver_email;
            cin >> receiver_email;

            cout << "Enter subject: ";
            string subject;
            cin.ignore(); // Clear input buffer
            getline(cin, subject);

            cout << "Enter body: ";
            string body;
            getline(cin, body);

            // Input time to send the email
            int year, month, day, hour, minute;
            cout << "Enter the date and time to send the email (YYYY MM DD HH MM): ";
            cin >> year >> month >> day >> hour >> minute;

            // Convert the provided time to Unix timestamp
            time_t scheduled_time = convertToUnixTimestamp(year, month, day, hour, minute);

            // Create the email object and schedule it
            Email new_email(sender_email, receiver_email, subject, body, scheduled_time);
            scheduler.scheduleEmail(new_email);
            break;
        }
        case 2:
        {
            // Process emails when it's time to send them
            scheduler.processEmails();
            break;
        }
        case 3:
        {
            // Display all scheduled emails
            scheduler.displayScheduledEmails();
            break;
        }
        case 4:
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 4);

    return 0;
}















