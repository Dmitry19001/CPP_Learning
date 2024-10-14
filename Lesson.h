#ifndef LESSON_H
#define LESSON_H

#include <string>
#include <iostream>

using namespace std;

class Lesson {
private:
    string name;
    void (*execute)();

public:
    Lesson(const string& lessonName, void (*runMethod)())
        : name(lessonName), execute(runMethod) {}

    void run() {
        cout << "\n\n" << name << endl;
        if (execute) {
            execute();
        }
        else {
            cout << "No function assigned to execute." << endl;
        }
    }

    string getName() const {
        return name;
    }
};

#endif
