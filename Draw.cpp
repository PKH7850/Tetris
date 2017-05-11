#include "Draw.h"

CDraw::CDraw() {
    sx = 40 - Width ;
    sy = 0;

    CursorView(HIDE);
    sideMenu();
}

void CDraw::sideMenu() {
	int x = 5;
	int y = 2;


	SetColor(SKY_BLUE);
	gotoxy(x, y + 1);	printf("   TETRIS_DEMO  ");

	y = 7;
	SetColor(GRAY);
	gotoxy(x, y++);	printf("    ������ȯ");
	gotoxy(x, y++);	printf("       ��");
	gotoxy(x, y++);	printf("���� ��  �� ������");
	gotoxy(x, y++);	printf("       ��");
	gotoxy(x, y++);	printf("      �Ʒ�");
	y += 3;
	gotoxy(x, y++);	printf("SPACE : ��� �Ʒ���");
	gotoxy(x, y++);	printf("P     : �Ͻ�����");
	gotoxy(x, y++);	printf("Esc   : ���� ����");
}

void CDraw::drawBoard(int x, int y, int type, int cType) {
    const int color[] = {SKY_BLUE, BLUE, DARK_YELLOW, YELLOW, GREEN, VIOLET, RED, GRAY, BLACK};
    const char *shape[] = {"  ", "��", "��", "��"}; 

    SetColor(color[cType]);
    gotoxy(x * 2 + sx, y + sy);
    printf("%s", shape[type]);
    SetColor(GRAY);
}

void CDraw::drawStage(int stage) {
	gotoxy((Width + 2) * 2 + sx, 2);	printf("��   �� : %d    ", stage);
}

void CDraw::drawScore(int score) {
	gotoxy((Width + 2) * 2 + sx, 4);	printf("��   �� : %d    ", score);
}

void CDraw::drawNumLine(int line) {
	gotoxy((Width + 2) * 2 + sx, 6);	printf("���� �� : %d    ", line);
}

void CDraw::drawNumBrick(int numBrick) {
	gotoxy((Width + 2) * 2 + sx, 8);	printf("�� �� : %d    ", numBrick);
}

void CDraw::drawTime(int sec) {
    int hh, mm;

    hh = sec / 3600;
    mm = (sec % 3600) / 60;
    sec %= 60;

	SetColor(SKY_BLUE);
	gotoxy((Width + 2) * 2 + sx, 10);
	printf("%02d : %02d : %02d", hh, mm, sec);
	SetColor(GRAY);
}

void CDraw::stageEndMsg(int color) {
    int y = 8;

    SetColor(color);
    gotoxy(3 + sx, y++); puts("                  ");
    gotoxy(3 + sx, y++); puts(" ���� �ܰ�� �̵� ");
    gotoxy(3 + sx, y++); puts("                  ");
    SetColor(GRAY);
}

void CursorView(char show) {
    HANDLE hConsole;
    CONSOLE_CURSOR_INFO ConsoleCursor;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    ConsoleCursor.bVisible = show;
    ConsoleCursor.dwSize = 1;

    SetConsoleCursorInfo(hConsole , &ConsoleCursor);
}

void gotoxy(int x, int y) {	// x, y ��ǥ�� Ŀ�� �̵�
    COORD XY = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), XY);
}

// �ܼ� ������ ����
void SetColor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}


int CDraw::getSX() {
	return sx;
}