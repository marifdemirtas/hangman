#include <GL/freeglut.h>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>

#include "hangmanMan.h"

hangmanMan::hangmanMan()
{
    man = 0;
    glutCreateWindow("HANGMAN");

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBegin(GL_LINES);
            glVertex2d(-0.4, -0.4); //TREE
            glVertex2d(-0.4, 0.9);

            glVertex2d(-0.4, 0.9); //TREE
            glVertex2d(0.2, 0.9);

            glVertex2d(0.2, 0.9); //TREE
            glVertex2d(0.2, 0.8);
    glEnd();
    glutSwapBuffers();
}

bool hangmanMan::hang()
{
    if(++man == 6){
        return true;
    } else {
        return false;
    }
}

void hangmanMan::show()
{
    std::cout << 6-man << " tries left." << std::endl;
}

void hangmanMan::reset()
{
    man = 0;
    this->clearCanvas();
}

void hangmanMan::drawMan(){
    drawTree();
    if(man > 0){
        drawHead();
    }if(man > 1){
        drawBody();
    }if(man > 2){
        drawArm(0);
    }if(man > 3){
        drawArm(1);
    }if(man > 4){
        drawFoot(0);
    }if(man > 5){
        drawFoot(1);
    }
}

void hangmanMan::write(const char* str, int pos)
{
    if (pos == 0){
        this->clearCanvas();
    }
    this->drawMan();

    const unsigned char* displayString = reinterpret_cast<const unsigned char*>(str);
    if (pos == 0){
        glRasterPos2f(-0.80, -0.60);
    }else if(pos == 1){
        glRasterPos2f(-0.80, -0.80);
    }
    glutBitmapString(GLUT_BITMAP_HELVETICA_18, displayString);
    glutSwapBuffers();

}

void hangmanMan::clearCanvas()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);    
}

void hangmanMan::drawTree()
{
    glBegin(GL_LINES);
            glVertex2d(-0.4, -0.4); //TREE
            glVertex2d(-0.4, 0.9);

            glVertex2d(-0.4, 0.9); //TREE
            glVertex2d(0.2, 0.9);

            glVertex2d(0.2, 0.9); //TREE
            glVertex2d(0.2, 0.8);
    glEnd();
    glutSwapBuffers();
}

void hangmanMan::drawHead()
{
    float t = 0;
    glBegin(GL_LINE_LOOP);
        for(int i = 0; i < 20; ++i){
            glVertex2f((0.2 + 0.125 * cos(t)), (0.675 + 0.125 * sin(t)));
            t += 2 * 3.14159 / 20;
        }
    glEnd();
    glutSwapBuffers();
}

void hangmanMan::drawBody()
{
    glBegin(GL_LINES);
        glVertex2d(0.2, 0.55); //BODY
        glVertex2d(0.2, 0.05);
    glEnd();
    glutSwapBuffers();
}


/** @param direction {int} - 0 for left arm, 1 or nonzero for right arm */ 
void hangmanMan::drawArm(int direction)
{
    glBegin(GL_LINES);
        switch (direction){
        case 0:
            glVertex2d(0.2, 0.45); //LEFT ARM 1
            glVertex2d(0.0, 0.45); 

            glVertex2d(0.0, 0.45); //LEFT ARM 2
            glVertex2d(0.0, 0.25); 
            break;
        case 1:
        default:
            glVertex2d(0.2, 0.45); //RIGHT ARM 1
            glVertex2d(0.4, 0.45); 

            glVertex2d(0.4, 0.45); //RIGHT ARM 2
            glVertex2d(0.4, 0.25);
            break;
        }
    glEnd();
    glutSwapBuffers();
}

/** @param direction {int} - 0 for left foot, 1 or nonzero for right foot */ 
void hangmanMan::drawFoot(int direction)
{
    glBegin(GL_LINES);
        switch (direction){
        case 0:
            glVertex2d(0.2, 0.05); //LEFT FOOT 1
            glVertex2d(0.1, 0.05);

            glVertex2d(0.1, 0.05); //LEFT FOOT 2
            glVertex2d(0.1, -0.40);

            glVertex2d(0.1, -0.40); //LEFT FOOT 3
            glVertex2d(0.0, -0.40);
            break;
        case 1:
        default:
            glVertex2d(0.2, 0.05); //RIGHT FOOT 1
            glVertex2d(0.3, 0.05);

            glVertex2d(0.3, 0.05); //RIGHT FOOT 2
            glVertex2d(0.3, -0.40);

            glVertex2d(0.3, -0.40); //RIGHT FOOT 3
            glVertex2d(0.4, -0.40);
            break;
        }
    glEnd();
    glutSwapBuffers();
}

