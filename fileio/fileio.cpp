#include <string>
#include <iostream>
#include <fstream>
#include "../includes/fileio.h"
#include "../includes/constants.h"


int writeFile(std::string &filename, char *contents) {
	std::ofstream myOutputFile;
	if (contents == NULL) {
			return INVALID_NULL_PTR_DETECTED;
		}

	myOutputFile.open(filename.c_str(), std::ios::out);
	myOutputFile << contents;
	myOutputFile.close();

	return SUCCESS;

}



int readFile(std::string &filename, std::string &contents) {
	std::ifstream inputFile;
	inputFile.open(filename.c_str());

	if (!inputFile.is_open()) {
		return FAIL_CANNOT_OPEN_FILE;
	}

	std::string line;
	while(!inputFile.eof()) {
		getline(inputFile, line);
		contents += line;
	}

	inputFile.close();
	return SUCCESS;
}
