#ifndef UTILS_H
#define UTILS_H

#include <string>

void printWithDelay(
	const std::string& text,
	const int& delayMilliseconds = 30
);
int getIntInput(
	const std::string& inputMessage,
	const std::string& errorMessage = "Invalid input. Please enter a valid numerical value.\n"
);
float getFloatInput(
	const std::string& inputMessage,
	const std::string& errorMessage = "Invalid input. Please enter a valid numerical value.\n"
);
char getCharInput(
	const std::string& inputMessage,
	const std::string& allowedChars = "",
	const std::string& errorMessage = ""
);
bool getBooleanInput(
	const std::string& inputMessage,
	const std::string& errorMessage = "Invalid input. Please enter either yes (y) or no (n)"
);

#endif // UTILS_H
