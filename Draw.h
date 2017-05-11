#ifndef __DRAW_H_
#define __DRAW_H_

#include "console.h"

#define Width  12
#define Height 24
#define BOXSIZE 8

enum {EMPTY, BRICK, WALL, SHADOW};

struct tag_Board {
    int color;
    int type;
};

class CDraw {
private :
    int sx, sy; //Start point of Map

public :
    CDraw();
    ~CDraw() {CursorView(SHOW);}
	int getSX();
    void sideMenu();
    void drawStage(int stage);
    void drawScore(int score);
    void drawNumLine(int line);
    void drawNumBrick(int numBrick);
    void drawTime(int sec);
    void drawBoard(int x, int y, int type, int cType);
    void stageEndMsg(int color);
    bool gameEndMsg(int Yes);
	int setTotScore(int total);
	void writeScore(int totscore);
};

#endif
