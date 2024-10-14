#ifndef LESSON_MANAGER_H
#define LESSON_MANAGER_H

#include "Lesson.h"
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class LessonManager {
public:
    // Add a lesson to the collection
    static void addLesson(Lesson* lesson) {
        lessons.push_back(lesson);
    }

    // Get all lessons
    static const vector<Lesson*>& getLessons() {
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
    static vector<Lesson*> lessons;
};

#endif
