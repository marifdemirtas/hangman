#include <GL/freeglut.h>
#include <cstdlib>
#include <cmath>

#include <iostream>
#include <ctime>
#include <cstdio>

#include "hangmanGame.h"

using namespace std;

int main(int argc, char* argv[]){
    glutInit(&argc, argv);

    glutInitWindowPosition(100, 100);
    glutInitWindowSize(320, 320);
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);

    hangmanGame game;
    if(argc > 1){
        game.init(argv[1]);
    }
    while(true){
        game.play();
        char playAgain;
        cout << "Do you want to play again? (Y/N): ";
        cin >> playAgain;
        if(playAgain == 'Y'){
            game.init();
        } else {
            break;
        }
    }
    
    return 0;
}