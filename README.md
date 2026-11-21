# Smart Student Management System

## Project Introduction
The Smart Student Management System is a beginner-level C++ console application developed as a university semester project at Sukkur IBA University. It helps manage student records, search student information, calculate academic results, and save records for future use.

## Project Objectives
- To understand practical C++ programming.
- To manage student records efficiently.
- To practice arrays, loops, conditions, and file handling.
- To calculate student percentages, grades, and pass/fail status.
- To improve programming and problem-solving skills.

## Features
- Add Student
- Display All Students
- Search Student by Roll Number
- Calculate Student Result
- Save Student Records
- Automatically Load Records
- Validate Duplicate Roll Numbers
- Validate Marks (0–100)
- Support up to 50 Students

## Technologies Used
- Programming Language: C++
- IDE: Dev-C++
- Application Type: Console-Based Application
- File Handling: `fstream`
- Data Storage: `student_records.txt`

## How to Run the Program
1. Download or clone this repository.
2. Open `main.cpp` in Dev-C++ or another C++ IDE.
3. Compile the program.
4. Run the executable.
5. Select an option from the main menu.

---

# Line-by-Line Code Explanation (C++)

## What the Program Does
The program stores up to 50 students, including their names, roll numbers, and marks.

Users can:
- Add a student.
- Display all students.
- Search by roll number.
- Calculate results (grade and pass/fail).
- Save records to a file.
- Exit the program.

Previously saved records are loaded from `student_records.txt` when the program starts.

## 1. Header Files and Variables

| Code | Explanation |
|---|---|
| `#include<iostream>` | Provides `cin` and `cout` for input and output. |
| `#include<string>` | Allows the use of the `string` data type. |
| `#include<fstream>` | Provides file handling through `ifstream` and `ofstream`. |
| `using namespace std;` | Allows us to write `cout` instead of `std::cout`. |
| `int main(){` | Starting point of program execution. |
| `string name[50];` | Stores up to 50 student names. |
| `int roll[50];` | Stores student roll numbers. |
| `float marks[50];` | Stores student marks, including decimal values. |
| `int count = 0;` | Counts the number of currently stored students. |
| `int choice;` | Stores the user's menu selection. |
| `bool duplicate;` | Checks whether a roll number is duplicate or invalid. |

## 2. Loading Records from File (At Start)

| Code | Explanation |
|---|---|
| `ifstream file("student_records.txt");` | Opens the file for reading. |
| `if(file){` | Checks whether the file opened successfully. |
| `while(count < 50 && getline(file, name[count]))` | Reads student names while there is available space. |
| `file >> roll[count] >> marks[count]` | Reads the student's roll number and marks. |
| `if(!(file >> roll[count] >> marks[count]))` | Checks whether reading failed or the data is incomplete. |
| `break;` | Stops the loading loop if reading fails. |
| `file.ignore();` | Skips the remaining newline character. |
| `count++;` | Increases the number of loaded students. |
| `file.close();` | Closes the file. |
| `cout << count << " Student Records Loaded Successfully!";` | Displays the number of loaded records. |

**Important:** `getline()` reads the complete student name, including spaces.

## 3. Menu Loop

| Code | Explanation |
|---|---|
| `do {` | Starts the main menu loop. |
| `cout << "===== SMART ... =====";` | Displays the program title. |
| `cout << "1. Add Student";` | Displays the Add Student option. |
| `cout << "6. Exit";` | Displays the Exit option. |
| `cout << "Enter your choice: ";` | Asks the user to select an option. |
| `cin >> choice;` | Reads the selected option. |
| `switch(choice){` | Selects the matching case according to the user's choice. |

The menu repeats until the user selects option 6.

## 4. Case 1: Add Student

**Purpose:** Adds a new student to the system.

| Code | Explanation |
|---|---|
| `case 1:` | Starts the Add Student operation. |
| `if(count < 50){` | Checks whether the student limit has been reached. |
| `cout << "Enter Student Name: ";` | Asks for the student's name. |
| `cin.ignore();` | Removes the leftover newline before reading the full name. |
| `getline(cin, name[count]);` | Reads the complete student name. |
| `do {` | Starts the roll number validation loop. |
| `duplicate = false;` | Initially assumes the roll number is valid. |
| `cin >> roll[count];` | Reads the roll number. |
| `cin.clear();` | Resets the input error state if invalid input occurs. |
| `cin.ignore(1000, '\n');` | Discards incorrect input from the current line. |
| `if(roll[count] <= 0)` | Rejects zero and negative roll numbers. |
| `for(int i = 0; i < count; i++)` | Checks previously stored roll numbers. |
| `if(roll[i] == roll[count])` | Detects a duplicate roll number. |
| `duplicate = true;` | Marks the roll number as invalid. |
| `break;` | Stops the duplicate-checking loop. |
| `while(duplicate);` | Repeats until a valid, unique roll number is entered. |
| `cout << "Enter Marks (0-100): ";` | Asks the user to enter marks. |
| `while(true){` | Starts the marks validation loop. |
| `cin >> marks[count];` | Reads student marks. |
| `marks[count] < 0 || marks[count] > 100` | Checks whether marks are outside the allowed range. |
| `break;` | Exits the loop when valid marks are entered. |
| `count++;` | Increases the student count after successful entry. |
| `cout << "Student Added Successfully!";` | Displays the success message. |
| `else` | Executes when the student limit is reached. |
| `cout << "Student Limit Reached!";` | Displays the capacity warning. |
| `break;` | Ends Case 1. |

**Important concepts:**
- `do-while`: Repeats input validation.
- `for`: Checks duplicate roll numbers.
- `continue`: Skips the current iteration and asks again.
- `break`: Exits a loop or switch case.

## 5. Case 2: Display All Students

**Purpose:** Displays all registered student records.

| Code | Explanation |
|---|---|
| `case 2:` | Starts the display operation. |
| `if(count == 0)` | Checks whether there are any students. |
| `cout << "No Students Found!";` | Displays a message if no records exist. |
| `else` | Runs when student records are available. |
| `for(int i = 0; i < count; i++)` | Loops through all stored students. |
| `i + 1` | Displays student serial numbers starting from 1. |
| `name[i]` | Displays the student's name. |
| `roll[i]` | Displays the student's roll number. |
| `marks[i]` | Displays the student's marks. |
| `break;` | Ends Case 2. |

**Important:** Array indexing starts from 0, but student serial numbers start from 1.

## 6. Case 3: Search Student

**Purpose:** Finds a student using their roll number.

| Code | Explanation |
|---|---|
| `case 3: {` | Starts the search operation. |
| `int searchRoll;` | Stores the roll number to search. |
| `bool found = false;` | Initially assumes the student has not been found. |
| `cin >> searchRoll;` | Reads the roll number. |
| `for(int i = 0; i < count; i++)` | Checks all stored students. |
| `if(roll[i] == searchRoll)` | Compares the stored roll number with the searched number. |
| `cout << "Student Found!";` | Displays a success message. |
| `cout << name[i];` | Displays the student's name. |
| `cout << roll[i];` | Displays the roll number. |
| `cout << marks[i];` | Displays the marks. |
| `found = true;` | Records that the student was found. |
| `break;` | Stops searching after a match. |
| `if(found == false)` | Checks whether


Developed by: Mr. Muhammad Idrees

Academic Institution: Sukkur IBA University

Department: Computer Systems Engineering

This project was developed as part of academic learning and practical C++ programming experience.
