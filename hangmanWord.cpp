#include <string>
#include <iostream>

#include "hangmanWord.h"

using namespace std;

hangmanWord::hangmanWord(const string word)
{
    this->word = word;
    for (auto & c: this->word) c = toupper(c);

    this->mask = string(word.length(), '_');
    this->revealed = false;
}

int hangmanWord::guessLetter(char c)
{
    c = toupper(c);
    int pos = 0;
    int matches = 0;;
    while ((pos = word.find(c, pos)) != string::npos){
        matches++;
        mask[pos] = '*';
        if(++pos == word.length()){
            break;
        }
    }
    if (matches > 0 && mask.find('_') == string::npos){
        revealed = true;
    }
    return matches;
}

string hangmanWord::getMaskedWord() const
{
    string maskedWord = mask;
    for(int i = 0; i < word.length(); i++){
        if (mask[i] == '*'){
            maskedWord[i] = word[i];        
        }
    }
    return maskedWord;
}

string hangmanWord::getWord() const
{
    return word;
}

hangmanWord& hangmanWord::operator=(const hangmanWord& word)
{
    revealed = false;
    this->word = word.getWord();
    this->mask = string(this->word.length(), '_');
}

hangmanWord& hangmanWord::operator=(const string& word)
{
    revealed = false;
    this->word = word;
    this->mask = string(word.length(), '_');
}
