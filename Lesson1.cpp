#include <iostream>
#include "Lesson.h"
#include "LessonManager.h"

using namespace std;

// Recursive function to get a valid age
static int _getValidAge() {
    // Do not use self recursion, could cause stack overflow in complex scenarios
    int age;
    while (true) {
        cout << "Enter your age: " << endl;
        cin >> age;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid numerical age." << endl;
        }
        else {
            break;
        }
    }
    return age;
}

// Function to run Lesson 1 logic
static void _runLesson1() {
    string name = "Unknown";
    int age = 0;

    cout << "This is Lesson 1: C++ Basics and Setup" << endl;
    cout << "Enter your name:" << endl;
    cin >> name;

    // Get a valid age
    age = _getValidAge();

    cout << "Hello, " << name << "! You are " << age << " years old." << endl;
}

// Initialization function for Lesson 1
void initializeLesson1() {
    // Create the lesson and add it to LessonManager
    Lesson* lesson1 = new Lesson("Lesson 1: Advanced Lesson Example", _runLesson1);
    LessonManager::addLesson(lesson1);
}
