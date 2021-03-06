// Devin_Brewer_COSC2030_Lab1

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

int main()
{
	// Create a stream to the file
	std::ifstream fin;

	std::cout << "Enter the name for the file: ";
	std::string fileName = "";

	std::cin >> fileName;

	fin.open("../" + fileName);

	// Attempt to open the file
	if (fin.fail()) {
		// Unsuccessful, alert the user and halt
		std::cout << "Error reading file: Could not open!\n";
		system("pause");
		return 0;
	}
	
	// File opened successfully, record the numbers
	int numCount = 0;
	double numInput, first = NULL, second = NULL, secondLast = NULL, last = NULL;

	while (fin >> numInput) {
		numCount += 1;

		// Set the values for the last couple numbers
		secondLast = last;
		last = numInput;

		// Get the values for the first and second
		if (first == NULL) {
			first = numInput;
		}
		else if (second == NULL & first != NULL) {
			second = numInput;
		}
	}

	// Output the results
	std::cout << "Count: " << numCount << "\n";
	std::cout << "First: " << first << "\n";
	std::cout << "Second: " << second << "\n";
	std::cout << "Second to Last: " << secondLast << "\n";
	std::cout << "Last: " << last << "\n";

	// Close the file and exit the program
	fin.close();
	system("pause");
    return 0;
}

