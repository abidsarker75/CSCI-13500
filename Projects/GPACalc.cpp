#include <iostream>
#include <string>

int main() {
    // Declaring variables to store credits, letter grade, and total classes
    std::string input;
    std::string credit;
    std::string grade;
    int credits = 0;
    int totalClasses = 0;

    // arrays to hold the letter grade and each gpa amount
    std::string letterGrades[13] = {"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "D", "F", "WU", "FIN", "FAB"};
    double gradePoint[13] = {4.0, 4.0, 3.7, 3.3, 3.0, 2.7, 2.3, 2.0, 1.0, 0.0, 0.0, 0.0, 0.0};

    double totalCredits = 0;
    double totalGradePoints = 0;
    double points = 0;
    double gpa = 0;

    // variable to hold the condition of the user wanting to continue inputing
    char yes = 'y';

    // Welcoming user
    std::cout << "Welcome to Basic GPA Calculator!" << std::endl;
    std::cout << "Enter input as such: '3A'" << std::endl;

    // While loop to keep going until user is done inputing credits and grades
    while (yes == 'y' || yes == 'Y') {
        // Take in user input which includes credits and letter grade
        std::cout << "Enter class credits and grade: ";
        std::cin >> input;

        credit = "";
        grade = "";

        // Split the credits and letter grade and store it into variables
        credit = credit + input[0];

        for (int i = 1; i < input.length(); i++) {
            grade = grade + input[i];
        }

        // Convert the credits from string into an int using ASCII and type casting
        credits = credit[0] - '0';

        // Makes lowercase letters uppercase
        for (int i = 0; i < grade.length(); i++) {
            if (grade[i] >= 'a' && grade[i] <= 'z') {
                grade[i] = grade[i] - 32;
            }
        }

        points = -1;

        // Switch statements to convert the letter grade into a grade point
        switch (grade[0]) {
            case 'A':
                if (grade == "A+" || grade == "A") {
                    points = 4.0;
                }
                else if (grade == "A-") {
                    points = 3.7;
                }
                break;

            case 'B':
                if (grade == "B+") {
                    points = 3.3;
                }
                else if (grade == "B") {
                    points = 3.0;
                }
                else if (grade == "B-") {
                    points = 2.7;
                }
                break;

            case 'C':
                if (grade == "C+") {
                    points = 2.3;
                }
                else if (grade == "C") {
                    points = 2.0;
                }
                break;

            case 'D':
                if (grade == "D") {
                    points = 1.0;
                }
                break;

            case 'F':
                if (grade == "F" || grade == "FIN" || grade == "FAB") {
                    points = 0.0;
                }
                break;

            case 'W':
                if (grade == "WU") {
                    points = 0.0;
                }
                break;
        }

        // Checks if the credits and letter grade are valid
        if (credits > 0 && credits < 10 && points != -1) {
            // Adds one to the total number of classes
            totalClasses++;

            // Adds the current class credits to the total credits
            totalCredits = totalCredits + credits;

            // Adds the current class grade points to the total grade points
            totalGradePoints = totalGradePoints + credits * points;

            // Calculates the current semester GPA
            gpa = totalGradePoints / totalCredits;

            // Makes the GPA print with 2 numbers after the decimal
            std::cout.setf(std::ios::fixed);
            std::cout.precision(2);

            // Prints the total classes taken and the current semester GPA
            std::cout << "Classes taken: " << totalClasses
                      << ", Semester GPA: " << gpa << std::endl;
        }
        else {
            // Prints an error message if the credits or grade are invalid
            std::cout << "Invalid input." << std::endl;
        }
        // Asks the user if they want to keep going by adding another class
        std::cout << "Do you want to enter another class? y/n: ";
        std::cin >> yes;

        std::cout << std::endl;
    }
    // Tells user the program is done
    std::cout << "Program completed." << std::endl;

    return 0;
}