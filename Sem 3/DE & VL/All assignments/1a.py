students = {}

# Function to add a new student
def add(name, score):
    if name in students:
        print(f"Student {name} already exists.")
    else:
        students[name] = score
        print(f"Added student {name} with score {score}.")

# Function to update a student's score
def update_score(name, score):
    if name in students:
        students[name] = score
        print(f"Updated {name}'s score to {score}.")
    else:
        print(f"Student {name} does not exist.")

# Function to delete a student
def delete(name):
    if name in students:
        del students[name]
        print(f"Deleted student {name}.")
    else:
        print(f"Student {name} not found.")

# Function to display the student with the highest score
def highest_score():
    if students:
        top_student = max(students, key=students.get)
        print(f"The student with the highest score is {top_student} with a score of {students[top_student]}.")
    else:
        print("No students in the list.")

# Function to display all students
def display_students():
    if students:
        print("Current list of students:")
        for name, score in students.items():
            print(f"Name: {name}, Score: {score}")
    else:
        print("No students in the list.")

# Menu-driven interface
def menu():
    while True:
        print("\nMenu:")
        print("1. Add a new student")
        print("2. Update a student's score")
        print("3. Delete a student")
        print("4. Display the student with the highest score")
        print("5. Display all students")
        print("6. Exit")
        
        choice = input("Enter your choice: ")
        
        if choice == '1':
            name = input("Enter student name: ")
            score = float(input(f"Enter score for {name}: "))
            add(name, score)
        
        elif choice == '2':
            name = input("Enter student name: ")
            if name in students:
                score = float(input(f"Enter new score for {name}: "))
                update_score(name, score)
            else:
                print(f"Student {name} does not exist.")
        
        elif choice == '3':
            name = input("Enter student name to delete: ")
            delete(name)
        
        elif choice == '4':
            highest_score()
        
        elif choice == '5':
            display_students()
        
        elif choice == '6':
            print("Exiting the program.")
            break
        
        else:
            print("Invalid choice. Please try again.")

# Start the menu-driven program
menu()



# Output:

# Menu:
# 1. Add a new student
# 2. Update a student's score
# 3. Delete a student
# 4. Display the student with the highest score
# 5. Display all students
# 6. Exit
# Enter your choice: 1

# Enter student name: Anjali Mehta
# Enter score for Anjali Mehta: 85.5
# Added student Anjali Mehta with score 85.5.

# Menu:
# 1. Add a new student
# 2. Update a student's score
# 3. Delete a student
# 4. Display the student with the highest score
# 5. Display all students
# 6. Exit
# Enter your choice: 1

# Enter student name: Ravi Kumar
# Enter score for Ravi Kumar: 91.2
# Added student Ravi Kumar with score 91.2.

# Menu:
# 1. Add a new student
# 2. Update a student's score
# 3. Delete a student
# 4. Display the student with the highest score
# 5. Display all students
# 6. Exit
# Enter your choice: 5

# Current list of students:
# Name: Anjali Mehta, Score: 85.5
# Name: Ravi Kumar, Score: 91.2

# Menu:
# 1. Add a new student
# 2. Update a student's score
# 3. Delete a student
# 4. Display the student with the highest score
# 5. Display all students
# 6. Exit
# Enter your choice: 4

# The student with the highest score is Ravi Kumar with a score of 91.2.

# Menu:
# 1. Add a new student
# 2. Update a student's score
# 3. Delete a student
# 4. Display the student with the highest score
# 5. Display all students
# 6. Exit
# Enter your choice: 2

# Enter student name: Anjali Mehta
# Enter new score for Anjali Mehta: 88.7
# Updated Anjali Mehta's score to 88.7.

# Menu:
# 1. Add a new student
# 2. Update a student's score
# 3. Delete a student
# 4. Display the student with the highest score
# 5. Display all students
# 6. Exit
# Enter your choice: 5

# Current list of students:
# Name: Anjali Mehta, Score: 88.7
# Name: Ravi Kumar, Score: 91.2

# Menu:
# 1. Add a new student
# 2. Update a student's score
# 3. Delete a student
# 4. Display the student with the highest score
# 5. Display all students
# 6. Exit
# Enter your choice: 3

# Enter student name to delete: Ravi Kumar
# Deleted student Ravi Kumar.

# Menu:
# 1. Add a new student
# 2. Update a student's score
# 3. Delete a student
# 4. Display the student with the highest score
# 5. Display all students
# 6. Exit
# Enter your choice: 5

# Current list of students:
# Name: Anjali Mehta, Score: 88.7

# Menu:
# 1. Add a new student
# 2. Update a student's score
# 3. Delete a student
# 4. Display the student with the highest score
# 5. Display all students
# 6. Exit
# Enter your choice: 6

# Exiting the program.
