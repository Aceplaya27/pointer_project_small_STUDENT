#include "../includes/stringmanip.h"
#include "../includes/constants.h"

namespace KP{

int amountOfMemoryToAllocateForNewString(int len_src, int numbTagsToReplace, int len_tag, int len_tag_replacement){
	return (len_src + len_tag_replacement + numbTagsToReplace - len_tag);
}

int replace(const char *src, char *new_src, const char *tag, const char *tag_replacement) {
	std::string check;
	int length_tag = 0;
	int length_tag_replacement = 0;
	int length_src = 0;
	int i = 0;
	int k;
	if (src == NULL || tag == NULL || tag_replacement == NULL) {
		return INVALID_NULL_PTR_DETECTED;
	}

	while(src[length_src] != '\0') {
		length_src++;
	}

	while(tag[length_tag] != '\0') {
		length_tag++;
	}
	while(tag_replacement[length_tag_replacement] != '\0') {
		length_tag_replacement++;
	}

	while(i < length_src) {
		if(src[i] == tag[0]) {
			for (int j = 0; j < length_tag; j++) {
				check[j] = src[i + j];
			}
			if (check == tag) {
					for (k = 0; k < length_tag_replacement; k++) {
						new_src[i + k] == tag_replacement[k];
					}
					i += k;
				}
		}
		else {

		i++;
		}
		return SUCCESS;

	}







}

int findNumbOccurrences(const char *src,  const char *tag){

	std::string occurence = "";

	if (src == NULL || tag == NULL) {
		return INVALID_NULL_PTR_DETECTED;
	}

	int count = 0;
	int src_length = 0;
	while(src[src_length] != '\0') {
		src_length++;
	}

	int tag_length = 0;
	while(tag[tag_length] != '\0') {
		tag_length++;
	}


	for (int i = 0; i < src_length; i++) {
		if (src[i] == tag[0]) {
			for (int j = 0; j < tag_length; j++) {
				occurence[j] = src[i + j];
				}
			if (occurence == tag) {
				count++;
				occurence = "";
			}
			else {
				occurence = "";
			}
		}
	}
	return count;
}


}
