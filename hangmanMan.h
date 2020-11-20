#include <iostream>

#ifndef HMAN_H
#define HMAN_H

class hangmanMan
{
private:
    int man;
public:
    hangmanMan();
    bool hang();
    void show();
    int getMan() const{
        return man;
    }
    void reset();

    void clearCanvas();

    void drawTree();
    void drawHead();
    void drawBody();    
    void drawFoot(int direction);
    void drawArm(int direction);

    void drawMan();

    void write(const char* str, int pos=0);
};

#endif