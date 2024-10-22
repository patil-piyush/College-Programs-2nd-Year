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
        cout << "Scheduled Time: " << ctime(&scheduled_time); // Show scheduled time in the format that human can read
        cout << "-------------------------------------\n";
    }
};

// EmailScheduler class for processing scheduled emails
class EmailScheduler
{
private:
    Email queue[100]; // Using a fixed-size array to store the emails
    int front;        // Pointer to the front of the queue
    int rear;         // Pointer to the rear of the queue
    int size;         // Number of emails in the queue

public:
    EmailScheduler()
    {
        front = 0;
        rear = 0;
        size = 0;
    }

    // Schedule a new email
    void scheduleEmail(Email email)
    {
        if (size >= 100)
        {
            cout << "Email queue is full!\n";
            return;
        }

        queue[rear] = email;     // Add the new email
        rear = (rear + 1) % 100; // Circular increment
        size++;
        cout << "Email scheduled from " << email.sender_email
             << " to " << email.receiver_email
             << " at " << ctime(&email.scheduled_time); // Show scheduled time in the format that human can read
    }

    // Sort the scheduled emails by scheduled time (Insertion Sort)
    void sortEmails()
    {
        for (int i = 1; i < size; ++i)
        {
            Email key = queue[(front + i) % 100]; // Get the email at the current index
            int j = i - 1;

            // Move elements of queue that are greater than key to one position ahead
            while (j >= 0 && queue[(front + j) % 100].scheduled_time > key.scheduled_time)
            {
                queue[(front + j + 1) % 100] = queue[(front + j) % 100];
                j--;
            }
            queue[(front + j + 1) % 100] = key; // Insert the key in its correct position
        }
    }

    // Process emails and send those whose time has come
    void processEmails()
    {
        if (size == 0)
        {
            cout << "No emails to send right now.\n";
            return;
        }

        // Sort emails by scheduled time before processing
        sortEmails();

        time_t now = time(0); // Get current time
        int count = size;     // Store the count of emails to process

        while (count > 0)
        {
            // Check if the front email is ready to be sent
            if (queue[front].scheduled_time <= now)
            {
                cout << "\n--- Sending Email ---";
                queue[front].displayEmail();
                // Move front pointer and decrease size
                front = (front + 1) % 100; // Circular increment
                size--;
            }
            else
            {
                break; // Exit loop if no more emails are ready to send
            }
            count--; // Decrease count
        }

        if (size > 0)
        {
            cout << "\nWaiting for the next email to be sent...\n";
        }
        else
        {
            cout << "\nAll emails have been sent.\n";
            front = rear = 0; // Reset the queue
        }
    }

    // Display all scheduled emails
    void displayScheduledEmails() const
    {
        if (size == 0)
        {
            cout << "\nNo scheduled emails.\n";
            return;
        }

        cout << "\nScheduled Emails:\n";
        int idx = front;
        for (int i = 0; i < size; ++i)
        {
            queue[idx].displayEmail();
            idx = (idx + 1) % 100; // Circular increment
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
