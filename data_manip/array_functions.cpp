#include "../includes/array_functions.h"
#include "../includes/utilities.h"

using namespace std;
using namespace KP;
using namespace constants;

//remove all elements from vector that tracks words and their occurrences
namespace KP {
	void clear(std::vector<constants::entry>  &entries) {
		entries.clear();
	}

	//return how many unique words are in the vector
	int getSize(std::vector<constants::entry>  &entries) {
		return entries.size();
	}

	//get word at location i iff i<size(see above function), otherwise return the last word
	//(this is lazy, should throw an exception instead)
	std::string getWordAt(std::vector<constants::entry>  &entries, int i) {
		return entries.at(i).word.c_str();
	}

	//get number_occurences at location i iff i<size(see above function), otherwise return the last number_occurences
	//(this is lazy, should throw an exception instead)
	int getNumbOccurAt(std::vector<constants::entry>  &entries,int i) {
		if (i < entries.size()) {
			return entries.at(i).number_occurences;
		}
		else {
			return entries.at(-1).number_occurences;
		}
	}

	/*loop through the entire file, one line at a time
	 * call processLine on each line from the file
	 * returns false: myfstream is not open
	 *         true: otherwise*/
	bool processFile(std::vector<constants::entry>  &entries,std::fstream &myfstream) {
		if (!myfstream.is_open()) {
			return false;
		}
		std::string line;
		while (myfstream.eof() == false) {
			processLine(entries, line);
		}
		return true;

	}

	/*take 1 line and extract all the tokens from it
	feed each token to processToken for recording*/
	void processLine(std::vector<constants::entry>  &entries,std::string &myLine) {
		stringstream ss(myLine);
		string tempLine;
		while (getline(ss, tempLine, constants::CHAR_TO_SEARCH_FOR)) {
			processToken(entries, tempLine);
		}
	}

	/*NOTE: first call strip_unwanted_chars from utilities to get rid of rubbish chars in the token
	 * if the token is an empty string after this then return since we are not tracking empty strings
	 *
	 * Keep track of how many times each token seen, in other words look thru the entries vector that
	 * holds entry structs to see if there is a struct that has entry.word==token,
	 * if so increment entry.number_occurences, otherwise create a new entry struct for the token,
	 * set entry.number_occurences=1 and add it to the entries vector*/
	void processToken(std::vector<constants::entry>  &entries,std::string &token) {
		strip_unwanted_chars(token);
		for (int i = 0; i < entries.size(); i++) {
			if (entries[i].word == token) {
				entries[i].number_occurences += 1;
			}
			else {
				constants::entry newTokenEntry;
				newTokenEntry.word = token;
				newTokenEntry.number_occurences = 1;
				entries.push_back(newTokenEntry);
			}
		}
	}

	/*
	 * Sort entries based on so enum value.
	 * Please provide a solution that sorts according to the enum
	 * The presence of the enum implies a switch statement based on its value
	 * See the course lectures and demo projects for how to sort a vector of structs
	 */
	void sort(std::vector<constants::entry>  &entries, constants::sortOrder so){
//		switch (so) {
//		case sortOrder::NONE:
//
//		case sortOrder::ASCENDING:
//
//		case sortOrder::DESCENDING:
//
//		case sortOrder::NUMBER_OCCURRENCES:
//		}

	}

}
