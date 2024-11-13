#include <iostream>
#include "Lesson.h"
#include "LessonManager.h"
#include "utils.h"
#include <iomanip>
#include <sstream>  // Required for ostringstream

// Function to run Lesson 3 logic
static void _runLesson3() {

}

// Initialization function for Lesson 3
void initializeLesson3() {
    // Create the lesson and add it to LessonManager
    Lesson* lesson3 = new Lesson("Lesson 3: Control Flow and Functions", _runLesson3);
    LessonManager::addLesson(lesson3);
}
