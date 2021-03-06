// The cross-reference program from §7.3/126 could be improved: As it stands, if
// a word occurs more than once on the same input line, the program will report
// that line multiple times.  Change the code so that it detects multiple
// occurrences of the same line number and inserts the line number only once.

#include <map>
#include <iostream>
#include <string>
#include <vector>
#include "split.h"

using std::cin;            using std::cout;
using std::endl;           using std::getline;
using std::istream;        using std::string;
using std::vector;         using std::map;




// find all the lines that refer to each word in the input
map<string, vector<int> > xref(istream& in,
			       vector<string> find_words(const string&) = split) {
    
    string line;
    int line_number = 0;
    map<string, vector<int> > ret;

    // read the next line
    while (getline(in, line)) {
	
	++line_number;

	// break the input line into words
	vector<string> words = find_words(line);

	// remember that each word occurs on the current line
	for (vector<string>::const_iterator it = words.begin(); it != words.end(); ++it) {

	    // case: we have not yet seen this line number for this word.  Note
	    // that the call to `ret[*it].back()' is always valid because if the
	    // key exists then an element was written to the vector at the time
	    // of initialization.
	    if (ret.find(*it) == ret.end() || ret[*it].back() != line_number) {
		ret[*it].push_back(line_number);
	    }
	}
    }
    return ret;
}




int main() {
    
    // call `xref' using `split' by default
    map<string, vector<int> > ret = xref(cin);

    // write the results
    for (map<string, vector<int> >::const_iterator it = ret.begin();
	 it != ret.end(); ++it) {
	// write the word
	cout << it->first << " occurs on line(s): ";

	// followed by one or more line numbers
	vector<int>::const_iterator line_it = it->second.begin();
	cout << *line_it;	// write the first line number

	++line_it;
	// write the rest of the line numbers, if any
	while (line_it != it->second.end()) {
	    cout << ", " << *line_it;
	    ++line_it;
	}
	// write a new line to separate each word from the next
	cout << endl;
    }

    return 0;
}

