#include <string>
#include <set>

#include "hangmanMan.h"
#include "hangmanWord.h"
#include "hangmanLexicon.h"

#ifndef HGAME_H
#define HGAME_H

class hangmanGame
{
private:
    hangmanLexicon words;
    hangmanWord word;
    hangmanMan* man;
    std::set<char> guesses_made;
    bool readyToPlay = false;
public:
    hangmanGame();
    hangmanGame(const std::string& word);
    ~hangmanGame();
    void play();
    void init(const std::string& word);
    void init();
    void keypress(unsigned char key, int x, int y);
    bool isReady(){
        return readyToPlay;
    }
};


#endif