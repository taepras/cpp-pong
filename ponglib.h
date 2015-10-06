#ifndef _CPP_PONG_LIB_
#define _CPP_PONG_LIB_

#include "pongconfig.h"
#include<string>
#include<iostream>

using namespace std;

void debug(COORD currentPos, string text){
    COORD debug;
    debug.X = 10;
    debug.Y = 25;
    SetConsoleCursorPosition(hStdOut, debug);
    cout << text;
    SetConsoleCursorPosition(hStdOut, currentPos);
}

void printAt(int x, int y, string text){
    COORD print;
    print.X = x;
    print.Y = y;
    SetConsoleCursorPosition(hStdOut, print);
    cout << text;
}

void printCenter(string text){
    printAt(middleX - text.length() / 2, middleY, text);
}

void drawGame(int ub, int lb, int lfb, int rtb){
    for(int i = 0; i <= lb + 4; i++){
        for(int j = 0; j <= rtb; j++)
            if(i < ub || j < lfb)
                cout << " ";
            else if(i == ub || i == lb || i == lb + 4 || j == lfb || j == rtb)
                cout << "X";
            else
                cout << " ";
        cout << endl;
    }

    string s = " PLAYER 1 vs PLAYER 2 ";
    printAt((leftBound + rightBound - s.length()) / 2 + 1, lowerBound + 2, "PLAYER 1 vs PLAYER 2");
}

void drawScore(int p1, int p2){
    COORD score;
    score.X = leftBound + boardOffset;
    score.Y = lowerBound + 2;
    SetConsoleCursorPosition(hStdOut, score);
    cout << p1 << "      ";
    int d = 0, p = p2; // count digits of p2
    for(d = 0; p >= 10; d++, p/=10);
    score.X = rightBound - boardOffset - d;
    SetConsoleCursorPosition(hStdOut, score);
    cout << p2;
}

int drawPad(int p, int y, int x, int len, string padChar){
    COORD pad;
    int r;
    for(int i = y; i < y + len; i++){
        pad.X = x;
        pad.Y = i;
        r += SetConsoleCursorPosition(hStdOut, pad) != 0 ? 1 : 0;
        cout << padChar;
    }
    return r;
}

int drawBall(int x, int y, string ballChar){
    COORD b;
    b.X = x;
    b.Y = y;
    int r = SetConsoleCursorPosition(hStdOut, b);
    cout << ballChar;
    return r;
}

#endif //_CPP_PONG_LIB_
