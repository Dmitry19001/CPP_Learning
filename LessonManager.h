#ifndef LESSON_MANAGER_H
#define LESSON_MANAGER_H

#include "Lesson.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include "utils.h"

class LessonManager {
public:
    // Add a lesson to the collection
    static void addLesson(Lesson* lesson) {
        lessons.push_back(lesson);
        if (lesson->getIsVisible()) {
            printWithDelay(lesson->getName() + " loaded successfully\n", 5);
        }
    }

    // Get all lessons
    static const std::vector<Lesson*>& getLessons() {
        return lessons;
    }

    // Get the number of lessons
    static int getLessonsCount() {
        return static_cast<int>(lessons.size()) + 1;
    }

    // Cleanup method to delete all lessons
    static void cleanup() {
        for (Lesson* lesson : lessons) {
            delete lesson;
        }
        lessons.clear();
    }

private:
    static std::vector<Lesson*> lessons;
};

#endif
