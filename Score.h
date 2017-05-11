#ifndef __SCORE_H_
#define __SCORE_H
#include "Data.h"
#include <fstream>
#include <iostream>
using namespace std;

class Score : public CData, public CDraw {
public:
	Score(){}
	~Score(){}
	ofstream os;
	void gotoxy(int x, int y);
	void drawScore(int totalScore);
	bool gameEndMsg(int Yes);
	void writeScore(int totscore);
};

#endif