#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Lesson.h"
#include "LessonManager.h"
#include "utils.h"

// Function to clear the console screen
static void clearScreen() {
    // ANSI escape sequence to clear the screen
    std::cout << "\033[2J\033[H";
}

// Function to move the cursor to a specific position in the console
static void moveCursor(int x, int y) {
    // ANSI escape sequence to move the cursor to position (x, y)
    std::cout << "\033[" << y << ";" << x << "H";
}

// Function for simple animation of random characters
static void simpleAnimation() {
    const int width = 40;
    const int height = 10;
    const int frames = 20;

    // Initialize random seed
    std::srand(static_cast<unsigned>(std::time(0)));

    // Characters to animate
    std::vector<char> symbols = { '*', '#', '@', '&', '%' };

    // Start animation loop
    for (int frame = 0; frame < frames; ++frame) {
        clearScreen();

        // Draw random characters in random positions
        for (int i = 0; i < 10; ++i) {
            int x = std::rand() % width + 1;
            int y = std::rand() % height + 1;
            char symbol = symbols[std::rand() % symbols.size()];

            moveCursor(x, y);
            std::cout << symbol;
        }

        // Delay between frames to create animation effect
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
}

// Function to display the final "Happy Birthday" message
static void happyBirthdayMessage() {
    clearScreen();
    moveCursor(10, 5);
    printWithDelay("С ДР, Вано!!!", 100);
    printWithDelay("Ебать ты дед теперь", 100);
}

// Function to run the lesson with ASCII animation
static void _runLessonAsciiAnimation() {
    printWithDelay("Инициализация анимации...\n");
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    // Show initial animation
    simpleAnimation();

    // Display the final message
    happyBirthdayMessage();
}

// Initialization function for ASCII Animation Lesson
void initializeLessonAsciiAnimation() {
    // Create the lesson and add it to LessonManager
    Lesson* lessonAsciiAnimation = new Lesson("Lesson X ASCII Animation: Fun with ASCII Art", _runLessonAsciiAnimation);
    LessonManager::addLesson(lessonAsciiAnimation);
}
