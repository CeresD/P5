// ===================================================================
//  tokenizer.cpp
// ===================================================================

#include "tokenizer.hpp"
#include <algorithm>

using namespace std;

// ===================================================================
StringTokenizer::StringTokenizer(string data, string delimiters) {
    _pos = 0;
    _data = data;
    _delimiters = delimiters;

    string::size_type lastPos = data.find_first_not_of(delimiters, 0);
    string::size_type pos = data.find_first_of(delimiters, lastPos);

    while (string::npos != pos || string::npos != lastPos) {
        // Found a token, add it to the vector
        _tokens.push_back(data.substr(lastPos, pos - lastPos));

        // Skip delimiters.  Note the "not_of"
        lastPos = data.find_first_not_of(delimiters, pos);

        // Find next "non-delimiter"
        pos = data.find_first_of(delimiters, lastPos);
    }
}

// ===================================================================
StringTokenizer::~StringTokenizer() {
    _tokens.clear();
}

// ===================================================================
int StringTokenizer::countTokens() {
    return _tokens.size();
}

// ===================================================================
string StringTokenizer::nextToken() {
    return _tokens[_pos++];
}

// ===================================================================
bool StringTokenizer::hasMoreTokens() {
    return _pos < _tokens.size();
}

