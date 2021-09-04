#include <iostream>
#include "morse_code.cpp"

int main() {
	Morse_Code morseTest;
	std::string AllYourBase = morseTest.StringToMorse("All your base are belong to us!");
	std::string AreBelongToUs = morseTest.MorseToString(AllYourBase);

	std::cout << AllYourBase << "\n\n";
	std::cout << AreBelongToUs << "\n\n";

	getchar();
	return 0;
}