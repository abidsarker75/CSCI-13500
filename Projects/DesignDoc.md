# Program Design Document

## Program Name

GPACalc

## Purpose

This program will allow the user to keep adding their classes to calculate their gpa
with the number of classes taken until the user is done. It will ask the user for
the class credit and GPA letter grade ex: '3A' and then calculate the gpa. Once the user
is done the program will then say it is completed.

---

## Inputs

- Credit
- Letter Grade
- 'Y' for yes to adding another input

---

## Outputs

- Classes taken
- GPA

---

## Variables

| Variable         | Type   | Purpose                                    |
| ---------------- | ------ | ------------------------------------------ |
| input            | string | Stores the full user input like 3A or 4B-  |
| credit           | string | Stores the credit part of the input        |
| grade            | string | Stores the letter grade part of the input  |
| credits          | int    | Stores the number of credits               |
| totalClasses     | int    | Stores the total number of classes entered |
| letterGrades     | array  | Stores all valid letter grades             |
| gradePoint       | array  | Stores the GPA point values for each grade |
| totalCredits     | double | Stores the total credits                   |
| totalGradePoints | double | Stores the total weighted grade points     |
| points           | double | Stores the grade point value for the class |
| gpa              | double | Stores the calculated GPA                  |
| yes              | char   | Stores whether the user wants to continue  |

---

## Key Design Choices

- I chose a while loop because in this program it requires the user to keep
  entering inputs until they are satisfied.
- I used a switch statement because the program needs to check the letter grade
  and each case will handle a different letter grade.
- I had to use ASCII and type casting to take the number of credits from the users
  input since I needed to take the value from a char into an int.

---

## Program Steps (Algorithm)

1. Declare variables to store the user input, credits, letter grade, total classes, total credits, total grade points, and GPA.
2. Create arrays to hold the valid letter grades and their GPA point values.
3. Welcome the user and show the correct input format, such as `3A`.
4. Use a while loop to keep going until the user is done inputting credits and grades.
5. Take in user input that includes both the credits and the letter grade.
6. Split the credits and letter grade and store them into separate variables.
7. Convert the credits from a string into an integer using ASCII.
8. Convert any lowercase letters in the grade into uppercase letters.
9. Use switch statements to convert the letter grade into a grade point value.
10. Check if the credits and letter grade are valid.
11. If the input is valid, add one to the total number of classes.
12. Add the current class credits to the total credits.
13. Add the current class grade points to the total grade points.
14. Calculate the semester GPA by dividing total grade points by total credits.
15. Display the total classes taken and the current semester GPA.
16. Ask the user if they want to enter another class.
17. End the program when the user does not enter `y` or `Y`.

---

## Sample Input/Output

Input:
Welcome to Basic GPA Calculator!
Enter input as such: '3A'
Enter class credits and grade: 4B
Do you want to enter another class? y/n:

Output:
Classes taken: 2, Semester GPA: 3.43

---

## AI Reflection:

1. I had to use AI and the AI I used was chatgbt.
2. I used it for figuring out how to take the first input from when the user inputs their
   credit and letter grade. I could not convert the credit from char to int with just type
   casting because I kept getting a different number. Chatgbt then told me the reason for me
   getting a different number was because it was giving the ASCII instead so I had to subtract
   the value I was taking by the ASCII of 0 to get the number of credits.
