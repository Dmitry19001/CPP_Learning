#include "utils.h"
#include <iostream>
#include <thread>
#include <chrono>

void typeWithDelay(const std::string& text, int delayMilliseconds) {
    for (char c : text) {
        std::cout << c;
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(delayMilliseconds));
    }
}
