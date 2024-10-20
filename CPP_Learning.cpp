#include <iostream>
#include "Lesson.h"
#include "LessonManager.h"
#include "utils.h"

void initializeLesson1();
void initializeLessonBsod();

using namespace std;

vector<Lesson*> LessonManager::lessons;

int main() {
    initializeLesson1();
    initializeLessonBsod();

    int typeDelay = 10;
    unsigned int lessonNumber = 1;
    const int totalLessons = LessonManager::getLessonsCount();  // Update this as you add more lessons

    while (lessonNumber != 0) {
        string choicePrompt = "\n\nWhich lesson do you want to choose? (Enter number from 1 to " + to_string(totalLessons - 1) + " or 0 to exit): ";
        typeWithDelay(choicePrompt, typeDelay);
        cin >> lessonNumber;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore the rest of the input
            typeWithDelay("Invalid input. Please enter a valid number.\n", typeDelay);
            continue;
        }

        if (lessonNumber == 0) {
            typeWithDelay("\n\nExiting program...\n", typeDelay);
            continue;
        }

        // Check if input is within the valid range
        if (lessonNumber < 0 || lessonNumber >= totalLessons) {
            string invalidRangePrompt = "Invalid lesson number. Please enter a number between 1 and " + to_string(totalLessons - 1) + ".\n";
            typeWithDelay(invalidRangePrompt, typeDelay);
            continue;
        }

        // Store the adjusted index in a signed variable to avoid unsigned overflow
        int lessonIndex = static_cast<int>(lessonNumber) - 1;

        // Safely call the selected lesson function
        if (lessonIndex >= 0 && lessonIndex < static_cast<int>(LessonManager::getLessons().size())) {
            LessonManager::getLessons()[lessonIndex]->run();
        }
        else {
            typeWithDelay("Unexpected error: Lesson index out of bounds.\n", typeDelay);
        }
    }

    // Cleanup to avoid memory leaks
    LessonManager::cleanup();

    return 0;
}
