#include<Windows.h>
#include<iostream>
#include<sstream>
#include<ponglib.h>

int main(){

    bool playing = true;
    int score[2] = {0, 0};

    int pressedKey = 0;
    short pressing[256], pressed[256];

    int padX[2];
    padX[0] = leftBound + boardOffset;
    padX[1] = rightBound - boardOffset;

    COORD ball;
    ball.X = ballStartX;
    ball.Y = ballStartY;

    drawGame(upperBound, lowerBound, leftBound, rightBound);

    printCenter("Press SPACEBAR to start.");
    while(!(GetKeyState(' ') & 0x8000));
    printCenter("                        ");

    while(1){
        Sleep(1000/frameRate);

        //getting all key states
        pressedKey = 0;
        for(int i = 0; i < 256; i++){
            pressing[i] = GetKeyState(i) & 0x8000;
            if(pressing[i]) pressedKey++;
        }

        if(playing){
            //update scores
            if(ball.X + ballVx == leftBound) score[1]++;
            if(ball.X + ballVx == rightBound) score[0]++;

            drawScore(score[0], score[1]);

            //stringstream ss;
            //ss << "x = " << ball.X << ", y = " << ball.Y;

            drawBall(ball.X, ball.Y, " ");

            if(ball.X + ballVx == leftBound || ball.X + ballVx == rightBound) ballVx = -ballVx;
            if(ball.Y + ballVy == upperBound || ball.Y + ballVy == lowerBound) ballVy = -ballVy;
            if(ball.X + ballVx == padX[0] && ball.Y + ballVy >= padY[0] && ball.Y + ballVy < padY[0] + padLen ||
                ball.X + ballVx == padX[1] && ball.Y + ballVy >= padY[1] && ball.Y + ballVy < padY[1] + padLen)
                        ballVx = -ballVx;

            ball.X += ballVx;
            ball.Y += ballVy;
            drawBall(ball.X, ball.Y, "O");

            //ss << " -- new x = " << ball.X << ", y = " << ball.Y << "          ";
            //debug(ball, ss.str());

            drawPad(0, padY[0], padX[0], padLen, " ");
            drawPad(1, padY[1], padX[1], padLen, " ");


            if(pressing['L'] && ! pressed['L']) padY[1] = padY[1] >= lowerBound - padLen ? padY[1] : padY[1] + 1;
            if(pressing['O'] && ! pressed['O']) padY[1] = padY[1] <= upperBound + 1 ? padY[1] : padY[1] - 1;

            if(pressing['S'] && ! pressed['S']) padY[0] = padY[0] >= lowerBound - padLen ? padY[0] : padY[0] + 1;
            if(pressing['W'] && ! pressed['W']) padY[0] = padY[0] <= upperBound + 1 ? padY[0] : padY[0] - 1;

            drawPad(0, padY[0], padX[0], padLen, "#");
            drawPad(1, padY[1], padX[1], padLen, "#");
        } else {

        }

        if(pressing[' '] && ! pressed[' ']){
            playing = !playing;
            if(!playing){
                printCenter("PAUSED");
            } else {
                printCenter("                        ");
            }
        }

        //propagate key states as 'pressed'
        for(int i = 0; i < 256; i++)
            pressed[i] = pressing[i];
    }
}
