#include <iostream>
#include "Lesson.h"
#include "LessonManager.h"

void initializeLesson1();

using namespace std;

vector<Lesson*> LessonManager::lessons;

int main() {
    initializeLesson1();

    int lessonNumber = 1;
    const int totalLessons = LessonManager::getLessonsCount();  // Update this as you add more lessons


    while (lessonNumber != 0) {
        cout << "\n\nWhich lesson do you want to choose? (Enter number from 1 to " << totalLessons - 1 << " or 0 to exit): ";
        cin >> lessonNumber;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore the rest of the input
            cout << "Invalid input. Please enter a valid number." << endl;
            continue; 
        }

        if (lessonNumber == 0) {
            cout << "\n\nExiting program..." << endl;
            continue;
        }

        // Check if input is within the valid range
        if (lessonNumber < 0 || lessonNumber >= totalLessons) {
            cout << "Invalid lesson number. Please enter a number between 1 and " << totalLessons - 1 << "." << endl;
            continue;
        }

        // Call the selected lesson function
        LessonManager::getLessons()[lessonNumber - 1]->run();
    }

    // Cleanup to avoid memory leaks
    LessonManager::cleanup();

    return 0;
}