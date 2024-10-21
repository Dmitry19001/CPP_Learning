#include "utils.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
#include <cctype>
#include <vector>

void printWithDelay(const std::string& text, const int& delayMilliseconds) {
    for (char c : text) {
        std::cout << c;
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(delayMilliseconds));
    }
}

int getIntInput(const std::string& inputMessage, const std::string& errorMessage) {
    int input;
    while (true) {
        printWithDelay(inputMessage);
        std::cin >> input;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            printWithDelay(errorMessage);
        }
        else {
            break;
        }
    }
    return input;
}

float getFloatInput(const std::string& inputMessage, const std::string& errorMessage) {
    float input;
    while (true) {
        printWithDelay(inputMessage);
        std::cin >> input;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            printWithDelay(errorMessage);
        }
        else {
            break;
        }
    }
    return input;
}

char getCharInput(const std::string& inputMessage, const std::string& allowedChars, const std::string& errorMessage) {
    // Create an error message if none is provided
    const std::string error = !errorMessage.empty() ? errorMessage
        : "Invalid input. Please enter one of the following characters: " + allowedChars + "\n";

    char input;
    while (true) {
        printWithDelay(inputMessage);
        std::cin >> input;

        // Handle failed input extraction
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            printWithDelay(error);
            continue;
        }

        // If allowedChars is specified, check if the input character is allowed
        if (!allowedChars.empty() && allowedChars.find(input) == std::string::npos) {
            printWithDelay(error);
            continue;
        }

        break;
    }
    return input;
}

bool getBooleanInput(const std::string& inputMessage, const std::string& errorMessage) {
    bool result;
    std::string input;

    const std::vector<std::string> yesAnswers = { "yes", "y", "true" };
    const std::vector<std::string> noAnswers = { "no", "n", "false" };

    while (true) {
        printWithDelay(inputMessage);
        std::cin >> input;

        // Clear cin if input failed
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            printWithDelay(errorMessage);
            continue;
        }

        // Convert input to lowercase
        std::transform(input.begin(), input.end(), input.begin(),
            [](unsigned char c) { return std::tolower(c); });

        // Determine if input is in yesAnswers or noAnswers
        bool isYes = std::find(yesAnswers.begin(), yesAnswers.end(), input) != yesAnswers.end();
        bool isNo = std::find(noAnswers.begin(), noAnswers.end(), input) != noAnswers.end();

        // Handle invalid input
        if (!isYes && !isNo) {
            printWithDelay(errorMessage);
            continue;
        }

        // Assign result based on the answer
        result = isYes;  // If the input is a "yes" answer, result is true; otherwise, it's false
        break;
    }

    return result;
}
