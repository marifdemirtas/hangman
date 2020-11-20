#include <GL/freeglut.h>
#include <string>
#include <iostream>

#include "hangmanGame.h"

using namespace std;

hangmanGame::hangmanGame()
{
    word = hangmanWord(words.getRandomWord());
    man = new hangmanMan();
    readyToPlay = true;
}

hangmanGame::hangmanGame(const std::string& word)
{
    this->word = hangmanWord(word);
    man = new hangmanMan();
    readyToPlay = true;
}

hangmanGame::~hangmanGame()
{
    delete man;
}

void hangmanGame::play()
{
    if (!readyToPlay){
        cout << "Please initialize the game using a word first." << endl;
    } else {
        man->write(word.getMaskedWord().data());
        readyToPlay = false;
        char c;
        while(true){
            cout << "Enter a guess: ";
            while (!(cin >> c)){
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Enter your guess as a single character: ";
            }
            if (this->guesses_made.insert(c).second == false){
                cout << "Already made that guess!" << endl;
            } else {
                int matches = 0;
                if((matches = word.guessLetter(c)) > 0){
                    cout << "Your letter shows up " << matches << " times." << endl; 
                    cout << "Word is " << word.getMaskedWord() << endl;
                } else {
                    cout << "Your letter does not show up." << endl;
                    if(man->hang()){
                        cout << "You lost, word was " << word.getWord() << endl;
                        cout << "Press q to quit." << endl;
                        man->write("Press q to quit.", 1);
                        while(cin.get() != 'q');
                        break;
                    }
                }
                man->write(word.getMaskedWord().data());
            } 
            if(word.isRevealed()){
                cout << "You know the word!" << endl;
                cout << "Press q to quit." << endl;
                man->write("Press q to quit.", 1);
                while(cin.get() != 'q');
                break;
            }
        }
        guesses_made.clear();
    }    
}

void hangmanGame::init(const string& word)
{
    this->word = hangmanWord(word);
    this->man->reset();
    readyToPlay = true;
}

void hangmanGame::init()
{
    this->word = hangmanWord(words.getRandomWord());
    this->man->reset();
    readyToPlay = true;
}
