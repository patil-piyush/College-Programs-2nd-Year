# Function to display the menu
def menu():
    print("\nStudent Database Management")
    print("1. Add Student")
    print("2. Remove Student")
    print("3. Update Student")
    print("4. View All Students")
    print("5. View Top Students (SGPA >= 8.0)")
    print("6. Sort Students by Roll Number")
    print("7. Sort Students by Name")
    print("8. Slice Student List")
    print("9. Exit")

# Function to add a student
def add_student(students):
    roll_no = int(input("Enter Roll Number: "))
    name = input("Enter Name: ")
    sgpa = float(input("Enter SGPA: "))
    student = {"Roll No": roll_no, "Name": name, "SGPA": sgpa}
    students.append(student)
    print(f"Student {name} added successfully.")

# Function to remove a student by roll number
def remove_student(students):
    roll_no = int(input("Enter Roll Number of the student to remove: "))
    for student in students:
        if student["Roll No"] == roll_no:
            students.remove(student)
            print(f"Student with Roll No {roll_no} removed successfully.")
            return
    print(f"Student with Roll No {roll_no} not found.")

# Function to update a student's details
def update_student(students):
    roll_no = int(input("Enter Roll Number of the student to update: "))
    for student in students:
        if student["Roll No"] == roll_no:
            name = input("Enter new Name: ")
            sgpa = float(input("Enter new SGPA: "))
            student["Name"] = name
            student["SGPA"] = sgpa
            print(f"Student {roll_no} updated successfully.")
            return
    print(f"Student with Roll No {roll_no} not found.")

# Function to view all students
def view_students(students):
    if not students:
        print("No students found.")
    else:
        print("\nStudent List:")
        for student in students:
            print(f"Roll No: {student['Roll No']}, Name: {student['Name']}, SGPA: {student['SGPA']}")

# Function to view students with SGPA >= 8.0
def view_top_students(students):
    print("\nTop Students (SGPA >= 8.0):")
    for student in students:
        if student["SGPA"] >= 8.0:
            print(f"Roll No: {student['Roll No']}, Name: {student['Name']}, SGPA: {student['SGPA']}")

# Function to sort students by roll number
def sort_by_roll_no(students):
    students.sort(key=lambda student: student["Roll No"])
    print("Students sorted by Roll Number.")

# Function to sort students by name
def sort_by_name(students):
    students.sort(key=lambda student: student["Name"])
    print("Students sorted by Name.")

# Function to slice and view a range of students
def slice_students(students):
    start = int(input("Enter the start index for slicing: "))
    end = int(input("Enter the end index for slicing: "))
    sliced_students = students[start:end]
    print(f"\nSliced List (from index {start} to {end}):")
    for student in sliced_students:
        print(f"Roll No: {student['Roll No']}, Name: {student['Name']}, SGPA: {student['SGPA']}")

# Main program
students = []  # List to store student data

while True:
    menu()
    choice = int(input("Enter your choice: "))

    if choice == 1:
        add_student(students)
    elif choice == 2:
        remove_student(students)
    elif choice == 3:
        update_student(students)
    elif choice == 4:
        view_students(students)
    elif choice == 5:
        view_top_students(students)
    elif choice == 6:
        sort_by_roll_no(students)
    elif choice == 7:
        sort_by_name(students)
    elif choice == 8:
        slice_students(students)
    elif choice == 9:
        print("Exiting program. Goodbye!")
        break
    else:
        print("Invalid choice. Please try again.")


# Output:
# Student Database Management
# 1. Add Student
# 2. Remove Student
# 3. Update Student
# 4. View All Students
# 5. View Top Students (SGPA >= 8.0)
# 6. Sort Students by Roll Number
# 7. Sort Students by Name
# 8. Slice Student List
# 9. Exit
# Enter your choice: 1

# Enter Roll Number: 101
# Enter Name: Rohan Sharma
# Enter SGPA: 8.5
# Student Rohan Sharma added successfully.

# Student Database Management
# 1. Add Student
# 2. Remove Student
# 3. Update Student
# 4. View All Students
# 5. View Top Students (SGPA >= 8.0)
# 6. Sort Students by Roll Number
# 7. Sort Students by Name
# 8. Slice Student List
# 9. Exit
# Enter your choice: 1

# Enter Roll Number: 102
# Enter Name: Priya Verma
# Enter SGPA: 7.8
# Student Priya Verma added successfully.

# Student Database Management
# 1. Add Student
# 2. Remove Student
# 3. Update Student
# 4. View All Students
# 5. View Top Students (SGPA >= 8.0)
# 6. Sort Students by Roll Number
# 7. Sort Students by Name
# 8. Slice Student List
# 9. Exit
# Enter your choice: 4

# Student List:
# Roll No: 101, Name: Rohan Sharma, SGPA: 8.5
# Roll No: 102, Name: Priya Verma, SGPA: 7.8

# Student Database Management
# 1. Add Student
# 2. Remove Student
# 3. Update Student
# 4. View All Students
# 5. View Top Students (SGPA >= 8.0)
# 6. Sort Students by Roll Number
# 7. Sort Students by Name
# 8. Slice Student List
# 9. Exit
# Enter your choice: 5

# Top Students (SGPA >= 8.0):
# Roll No: 101, Name: Rohan Sharma, SGPA: 8.5

# Student Database Management
# 1. Add Student
# 2. Remove Student
# 3. Update Student
# 4. View All Students
# 5. View Top Students (SGPA >= 8.0)
# 6. Sort Students by Roll Number
# 7. Sort Students by Name
# 8. Slice Student List
# 9. Exit
# Enter your choice: 7

# Students sorted by Name.

# Student Database Management
# 1. Add Student
# 2. Remove Student
# 3. Update Student
# 4. View All Students
# 5. View Top Students (SGPA >= 8.0)
# 6. Sort Students by Roll Number
# 7. Sort Students by Name
# 8. Slice Student List
# 9. Exit
# Enter your choice: 4

# Student List:
# Roll No: 102, Name: Priya Verma, SGPA: 7.8
# Roll No: 101, Name: Rohan Sharma, SGPA: 8.5

# Student Database Management
# 1. Add Student
# 2. Remove Student
# 3. Update Student
# 4. View All Students
# 5. View Top Students (SGPA >= 8.0)
# 6. Sort Students by Roll Number
# 7. Sort Students by Name
# 8. Slice Student List
# 9. Exit
# Enter your choice: 9

# Exiting program. Goodbye!
