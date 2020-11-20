#include <string>
#include <cstdio>
#include <ctime>

#include "hangmanLexicon.h"

hangmanLexicon::hangmanLexicon()
{
    srand(time(NULL));
/*
    words.push_back("BUOY");
    words.push_back("COMPUTER");
    words.push_back("CONNOUSSEUR");
    words.push_back("DEHYDRATE");
    words.push_back("FUZZY");
    words.push_back("HUBBUB");
    words.push_back("KEYHOLE");
    words.push_back("QUAGMIRE");
    words.push_back("SLITHER");
    words.push_back("ZIRCON");
*/

    words.push_back("Vatan");
    words.push_back("Gönenç");
    words.push_back("Hayat");
    words.push_back("Gökyüzü");
    words.push_back("Deniz");
    words.push_back("Gönül");
    words.push_back("Kof");
    words.push_back("Kutlu");

    wordCount = words.size();
}

std::string hangmanLexicon::getWord(int index)
{
    return words[index];
}

std::string hangmanLexicon::getRandomWord()
{
    return words[rand() % wordCount];
}
