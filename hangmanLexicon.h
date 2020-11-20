#include <string>
#include <vector>

#ifndef HLEXICON_H
#define HLEXICON_H

class hangmanLexicon
{
private:
    int wordCount;
    std::vector<std::string> words;
public:
    hangmanLexicon();
    int getWordCount() const{
        return wordCount;
    }
    std::string getWord(int index);
    std::string getRandomWord();
};

#endif