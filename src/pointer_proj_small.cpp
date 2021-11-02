//============================================================================
// Name        : pointer_proj_small.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
using namespace std;
#include "../includes/constants.h"
#include "../includes/stringmanip.h"
#include "../includes/fileio.h"


int main(int argc, char *argv[]) {	
	//TODO Get commandline arguments
	if (argc != EXPECTED_NUMBER_ARGUMENTS) {
		cout <<HELP_STRING1<<endl;
		return FAIL_WRONG_NUMBER_ARGS;
	}
	string infile = argv[1];
	string outfile = argv[2];
	string tag = argv[3];
	string tag_replacement = argv[4];
	string src;
	int numbTagsToReplace;



	char* tag_Char = new char[tag.length() + 1];
	std::copy(tag.begin(), tag.end(), tag_Char);

	char* tag_Replacement_Char = new char[tag_replacement.length() + 1 ];
	std::copy(tag_replacement.begin(), tag_replacement.end(), tag_Replacement_Char);

	//TODO can we read file? Fail if not
	int readability = readFile(infile,src);
	if (readability == FAIL_CANNOT_OPEN_FILE) {
		return FAIL_CANNOT_OPEN_FILE;
	}

	char* src_Char = new char[src.length() + 1];
	std::copy(src.begin(), src.end(), src_Char);

	//TODO how many tags found in file?
	numbTagsToReplace = KP::findNumbOccurrences(src_Char, tag_Char);
	int src_length = 0;
	while(src[src_length] != '\0') {
		src_length++;
	}

	int tag_length = 0;
	while(tag[tag_length] != '\0') {
		tag_length++;
	}
	
	int tag_replacement_length = 0;
	while(tag_replacement[tag_replacement_length] != '\0') {
		tag_replacement_length++;
	}


	//TODO allocate memory
	int amountToAllocate = KP::amountOfMemoryToAllocateForNewString(src_length, numbTagsToReplace, tag_length, tag_replacement_length);
	char* new_src = new char[amountToAllocate + 1];


	//TODO replace original tag with new tags
	int work = KP::replace(src_Char, new_src, tag_Char, tag_Replacement_Char);

	writeFile(outfile, new_src);

	//TODO deallocate any memory allocated

	if (tag_Replacement_Char) {
		delete tag_Replacement_Char;
	}

	if (src_Char) {
		delete[] src_Char;
	}

	if (new_src) {
		delete[] new_src;
	}

	if (tag_Char) {
		delete[] tag_Char;
	}


	return SUCCESS;


