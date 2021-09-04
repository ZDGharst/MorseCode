#pragma once

#include <string>

class Morse_Code {
	/* A binary tree consisting of all 26 alphabetical English characters in order. The # symbol represents a null node. */
	const char *Morse_Tree = "#etianmsurwdkgohvf#l#pjbxcyzq";

public:
	std::string CharToMorse(char c);
	char MorseToChar(std::string str);
	std::string StringToMorse(std::string str);
	std::string MorseToString(std::string str);
};