#include <iostream>

#include "morse_code.h"

int main() {
	Morse_Code morseTest;
	std::string AllYourBase = morseTest.StringToMorse("All your base are belong to us!");
	std::string AreBelongToUs = morseTest.MorseToString(AllYourBase);

	std::cout << AllYourBase << "\n\n";
	std::cout << AreBelongToUs << "\n\n";

	return 0;
}