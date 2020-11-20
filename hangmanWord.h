#ifndef HWORD_H
#define HWORD_H

#include <string>

class hangmanWord
{
private:
    std::string word;
    std::string mask;
    bool revealed;
public:
    hangmanWord(const std::string word);
    hangmanWord() = default;
    int guessLetter(char c);
    std::string getMaskedWord() const;
    std::string getWord() const;
    bool isRevealed(){
        return revealed;
    }
    hangmanWord& operator=(const hangmanWord& word);
    hangmanWord& operator=(const std::string& word);
};

#endif