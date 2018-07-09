// ===================================================================
//  tokenizer.hpp
// ===================================================================

#ifndef _TOKENIZER_HPP
#define _TOKENIZER_HPP

#include <string>
#include <vector>

// ===================================================================
class StringTokenizer {
private:
    std::string _data;
    std::string _delimiters;
    unsigned int _pos;
    std::vector<std::string> _tokens;

public:
    StringTokenizer(std::string data, std::string token);
    ~StringTokenizer();
    int countTokens();
    std::string nextToken();
    bool hasMoreTokens();
};

#endif

