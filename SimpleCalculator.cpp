#include <iostream>

int main() {
    double num1, num2;
    char operation;

    // Input the two numbers
    std::cout << "Enter the first number: ";
    std::cin >> num1;
    std::cout << "Enter the second number: ";
    std::cin >> num2;

    // Input the operation
    std::cout << "Choose an operation (+, -, *, /): ";
    std::cin >> operation;

    double result;

    // Perform the selected operation and display the result
    switch (operation) {
        case '+':
            result = num1 + num2;
            std::cout << "Result: " << result << std::endl;
            break;
        case '-':
            result = num1 - num2;
            std::cout << "Result: " << result << std::endl;
            break;
        case '*':
            result = num1 * num2;
            std::cout << "Result: " << result << std::endl;
            break;
        case '/':
            if (num2 == 0) {
                std::cout << "Error: Division by zero is not allowed." << std::endl;
            } else {
                result = num1 / num2;
                std::cout << "Result: " << result << std::endl;
            }
            break;
        default:
            std::cout << "Invalid operation. Please choose +, -, *, or /." << std::endl;
    }

    return 0;
}
