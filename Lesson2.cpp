#include <iostream>
#include "Lesson.h"
#include "LessonManager.h"
#include "utils.h"
#include <iomanip>
#include <sstream>  // Required for ostringstream

// Function to run Lesson 2 logic
static void _runLesson2() {
    int firstInt = getIntInput("Enter the first integer: ");
    int secondInt = getIntInput("Enter the second integer: ");
    float firstFloat = getFloatInput("Enter the first floating-point number: ");
    float secondFloat = getFloatInput("Enter the second floating-point number: ");
    bool divisionSuccessful = true;

    // Create an ostringstream to format the output
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(1);

    // Add formatted results to the ostringstream
    oss << "Results of Operations:"
        << "\n- " << firstInt << " + " << secondInt << " = " << (firstInt + secondInt)
        << "\n- " << firstFloat << " - " << secondFloat << " = " << (firstFloat - secondFloat)
        << "\n- " << firstInt << " * " << firstFloat << " = " << (firstInt * firstFloat);

    if (secondInt != 0) {
        oss << std::fixed << std::setprecision(6)
            << "\n- " << firstInt << " / " << secondInt << " = " << (static_cast<float>(firstInt) / static_cast<float>(secondInt)); // Fix int value not showing decimals
    }
    else {
        oss << "- Division by zero is not allowed.\n";
        divisionSuccessful = false;
    }

    // Use typeWithDelay to print the formatted string
    printWithDelay(oss.str());

    // Clearing for future use
    oss.str("");
    oss.clear();

    // Boolean logic section
    printWithDelay("\n\nNow let's try using some characters and boolean logic!\n");

    char inputOperation = getCharInput(
        "Enter a character representing the operation you want to perform('+', '-', '*', '/') : ",
        "+-*/"
    );

    int operationResult = 0;

    switch (inputOperation)
    {
    case '+':
        operationResult = firstInt + secondInt;
        break;
    case '-':
        operationResult = firstInt - secondInt;
        break;
    case '*':
        operationResult = firstInt * secondInt;
        break;
    case '/':
        if (secondInt != 0 && divisionSuccessful) {
            operationResult = firstInt / secondInt;
        }
        break;
    default:
        break;
    }

    if (secondInt != 0 && divisionSuccessful) {
        oss << "-The result of " << firstInt << " " << inputOperation << " " << secondInt << " is : " << operationResult << "\n\n";
    }
    else {
        oss << "Division by zero is not allowed.\n";
    }

    oss << "Division check :\n"
        << "-Was the division operation successful without dividing by zero ? " << (divisionSuccessful ? "Yes" : "False");

    printWithDelay(oss.str());
    // Clearing oss
    oss.str("");
    oss.clear();
}

// Initialization function for Lesson 2
void initializeLesson2() {
    // Create the lesson and add it to LessonManager
    Lesson* lesson2 = new Lesson("Lesson 2: Variables, Data Types, and Operators", _runLesson2);
    LessonManager::addLesson(lesson2);
}
