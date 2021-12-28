#include <stack>

#include "morse_code.h"

/* Input is a character; converts it to its morse code equivalent as a string. Example: CharToMorse('G') -> "--." */
std::string Morse_Code::CharToMorse(char c) {
	/* Convert the character to lowercase. If the character is not a letter, exit the function.	*/
	c = tolower(c);
	if (c > 123 || c < 96)
		return "";

	/*
	pos:	Will first be set to the location of the character in tree; then it will change as program traverses the tree back to the root.
	code:	Temporary storage (as a stack) for the dashes and dots while the conversion is happening.
	str:	This string is where the morse code conversion will be stored after program is finished converting.
	*/
	int pos;
	std::stack<char> code;
	std::string str;

	/* Find the position of the character in the tree. */
	for (pos = 0; pos < 29; pos++) {
		if (c == Morse_Tree[pos])
			break;
	}

	while (pos > 0) {
		/* Even numbers are the root of the right sub-tree, which is indicated with a dash. */
		if (pos % 2 == 0)
			code.push('-');

		/* Odd number must be in the left sub-tree, which is indicated with a dot. */
		else
			code.push('.');

		/* Set the position to the parent node and repeat the process. */
		pos = (pos - 1) / 2;
	}

	/* Empty the stack into the string to reverse the order. */
	while (!code.empty()) {
		str += code.top();
		code.pop();
	}

	/* Return the morse code equivalent of the input character. */
	return str;
}

/* Input is morse code for a single character; converts it to its alphabetical character equivalent as a char. Example: MorseToChar("--.") -> 'G' */
char Morse_Code::MorseToChar(const std::string str) {
	int pos = 0;

	for (int i = 0; i < str.length(); i++) {
		/* If the character is a dot, go to the left sub-tree. */
		if (str[i] == '.')
			pos = 2 * pos + 1;
		/* If the character is a dash, go to the right sub-tree. We do an elif instead of an else because we want to sanitize input. */
		else if (str[i] == '-')
			pos = 2 * pos + 2;
	}

	/* When loop has checked every character, the position in the tree will be at the correct spot for the data. First, do a check to sanitize the input of
	the function. If the position isn't a null child (# symbol), and it's not greater than the number of elements in our tree, return the character. */
	if (Morse_Tree[pos] != '#' && pos < 29)
		return Morse_Tree[pos];

	/* If the input wasn't an acceptable morse code, assume it's a space; if spaces are appearing where they shouldn't, there is an error with input. */
	return ' ';
}

/* Input is a alphabetical string of characters; converts all character to their morse code equivalents. */
std::string Morse_Code::StringToMorse(std::string str) {
	std::string MorseConversion;

	/* For each character in the input string, pass it into the CharToMorse method. Store the result in a string with a space to represent a delimeter. */
	for (int i = 0; i < str.length(); i++) {
		MorseConversion += CharToMorse(str[i]);
		MorseConversion += ' ';
	}

	/* Return our stored result. */
	return MorseConversion;
}

/* Input is multiple characters in morse code each separated by spaces; converts all code to their alphabetical equivalent. A single space separates characters,
and a double space separates words. */
std::string Morse_Code::MorseToString(std::string str) {
	std::string LetterConversion;
	std::string character;

	/* Add each character to the string `character`. Once we reach our delimiting character, pass the collected dots and dashes into MorseToChar method. */
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ' ') {
			LetterConversion += MorseToChar(character);
			character = "";
		}
		else
			character += str[i];
	}

	/* Return our stored result. */
	return LetterConversion;
}
