#include <iostream>
#include "Lesson.h"
#include "LessonManager.h"
#include "utils.h"

// Recursive function to get a valid age
static int _getValidAge() {
    // Do not use self recursion, could cause stack overflow in complex scenarios
    int age = getIntInput("Enter your age: ");

    return age;
}

// Function to run Lesson 1 logic
static void _runLesson1() {
    std::string name = "Unknown";
    int age = 0;

    printWithDelay("This is Lesson 1: C++ Basics and Setup\n");
    printWithDelay("Enter your name:\n");
    std::cin >> name;

    // Get a valid age
    age = _getValidAge();

    // Construct the greeting message
    std::string greeting = "Hello, " + name + "! You are " + std::to_string(age) + " years old.\n";
    printWithDelay(greeting);
}

// Initialization function for Lesson 1
void initializeLesson1() {
    // Create the lesson and add it to LessonManager
    Lesson* lesson1 = new Lesson("Lesson 1: Advanced Lesson Example", _runLesson1);
    LessonManager::addLesson(lesson1);
}
