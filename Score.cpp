#include "Score.h"

void Score::gotoxy(int x, int y) {
	COORD XY = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), XY);
}

void Score::drawScore(int totalScore) {
//	gotoxy((Width + 2) * 2 + getSX(), 12);	printf("고 득  점 : %d    ", totalScore);
}

bool Score::gameEndMsg(int Yes) {
	char ch;
	int  y = 8;

	gotoxy(3 + getSX(), y++); puts("                  ");
	if (Yes) {
		gotoxy(3 + getSX(), y++); puts(" 게임 클리어 ");
	}
	else {
		gotoxy(3 + getSX(), y++); puts("    GAME OVER     ");
	}
	writeScore(getTotal());
	gotoxy(3 + getSX(), y++); puts("                  ");
	gotoxy(3 + getSX(), y++); puts("  다시 하겠습니까?  y/n  ");
	gotoxy(3 + getSX(), y++); puts("                  ");

	while (1) {
		ch = _getch();
		if (ch == 'y' || ch == 'Y') return true;
		else if (ch == 'n' || ch == 'N') return false;
	}
}

void Score::writeScore(int totscore) {
	os.open("result.txt");
	os << totscore;
}