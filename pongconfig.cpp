#include<Windows.h>

using namespace std;

// ----------------------- CONFIG -----------------------

int frameRate = 20;

int ballStartX = 20;
int ballStartY = 10;
int ballVx = 1;
int ballVy = -1;

int boardOffsetTop = 2;
int boardOffsetLeft = 4;
int boardWidth = 70;
int boardHeight = 20;

int padStartOffset = 7;
int padLen = 6;
int boardOffset = 5;

//----------------------------------------------------------

HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

int upperBound = boardOffsetTop;
int lowerBound = boardOffsetTop + boardHeight;
int leftBound = boardOffsetLeft;
int rightBound = boardOffsetLeft + boardWidth;

int middleX = (leftBound + rightBound) / 2;
int middleY = (lowerBound + upperBound) / 2;

int padY[2] = {padStartOffset + upperBound, padStartOffset + upperBound};

