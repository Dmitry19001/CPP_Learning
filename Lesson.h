#ifndef LESSON_H
#define LESSON_H

#include <string>
#include <iostream>
#include "utils.h"

class Lesson {
private:
    bool isVisible;
    std::string name;
    void (*execute)();

public:
    Lesson(
        const std::string& lessonName,
        void (*runMethod)(),
        bool isVisible = true
    )
        : name(lessonName), execute(runMethod), isVisible(isVisible) {}

    void run() {
        std::cout << "\n\n" << name << std::endl;
        if (execute) {
            execute();
        }
        else {
            printWithDelay("No function assigned to execute.");
        }
    }

    std::string getName() const {
        return name;
    }

    bool getIsVisible() const {
        return isVisible;
    }
};

#endif
