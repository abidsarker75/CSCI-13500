#include <iostream>

int main()
{
    // Declaring variables
    double num1 = 0;
    double num2 = 0;
    char operation = ' ';

    // Asks user for two numbers
    std::cout << "Enter first number: ";
    std::cin >> num1;
    std::cout << "Enter second number: ";
    std::cin >> num2;

    // Asks user for operation
    std::cout << "Choose operation (+, -, *, /, %): ";
    std::cin >> operation;

    // Checks operation and calculates operation
    // Displays the final answer
    if (operation == '+')
    {
        std::cout << "Result: " << num1 + num2 << std::endl;
    }
    else if (operation == '-')
    {
        std::cout << "Result: " << num1 - num2 << std::endl;
    }
    else if (operation == '*')
    {
        std::cout << "Result: " << num1 * num2 << std::endl;
    }
    else if (operation == '%')
    {
        // Validate input
        if (num2 == 0)
        {
            std::cout << "Invalid input, cannot modulo by 0." << std::endl;
        }
        else
        {
            // Change double into int to modulo
            int number1 = num1;
            int number2 = num2;
            std::cout << "Result: " << number1 % number2 << std::endl;
        }
    }
    else if (operation == '/')
    {
        // Validate input
        if (num2 == 0)
        {
            std::cout << "Invalid input, cannot divide by 0." << std::endl;
        }
        else
        {
            std::cout << "Result: " << num1 / num2 << std::endl;
        }
    }
    else
    {
        // Validate input
        std::cout << "Invalid operation." << std::endl;
    }

    return 0;
}